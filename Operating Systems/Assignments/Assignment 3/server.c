#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#define SIZE 1024
#define semaphoreShare1 "/filesharing1"
#define semaphoreShare2 "/filesharing2"

sem_t sem1, sem2;
sem_t *semaphore1, *semaphore2;
key_t mainKey;
int sharedID;
char *val[SIZE];

void *readFile(void *arg) 
{
    key_t readKey = ftok("readfile.txt", 66);
    int sharedID2 = shmget(readKey, SIZE, 0666 | IPC_CREAT);
    char *readPtr = (char *)shmat(sharedID2, NULL, 0);

    FILE *writefile;
    char data[SIZE];
    size_t readFileSize;

    writefile = fopen(val[1], "rb");
    
    fseek(writefile, 0, SEEK_END);
    readFileSize = ftell(writefile);
    rewind(writefile);
    fread(data, 1, readFileSize, writefile);
    
    fclose(writefile);
    
    data[readFileSize] = '\0';
    strncpy(readPtr, data, SIZE);
    shmdt(readPtr);
    sem_post(semaphore2);

    return NULL;
}

void *writeFile(void *arg) 
{
    int len = strlen(val[2]);
    char buffer[len + 1];
    strcpy(buffer, val[2]);
    buffer[len + 1] = '\0';

    FILE *file;
    file = fopen(val[1], "wb");

    size_t writtenToFile = fwrite(buffer, 1, strlen(buffer), file);
    fclose(file);

    return NULL;
}

int main() 
{
    semaphore1 = sem_open(semaphoreShare1, O_CREAT, 0666, 0);
    semaphore2 = sem_open(semaphoreShare2, O_CREAT, 0666, 0);

    sem_init(&sem1, 1, 1);
    sem_init(&sem2, 1, 1);

    mainKey = ftok("argFile.txt", 65);
    sharedID = shmget(mainKey, SIZE, 0666 | IPC_CREAT);
    char *mainPtr = (char *)shmat(sharedID, (void *)0, 0);

    printf("Server Started (Waiting for Client)\n");
    sem_wait(semaphore1);

    char *token = strtok(mainPtr, " ");
    
    int i = 0;
    while (token != NULL) 
    {
        val[i++] = strdup(token);
        token = strtok(NULL, " ");
    }
    val[i] = NULL;

    pthread_t writeThread;
    pthread_t readThread;

    sem_wait(&sem1);
    if (strcmp(val[0], "read") == 0) 
    {
        pthread_create(&writeThread, NULL, readFile, NULL);
        pthread_join(writeThread, NULL);
    } 
    else (strcmp(val[0], "write")==0);
    {
        sem_wait(&sem2);
        pthread_create(&readThread, NULL, writeFile, NULL);
        pthread_join(readThread, NULL);
        sem_post(&sem2);
    }

    
    shmctl(sharedID, IPC_RMID, NULL);
    sem_post(&sem1);

    return 0;
}

