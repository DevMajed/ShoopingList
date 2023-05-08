#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// struct to hold shopping list item information
typedef struct shopping_list {
    char name[50];
    float price;
    struct shopping_list* next;
} ShoppingList;

// function to create a new shopping list item node
ShoppingList* createItem(char* name, float price) {
    ShoppingList* newItem = (ShoppingList*)malloc(sizeof(ShoppingList));
    if (newItem == NULL) {
        printf("Error: Could not allocate memory for new item\n");
        return NULL;
    }
    strncpy_s(newItem->name, name, 50);
    newItem->price = price;
    newItem->next = NULL;
    return newItem;
}

// function to add a new shopping list item to the end of the list
void addItem(ShoppingList** listHead, char* name, float price) {
    ShoppingList* newItem = createItem(name, price);
    if (*listHead == NULL) {
        *listHead = newItem;
    }
    else {
        ShoppingList* item = *listHead;
        while (item->next != NULL) {
            item = item->next;
        }
        item->next = newItem;
    }
}

// function to remove a shopping list item from the list
void removeItem(ShoppingList** listHead, char* name) {
    if (*listHead == NULL) {
        printf("Error: List is empty\n");
        return;
    }
    ShoppingList* item = *listHead;
    ShoppingList* prev = NULL;
    while (item != NULL) {
        if (strcmp(item->name, name) == 0) {
            if (prev == NULL) {
                *listHead = item->next;
            }
            else {
                prev->next = item->next;
            }
            free(item);
            printf("Item removed from list: %s\n", name);
            return;
        }
        prev = item;
        item = item->next;
    }
    printf("Error: Item '%s' not found in list\n", name);
}

// function to display the shopping list
void displayList(ShoppingList* listHead) {
    if (listHead == NULL) {
        printf("Shopping list is empty\n");
        return;
    }
    printf("Shopping list:\n");
    ShoppingList* item = listHead;
    while (item != NULL) {
        printf("- %s: $%.2f\n", item->name, item->price);
        item = item->next;
    }
}


void insertAtBeginning(ShoppingList** listHead, char* name, float price) {
    ShoppingList* newItem = createItem(name, price);
    if (newItem == NULL) {
        printf("Error: Could not allocate memory for new item\n");
        return;
    }
    newItem->next = *listHead;
    *listHead = newItem;
    printf("Item added at the beginning of the list: %s\n", name);
}




ShoppingList* popFromBeginning(ShoppingList** listHead) {
    if (*listHead == NULL) {
        printf("Error: List is empty\n");
        return NULL;
    }
    ShoppingList* removedItem = *listHead;
    *listHead = (*listHead)->next;
    removedItem->next = NULL;
    printf("Item removed from the beginning of the list: %s\n", removedItem->name);
    return removedItem;
}


void insertAtEnd(ShoppingList** listHead, char* name, float price) {
    ShoppingList* newItem = createItem(name, price);
    if (newItem == NULL) {
        printf("Error: Could not allocate memory for new item\n");
        return;
    }
    if (*listHead == NULL) {
        *listHead = newItem;
    }
    else {
        ShoppingList* item = *listHead;
        while (item->next != NULL) {
            item = item->next;
        }
        item->next = newItem;
    }
    printf("Item added at the end of the list: %s\n", name);
}



ShoppingList* DeleteAtEnd(ShoppingList** listHead) {
    if (*listHead == NULL) {
        printf("Error: List is empty\n");
        return NULL;
    }
    ShoppingList* item = *listHead;
    ShoppingList* prev = NULL;
    while (item->next != NULL) {
        prev = item;
        item = item->next;
    }
    if (prev == NULL) {
        *listHead = NULL;
    }
    else {
        prev->next = NULL;
    }
    printf("Item removed from the end of the list: %s\n", item->name);
    return item;
}



void insertAfter(ShoppingList** listHead, char* prevName, char* newName, float price)

{
    if (*listHead == NULL) {
        printf("Error: List is empty\n");
        return;
    }
    ShoppingList* item = *listHead;
    while (item != NULL) {
        if (strcmp(item->name, prevName) == 0) {
            ShoppingList* newItem = createItem(newName, price);
            if (newItem == NULL) {
                printf("Error: Could not allocate memory for new item\n");
                return;
            }
            newItem->next = item->next;
            item->next = newItem;
            printf("Item added to list after %s: %s\n", prevName, newName);
            return;
        }
        item = item->next;
    }
    printf("Error: Item '%s' not found in list\n", prevName);
}




int main() {
    ShoppingList* listHead = NULL;
    int choice = 0;
    char name[50];
    float price;



    while (1) {
        printf("\nEnter a choice:\n");
        printf("1. Add item to list\n");
        printf("2. Remove item from list\n");
        printf("3. Display shopping list\n");
        printf("4. Insert item at the beginning of the list\n");
        printf("5. Remove item from the beginning of the list\n");
        printf("6. Insert item at the end of the list\n");
        printf("7. Remove item from the end of the list\n");
        printf("8. Insert item after a specific item in the list\n");
        printf("9. Exit\n");
        scanf("%d", &choice);


        switch (choice) {
        case 1:
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter item price: ");
            scanf("%f", &price);
            addItem(&listHead, name, price);
            break;
        case 2:
            printf("Enter item name to remove: ");
            scanf("%s", name);
            removeItem(&listHead, name);
            break;
        case 3:
            displayList(listHead);
            break;
        case 4:
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter item price: ");
            scanf("%f", &price);
            insertAtBeginning(&listHead, name, price);
            break;
        case 5:
            popFromBeginning(&listHead);
            break;
        case 6:
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter item price: ");
            scanf("%f", &price);
            insertAtEnd(&listHead, name, price);
            break;
        case 7:
            DeleteAtEnd(&listHead);
            break;
        case 8:
            printf("Enter the name of the item to insert after: ");
            scanf("%s", name);
            printf("Enter the name of the new item: ");
            char newName[50];
            scanf("%s", newName);
            printf("Enter the price of the new item: ");
            scanf("%f", &price);
            insertAfter(&listHead, name, newName, price);
            break;
        case 9:
            printf("Exiting\n");
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
