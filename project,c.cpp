#include <stdio.h>

#define MAX_SIZE 100

struct InventoryItem {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct CircularQueue {
    struct InventoryItem items[MAX_SIZE];
    int front, rear;
};

// Function to initialize the circular queue.
void initializeQueue(struct CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty.
int isEmpty(struct CircularQueue* queue) {
    return (queue->front == -1);
}

// Function to check if the queue is full.
int isFull(struct CircularQueue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to enqueue an item.
void enqueue(struct CircularQueue* queue, struct InventoryItem item) {
    // Check for queue overflow.
    if (isFull(queue)) {
        printf("Queue is full. Cannot add more items.\n");
        return;
    }

    // Enqueue the item.
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = item;
}

// Function to dequeue an item.
struct InventoryItem dequeue(struct CircularQueue* queue) {
    struct InventoryItem emptyItem = {0, "", 0, 0.0}; // Empty item
    // Check for queue underflow.
    if (isEmpty(queue)) {
        printf("Queue is empty. No items to remove.\n");
        return emptyItem;
    }

    struct InventoryItem item = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return item;
}

// Function to add an item to the inventory.
void addItemToInventory(struct CircularQueue* queue) {
    struct InventoryItem newItem;
    
    printf("Enter Item ID: ");
    scanf("%d", &newItem.id);
    
    printf("Enter Item Name: ");
    scanf("%s", newItem.name);
    
    printf("Enter Item Quantity: ");
    scanf("%d", &newItem.quantity);
    
    printf("Enter Item Price: ");
    scanf("%f", &newItem.price);

    // Enqueue the item to the inventory.
    enqueue(queue, newItem);
    printf("Item added to the inventory.\n");
}


// Function to display the current inventory.
void displayInventory(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Inventory is empty.\n");
        return;
    }

    int i = queue->front;
    printf("Current Inventory:\n");
    do {
        struct InventoryItem item = queue->items[i];
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", item.id, item.name, item.quantity, item.price);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);
}
// Function to sell an item from the inventory.
void sellItemFromInventory(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Inventory is empty. Cannot sell items.\n");
        return;
    }

    int itemId;
    printf("Enter the ID of the item to sell: ");
    scanf("%d", &itemId);

    // Search for the item with the given ID.
    int i = queue->front;
    while (i != (queue->rear + 1) % MAX_SIZE) {
        if (queue->items[i].id == itemId) {
            // Item found, decrement quantity.
            if (queue->items[i].quantity > 0) {
                queue->items[i].quantity--;
                printf("Item sold.\n");
                return;
            } else {
                printf("Item is out of stock.\n");
                return;
            }
        }
        i = (i + 1) % MAX_SIZE;
    }

    // Item with the given ID not found.
    printf("Item with ID %d not found in the inventory.\n", itemId);
}


int main() {
    struct CircularQueue inventoryQueue;
    initializeQueue(&inventoryQueue);

    int choice;
    while (1) {
        printf("\nInventory Management System:\n");
        printf("1. Add an item\n");
        printf("2. Sell an item\n");
        printf("3. Display current inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItemToInventory(&inventoryQueue);
                break;
            case 2:
                sellItemFromInventory(&inventoryQueue);
                break;
            case 3:
                displayInventory(&inventoryQueue);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

