#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MATRIX_SIZE 100
#define THREAD_COUNT 5

int matrixA[MATRIX_SIZE][MATRIX_SIZE];
int matrixB[MATRIX_SIZE][MATRIX_SIZE];
int resultMatrix[MATRIX_SIZE][MATRIX_SIZE];

// Shared memory structure to store execution times
typedef struct {
    double thread_execution_time[THREAD_COUNT];
} SharedMemory;

SharedMemory *shared_memory;

// Matrix multiplication function for a specific row
void* multiplyRow(void* arg) {
    int row = *((int*)arg);
    struct timeval start_time, end_time;
    
    gettimeofday(&start_time, NULL);

    for (int col = 0; col < MATRIX_SIZE; col++) {
        resultMatrix[row][col] = 0;
        for (int k = 0; k < MATRIX_SIZE; k++) {
            resultMatrix[row][col] += matrixA[row][k] * matrixB[k][col];
        }
    }

    gettimeofday(&end_time, NULL);
    
    // Calculate execution time for the thread
    double execution_time = (end_time.tv_sec - start_time.tv_sec) * 1000000.0 + (end_time.tv_usec - start_time.tv_usec);

    // Store execution time in shared memory
    shared_memory->thread_execution_time[row] = execution_time;

    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));

    // Initialize matrices with random values
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrixA[i][j] = rand() % 10 + 1;
            matrixB[i][j] = rand() % 10 + 1;
        }
    }

    // Create shared memory segment
    key_t key = ftok("matrix_multiplication", 65);
    int shmid = shmget(key, sizeof(SharedMemory), 0666 | IPC_CREAT);
    shared_memory = (SharedMemory*)shmat(shmid, (void*)0, 0);

    // Create pthreads
    pthread_t threads[THREAD_COUNT];
    int thread_args[THREAD_COUNT];

    // Initialize thread arguments and create threads
    for (int i = 0; i < THREAD_COUNT; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, multiplyRow, (void*)&thread_args[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    // Detach shared memory
    shmdt(shared_memory);

    // Display the result matrix
    printf("Result Matrix:\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }

    // Calculate and display total execution time
    double total_execution_time = 0.0;
    for (int i = 0; i < THREAD_COUNT; i++) {
        total_execution_time += shared_memory->thread_execution_time[i];
    }
    printf("Total Execution Time: %.2f microseconds\n", total_execution_time);

    // Delete shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

