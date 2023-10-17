#include <stdio.h>
#include <stdlib.h>

struct InventoryItem {
    int id;
    char name[50];
    int quantity;
    float price;
    struct InventoryItem* next;
};

struct InventoryList {
    struct InventoryItem* head;
};

// Function to initialize the inventory list.
void initializeList(struct InventoryList* list) {
    list->head = NULL;
}

// Function to check if the list is empty.
int isEmpty(struct InventoryList* list) {
    return list->head == NULL;
}

// Function to add an item to the inventory.
void addItemToInventory(struct InventoryList* list) {
    struct InventoryItem* newItem = (struct InventoryItem*)malloc(sizeof(struct InventoryItem));

    if (newItem == NULL) {
        printf("Memory allocation failed. Cannot add more items.\n");
        return;
    }

    printf("Enter Item ID: ");
    scanf("%d", &newItem->id);
    
    printf("Enter Item Name: ");
    scanf("%s", newItem->name);
    
    printf("Enter Item Quantity: ");
    scanf("%d", &newItem->quantity);
    
    printf("Enter Item Price: ");
    scanf("%f", &newItem->price);

    newItem->next = NULL;

    if (isEmpty(list)) {
        list->head = newItem;
    } else {
        struct InventoryItem* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newItem;
    }

    printf("Item added to the inventory.\n");
}

// Function to display the current inventory.
void displayInventory(struct InventoryList* list) {
    if (isEmpty(list)) {
        printf("Inventory is empty.\n");
        return;
    }

    struct InventoryItem* current = list->head;
    printf("Current Inventory:\n");

    while (current != NULL) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", current->id, current->name, current->quantity, current->price);
        current = current->next;
    }
}

// Function to sell an item from the inventory.
void sellItemFromInventory(struct InventoryList* list) {
    if (isEmpty(list)) {
        printf("Inventory is empty. Cannot sell items.\n");
        return;
    }

    int itemId;
    printf("Enter the ID of the item to sell: ");
    scanf("%d", &itemId);

    struct InventoryItem* current = list->head;
    struct InventoryItem* prev = NULL;

    while (current != NULL) {
        if (current->id == itemId) {
            // Item found, decrement quantity.
            if (current->quantity > 0) {
                current->quantity--;
                printf("Item sold.\n");
                if (current->quantity == 0) {
                    // Remove the item if it's out of stock.
                    if (prev == NULL) {
                        list->head = current->next;
                    } else {
                        prev->next = current->next;
                    }
                    free(current);
                }
                return;
            } else {
                printf("Item is out of stock.\n");
                return;
            }
        }
        prev = current;
        current = current->next;
    }

    // Item with the given ID not found.
    printf("Item with ID %d not found in the inventory.\n", itemId);
}

int main() {
    struct InventoryList inventoryList;
    initializeList(&inventoryList);

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
                addItemToInventory(&inventoryList);
                break;
            case 2:
                sellItemFromInventory(&inventoryList);
                break;
            case 3:
                displayInventory(&inventoryList);
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

