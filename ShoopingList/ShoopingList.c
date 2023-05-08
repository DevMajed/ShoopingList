#define _CRT_SECURE_NO_WARNINGS
#include "ShoopingList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*

This is a function to creat new ShoppingList instances to the linked list,
which means making new items ( nodes ) in the shooping list.

* 1st: Allocating memory to a new item and create a pinter ( newItem ) to the first Bytes of the memory block
* 2nd: Size of memory block will be the sum of ShppingList struct members char name[50] + folat price + *next
* 3nd: new instance of ShoppingList struct created
* 4rd: using strncopy to copy new item name ( newItem ) to new new instance 
* instance of ShoppingList, which is the new ShoppingList item.
* 5th: Assigning the new price ( newPrice ) to the new ShoppingList item.
* 6th: Setting the ( next ) pointer of the new ShoppingList item to (Null) because
* 7th: this item will be the last node, last in the list, not pointing to other item.

*/ 

ShoppingList* createItem(char* newName, float newPrice)
{
    ShoppingList* newItem = (ShoppingList*)malloc(sizeof(ShoppingList));
    if (newItem == NULL) {
        printf("Error: Could not allocate memory for new item\n");
        return NULL;
    }
    strncpy(newItem->name, newName, 50);
    newItem->price = newPrice;
    newItem->next = NULL;
    return newItem;
}

/*

This is a function adds a new item to the linked list,
it adds a new shopping list item to the ( End ) of the list.

* 0th: user inputs data to addItem(&listHead, name, price); and &listHead initially Null
* 1st: creating new ShoppingList item by calling createItem function and pass user inputs.
* 2nd: the member ( next ) of the new ShoppingList instance is set to Null, as to say no items next.
* 3nd: The pointer created by createItem and assigned to the pointer ( itemAdded )
* 4rd: Initally listHead is Null, so the first if condition met, itemAdded is the head node.
* 5th: The second time ( add Item ) called by the user, *listHead will point to the last item we added.
* 6th: the function goes to ( else ) and we use currentItem to iterate over the linked list to find the last node.
* 7th: once it find Null, and (next) of the new ShoppingList instance assigned to itemAdded to make it the last in the list.

*/

void addItem(ShoppingList** listHead, char* addName, float addPrice)
 {
    ShoppingList* itemAdded = createItem(addName, addPrice);
    if (*listHead == NULL) {
        *listHead = itemAdded;
    }
    else
    {
        ShoppingList* currentItem = *listHead;
        while (currentItem->next != NULL)
        {
            currentItem = currentItem->next;
        }
        currentItem->next = itemAdded;
    }
}

/*

This is a function to remove a shiiping list item from the list,
it uses two pointers, one to kepep track of the current item, and another to the item previous  to it.

* 0th: user inputs data to removeItem(&listHead, name);
* 1st: Checks if listHead is Null it shows error.
* 2nd: Making new pointer itemRemoved, initially assigned to listHead listHead to it.
* 3rd: Making new pointer prev that will keep track of previous node in the linked list while iterating, iniitially assigned to NULL.
* 4th: iterate over the list, checking for matched between the current item and the item that the user want it to be removed.
* 5th: if the match occred in strcmp, check condition#1: if prev = Null, meaning the item to be removed is the only one in the list.
* 6th: condition #2, if there is node before the one to be removed, we will point the previous item (next instance) to the item after the removed one.
* 7th: free the memory allocated to the instance of ShoopingList that was assigned to the removed item.

*/

void removeItem(ShoppingList** listHead, char* removeName)
{
    if (*listHead == NULL) {
        printf("Error: List is empty\n");
        return;
    }
    ShoppingList* itemRemoved = *listHead;
    ShoppingList* prev = NULL;
    while (itemRemoved != NULL)
    {
        if (strcmp(itemRemoved->name, removeName) == 0)
        {
            if (prev == NULL) {
                *listHead = itemRemoved->next;
            }
            else {
                prev->next = itemRemoved->next;
            }
            free(itemRemoved);
            printf("Item removed from list: %s\n", removeName);
            return;
        }
        prev = itemRemoved;
        itemRemoved = itemRemoved->next;
    }
    printf("Error: Item '%s' not found in list\n", removeName);
}

/*

This function just to display the shopping list

* 0th: user inputs choose displayList(listHead) and from main, the current listHead will be passed.
* 1st: checks if the head is NULL, it means we still have no items at all.
* 2nd: makng a new pointer that will iterate over all other items to be displaied, it gets assigned to head of the linked list.
* 3rd: iterating over the linked list, and every time each item's name and price get displaied, until we reach NULL.

*/

void displayList(ShoppingList* listHead)
{
    if (listHead == NULL) {
        printf("Shopping list is empty\n");
        return;
    }
    printf("Shopping list:\n");
    ShoppingList* itemDisplaied = listHead;
    while (itemDisplaied != NULL) {
        printf("- %s: $%.2f\n", itemDisplaied->name, itemDisplaied->price);
        itemDisplaied = itemDisplaied->next;
    }
}

