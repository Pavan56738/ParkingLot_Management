#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CAPACITY 5 

typedef struct Vehicle {
    char plate[15];
} Vehicle;
typedef struct Queue {
    int front, rear, size;
    Vehicle vehicles[MAX_CAPACITY];
} Queue;
void initializeQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}
int isFull(Queue *q) {
    return q->size == MAX_CAPACITY;
}
int isEmpty(Queue *q) {
    return q->size == 0;
}
void parkVehicle(Queue *q, char *plate) {
    if (isFull(q)) {
        printf("Parking lot is full! Cannot park vehicle %s.\n", plate);
        return;
    }
    q->rear = (q->rear + 1) % MAX_CAPACITY;
    strcpy(q->vehicles[q->rear].plate, plate);
    q->size++;
    printf("Vehicle %s parked successfully.\n", plate);
}
void removeVehicle(Queue *q) {
    if (isEmpty(q)) {
        printf("Parking lot is empty! No vehicles to remove.\n");
        return;
    }
    printf("Vehicle %s is leaving the parking lot.\n", q->vehicles[q->front].plate);
    q->front = (q->front + 1) % MAX_CAPACITY;
    q->size--;
}
void displayParkingLot(Queue *q) {
    if (isEmpty(q)) {
        printf("Parking lot is empty!\n");
        return;
    }
    printf("Current vehicles in the parking lot:\n");
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % MAX_CAPACITY;
        printf("%d. %s\n", i + 1, q->vehicles[index].plate);
    }
}
int main() {
    Queue parkingLot;
    initializeQueue(&parkingLot);
    int choice;
    char plate[15];
    do {
        printf("\nParking Lot Management System\n");
        printf("1. Park Vehicle\n");
        printf("2. Remove Vehicle\n");
        printf("3. Display Parking Lot\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter vehicle plate number: ");
                scanf("%s", plate);
                parkVehicle(&parkingLot, plate);
                break;
            case 2:
                removeVehicle(&parkingLot);
                break;
            case 3:
                displayParkingLot(&parkingLot);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
    return 0; }
