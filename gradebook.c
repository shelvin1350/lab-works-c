#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100
int j;

// Define the structure for a student record
struct StudentRecord {
    char name[50];
    float grade;
};

// Define the queue structure using an array
struct Queue {
    struct StudentRecord data[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (!queue) {
        perror("Queue creation failed");
        exit(1);
    }
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->size == MAX_QUEUE_SIZE);
}

// Function to enqueue a student record
void enqueue(struct Queue* queue, struct StudentRecord student) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot add more records.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->data[queue->rear] = student;
    queue->size++;
}

// Function to dequeue a student record
void dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->size--;
}

// Function to calculate and display average grade
void calculateAverage(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("No students in the gradebook.\n");
        return;
    }

    float sum = 0.0;
    int count = 0;
    int i = queue->front;
    for (j = 0; j < queue->size; j++) {
        sum += queue->data[i].grade;
        count++;
        i = (i + 1) % MAX_QUEUE_SIZE;
    }

    printf("Average grade: %.2f\n", sum / count);
}

// Function to display all student records
void displayRecords(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("No students in the gradebook.\n");
        return;
    }

    printf("Student Gradebook:\n");
    int i = queue->front;
    for (j = 0; j < queue->size; j++) {
        printf("Name: %s, Grade: %.2f\n", queue->data[i].name, queue->data[i].grade);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
}

int main() {
    struct Queue* gradebook = createQueue();
    int choice;

    do {
        printf("\nStudent Gradebook Menu:\n");
        printf("1. Add Student Record\n");
        printf("2. Remove Student Record\n");
        printf("3. Calculate Average Grade\n");
        printf("4. Display All Records\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct StudentRecord student;
                printf("Enter student name: ");
                scanf("%s", student.name);
                printf("Enter student grade: ");
                scanf("%f", &student.grade);
                enqueue(gradebook, student);
                printf("Student record added successfully.\n");
                break;
            }
            case 2: {
                dequeue(gradebook);
                printf("Student record removed.\n");
                break;
            }
            case 3: {
                calculateAverage(gradebook);
                break;
            }
            case 4: {
                displayRecords(gradebook);
                break;
            }
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    // Free memory and exit
    free(gradebook);

    return 0;
}

