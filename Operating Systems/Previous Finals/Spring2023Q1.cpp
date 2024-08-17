#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Define constants
#define MAX_CONCURRENT_ORDERS 3
#define MAX_CUSTOMERS 3

// Define global variables
sem_t orderPlacementSemaphore;
sem_t orderProcessingSemaphore;
sem_t orderDeliverySemaphore;

// Structure to represent an order
typedef struct {
    int customerId;
    int tokenNumber;
} Order;

// Function prototypes
void* placeOrder(void* arg);
void* processOrder(void* arg);
void* deliverOrder(void* arg);

int main() {
    // Initialize semaphores
    sem_init(&orderPlacementSemaphore, 0, MAX_CONCURRENT_ORDERS);
    sem_init(&orderProcessingSemaphore, 0, 0);  // Initialize to 0 to start with order placement
    sem_init(&orderDeliverySemaphore, 0, 0);  // Initialize to 0 to start with order placement

    // Create threads for order placement, processing, and delivery
    pthread_t placeOrderTh[MAX_CUSTOMERS], processOrderTh[MAX_CUSTOMERS], deliverOrderTh[MAX_CUSTOMERS];

    // Create threads for order placement
    for (int i = 0; i < MAX_CUSTOMERS; ++i) {
        pthread_create(&placeOrderTh[i], NULL, placeOrder, NULL);
    }

    // Create threads for order processing
    for (int i = 0; i < MAX_CUSTOMERS; ++i) {
        pthread_create(&processOrderTh[i], NULL, processOrder, NULL);
    }

    // Create threads for order delivery
    for (int i = 0; i < MAX_CUSTOMERS; ++i) {
        pthread_create(&deliverOrderTh[i], NULL, deliverOrder, NULL);
    }

    // Wait for all threads to finish
    for (int i = 0; i < MAX_CUSTOMERS; ++i) {
        pthread_join(placeOrderTh[i], NULL);
        pthread_join(processOrderTh[i], NULL);
        pthread_join(deliverOrderTh[i], NULL);
    }

    // Destroy semaphores
    sem_destroy(&orderPlacementSemaphore);
    sem_destroy(&orderProcessingSemaphore);
    sem_destroy(&orderDeliverySemaphore);

    return 0;
}

void* placeOrder(void* arg) {
    // Implement order placing logic here
    sem_wait(&orderPlacementSemaphore);

    // Simulating assigning a unique token number
    static int tokenCounter = 1;
    Order order;
    order.customerId = tokenCounter;
    order.tokenNumber = tokenCounter++;

    // Display customer ID and assigned token number
    printf("Customer %d placed an order. Token Number: %d\n", order.customerId, order.tokenNumber);

    sem_post(&orderProcessingSemaphore);

    pthread_exit(NULL);
}

void* processOrder(void* arg) {
    // Implement order processing logic here
    sem_wait(&orderProcessingSemaphore);

    // Display the token number when an order starts processing
    printf("Order with Token Number %d is being processed.\n", MAX_CUSTOMERS);

    sem_post(&orderDeliverySemaphore);

    pthread_exit(NULL);
}

void* deliverOrder(void* arg) {
    // Implement order delivery logic here
    sem_wait(&orderDeliverySemaphore);

    // Display the token number and customer ID when an order is being delivered
    printf("Order with Token Number %d is being delivered to Customer %d.\n", MAX_CUSTOMERS, MAX_CUSTOMERS);

    sem_post(&orderPlacementSemaphore);

    pthread_exit(NULL);
}

