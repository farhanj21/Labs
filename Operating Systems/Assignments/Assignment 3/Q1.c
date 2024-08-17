#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore1, semaphore2, semaphore3;

typedef struct 
{
    int* arr;
    int max, top;
} Stack;

void initializeStack(Stack* stack, int size) 
{
    stack->arr = (int*)malloc(size * sizeof(int));
    stack->max = size;
    stack->top = 0;
}

void push(Stack* stack, int x) 
{
    sem_wait(&semaphore3);
    
    if (stack->top >= stack->max) 
    {
        sem_post(&semaphore3);
        sem_wait(&semaphore1);
    }
    
    stack->arr[stack->top] = x;
    
    ++stack->top;
    
    sem_post(&semaphore2);
    sem_post(&semaphore3);
}

int pop(Stack* stack) 
{
    sem_wait(&semaphore3);

    if (stack->top == 0) 
    {
        sem_post(&semaphore3);
        sem_wait(&semaphore2);
    }
    
    --stack->top;
    
    int temp = stack->arr[stack->top];
    sem_post(&semaphore1);
    sem_post(&semaphore3);
    
    return temp;
}

void* pushThread(void* arg) 
{
    Stack* stack = (Stack*)arg;

    for (int i = 0; i < stack->max; ++i)
     {
        sem_wait(&semaphore1); //wait for signal from main until whole stack is set
        push(stack, stack->arr[i]);

    }
    return NULL;
}

void* popThread(void* arg) 
{
    Stack* stack = (Stack*)arg;
 
    for (int i = 0; i < stack->max; ++i) 
    {
        int num = pop(stack);
        printf("Popped From Stack: %d\n", num);
 
    }
    return NULL;
}

int main() 
{
    sem_init(&semaphore1, 0, 0);
    sem_init(&semaphore2, 0, 0);
    sem_init(&semaphore3, 0, 1);

    int size;
    
    printf("Enter Size of Stack: ");
    scanf("%d", &size);

    Stack s;
    initializeStack(&s, size);

    for (int i = 0; i < size; ++i) {
        printf("Enter value to push: ");
        scanf("%d", &s.arr[i]);
        sem_post(&semaphore1);  //signal pushThread to push into stack
    }

    pthread_t pushThreadID, popThreadID;
    pthread_create(&pushThreadID, NULL, pushThread, &s);
    pthread_create(&popThreadID, NULL, popThread, &s);
    pthread_join(pushThreadID, NULL);
    pthread_join(popThreadID, NULL);

    return 0;
}