/*

This function is (pushing to the list) it will add an item to the beginning of the linked list.

* 0th: like others, user inputs data to insertAtBeginning(&listHead, name, price);
* 1st: listHead is initially NULL, otherwise it will take the current value from main.c
* 2nd: Makiing new instance of ShoppingList by using createItem, and passing name and price to it.
* 3rs: itemInserted->next = *listHead; making the next item after itemInserted is the previous listHead.
* 4th: *listHead = itemInserted; making the itemInserted is the new listHead.

*/
void insertAtBeginning(ShoppingList** listHead, char* name, float price) {
    ShoppingList* itemInserted = createItem(name, price);
    if (itemInserted == NULL) {
        printf("Error: Could not allocate memory for new item\n");
        return;
    }
    itemInserted->next = *listHead;
    *listHead = itemInserted;
    printf("Item added at the beginning of the list: %s\n", name);
}

/*

This function is (popping from the list) it will remove the first item in the list.

* 0th: user inputs choose popFromBeginning(listHead) and from main, the current listHead will be passed.
* 1st: checking if the list head is null, means we have an empty list
* 2nd: making a new pointer called ItemPopped, and dereferencing listHead pointer to get the value of the pointer it is pointing to, which is the the address of first item in the list.
* 3rd: updating the listHead pointer to point to the next item in the list after the current head.
* 4th: making ItemPopped's next item is NULL because it will be deleted.
* 5th: freeing the memory ItemPopped to avoid memory leaks

*/

void popFromBeginning(ShoppingList** listHead)
{
    if (*listHead == NULL)
    {
        printf("Error: List is empty\n");
        return NULL;
    }
    ShoppingList* itemPopped = *listHead;
    *listHead = (*listHead)->next;
    itemPopped->next = NULL;
    printf("Item removed from the beginning of the list: %s\n", itemPopped->name);
    free(itemPopped);
}

/*

This function adds an item to the end of the linked list.

* 0th: user inputs choose insertAtEnd(&listHead, name, price);
* 1st: listHead is initially NULL, otherwise it will take the current value from main.c
* 2nd: Makiing new instance of ShoppingList ( nammed itemEndInserted ) by using createItem, and passing name and price to it.
* 3rd: Checking, if listHead = NULL, making the listHead NULL it adds the item right away.
* 4th: it makes pointer ( TheCurrentItem ) to iterate over the linked list
* 5th: once it find the last item, it points its (next) pointer to the new item named ( itemEndInserted )

*/

void insertAtEnd(ShoppingList** listHead, char* name, float price)

{
    ShoppingList* itemEndInserted = createItem(name, price);
    if (itemEndInserted == NULL) {
        printf("Error: Could not allocate memory for new item\n");
        return;
    }
    if (*listHead == NULL) {
        *listHead = itemEndInserted;
    }
    else {
        ShoppingList* TheCurrentItem = *listHead;
        while (TheCurrentItem->next != NULL) {
            TheCurrentItem = TheCurrentItem->next;
        }
        TheCurrentItem->next = itemEndInserted;
    }
    printf("Item added at the end of the list: %s\n", name);
}

/*

This function Delete an item to the end of the linked list.

* 0th: user inputs choose DeleteAtEnd(&listHead);
* 1st: if listHead is  NULL, it gives error, cause the list is empty.
* 2nd: making new pointers: itemEndDeleted for the deleted node, and prev to keep track of the previuos node.
* 3rd: iterate itemEndDeleted until we find the last item, and each time it assigns the item before it to prev.
* 4th: after the last item found, the function exsits the while loop, and checks of prev = NULL means the list have 1 item, which we deleted.
* 5th: if there are other items left in the list, the last one of them will have its (next) pointer pointing to NULL.

*/



void DeleteAtEnd(ShoppingList** listHead)
{
    if (*listHead == NULL) {
        printf("Error: List is empty\n");
        return NULL;
    }
    ShoppingList* itemEndDeleted = *listHead;
    ShoppingList* prev = NULL;
    while (itemEndDeleted->next != NULL)
    {
        prev = itemEndDeleted;
        itemEndDeleted = itemEndDeleted->next;
    }
    if (prev == NULL) {
        *listHead = NULL;
    }
    else {
        prev->next = NULL;
    }
    printf("Item removed from the end of the list: %s\n", itemEndDeleted->name);
  
}

/*

This is a function adds a new item after a spevefic item in the  linked list.

* 0th: user inputs data to insertAfter(&listHead, prevName, newName, price);
* 1st: assigning prevItem to list head initially, to start iterating.
* 2nd: iterating to the end of the list to find the previous item the user passed
* 3rd: once the previous item found and strcmp condition met, the new item will be created.
* 4th: createItem function will be usede to create new instance of ShoppingList called newItem.
* 5th: give the previous item's ( next ) pointer to the newItem, so it points where previous was pointing.
* 6th: make the previous itme's ( next ) pointer points to newItem that we made.

*/
void insertAfter(ShoppingList** listHead, char* prevName, char* newName, float price)

{
    if (*listHead == NULL) {
        printf("Error: List is empty\n");
        return;
    }
    ShoppingList* prevItem = *listHead;
    while (prevItem != NULL)
    {
        if (strcmp(prevItem->name, prevName) == 0)
        {
            ShoppingList* newItem = createItem(newName, price);
            if (newItem == NULL) {
                printf("Error: Could not allocate memory for new item\n");
                return;
            }
            newItem->next = prevItem->next;
            prevItem->next = newItem;
            printf("Item added to list after %s: %s\n", prevName, newName);
            return;
        }
        prevItem = prevItem->next;
    }
    printf("Error: Item '%s' not found in list\n", prevName);
}