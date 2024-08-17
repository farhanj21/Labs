#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int X1, Y1, Z1, W1, S1, S2;
int X, Y, W, Z;

sem_t s1, s2;

void *Thread1(void *arg) 
{
   
    printf("Enter values for X and Y: ");
    scanf("%d %d", &X, &Y);

    sem_wait(&s1); //Wait for s2 to finish
    
    X1 = Z + 2;
    
    sem_post(&s2);
    sem_wait(&s1);
    
    Y1 = Z1 * 5;
    S1 = X1 + Y1;
    
    printf("Thread T1: x = %d\n", S1);

    sem_post(&s2); //signal s2 to proceed
    return NULL;
}

void *Thread2(void *arg) {

    printf("Enter values for W and Z: ");
    scanf("%d %d", &W, &Z);
    
    sem_post(&s1);
    sem_wait(&s2);
    
    Z1 = X1 * 2;
    
    sem_post(&s1);
    sem_wait(&s2);
    
    W1 = Y1 + 5;
    S2 = Z1 + W1;

    printf("Thread T2: x = %d\n", S2);

    sem_post(&s2); 
    return NULL;
}

int main() {
    sem_init(&s1, 0, 0);
    sem_init(&s2, 0, 0);

    pthread_t t1, t2;

    pthread_create(&t1, NULL, Thread1, NULL);
    pthread_create(&t2, NULL, Thread2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&s1);
    sem_destroy(&s2);

    return 0;
}


