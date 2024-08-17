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

int main() {
    char in[SIZE];
    char cmd[SIZE];
    char FName[SIZE];
    char data[SIZE];
    
    sem_t sem1;
    sem_init(&sem1, 0, 1);
    sem_t *semaphore1 = sem_open(semaphoreShare1, 0);
    sem_t *semaphore2 = sem_open(semaphoreShare2, 0);

    while (1) {
        printf("Enter command ('read filename.txt' or 'write filename.txt data' or 'exit'):\n");
        fgets(in, SIZE, stdin);
        in[strcspn(in, "\n")] = 0;

        if (sscanf(in, "%s %s %[^\n]", cmd, FName, data) < 2) {
            if (strcmp(in, "exit") == 0) {
                break;
            }
            printf("Invalid command. Please use the correct format.\n");
            continue;
        }

        if (strcmp(cmd, "read") == 0) {
            sem_wait(&sem1);

            char buffer[SIZE];
            snprintf(buffer, SIZE, "%s %s", cmd, FName);

            key_t key = ftok("readFile.txt", 65); 
            int sharedID = shmget(key, SIZE, 0666 | IPC_CREAT);
            char *ptr = (char*) shmat(sharedID, (void*)0, 0);
            strncpy(ptr, buffer, SIZE);
            sem_post(semaphore1);

            sem_wait(semaphore2);

            key_t sharedKey = ftok("readFile.txt", 66);
            int sharedID2 = shmget(sharedKey, SIZE, 0666 | IPC_CREAT);
            char *ptr2 = (char *)shmat(sharedID2, (void *)0, 0);
            printf("File Data: %s\n", ptr2);

            sem_post(&sem1);
        } 
        else if (strcmp(cmd, "write") == 0) {
            sem_wait(&sem1);

            char buffer[SIZE];
            snprintf(buffer, SIZE, "%s %s %s", cmd, FName, data);

            key_t writekey = ftok("writeFile.txt", 65); 
            int sharedID = shmget(writekey, SIZE, 0666 | IPC_CREAT);
            char *writePtr = (char*) shmat(sharedID, (void*)0, 0);
            strncpy(writePtr, buffer, SIZE);
            sem_post(semaphore1);

            sem_wait(semaphore2);
            sem_post(&sem1);
        } else {
            printf("Unknown command.\n");
        }
    }

    sem_destroy(&sem1);
    sem_close(semaphore1);
    sem_close(semaphore2);
    return 0;
}

