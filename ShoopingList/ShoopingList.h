#ifndef SHOPPING_LIST_H
#define SHOPPING_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* struct to hold shopping list item information
* Data type allows to combine char (name ), float (price), and pointer (next)
* typedef will be used to make an alias for this data type, alias is (ShoppingList)
* char name[50] for items names, making array of 50 chars for it.
* float price for the prices of items, in floats so we include cents.
* struct shopping_list* next is pointer to the next node in linked list.
* it points to the memory address of the next item in the list.
* it has type struct shopping_list to determine what values can be accessed through it.
* so when we dereference the struct pointer, the memory at that address will be interpreted as struct instance,
* then we can access struct shopping_list members.
*/
typedef struct shopping_list {
    char name[50];
    float price;
    struct shopping_list* next;
} ShoppingList;


/*
Function protoypes for the functions implmented in ShiipingList.c source file.
This is so all source files can access the functions.
For more about each function, check the comments in ShoopingList.c
*/

ShoppingList* createItem(char* name, float price);
void addItem(ShoppingList** listHead, char* name, float price);
void removeItem(ShoppingList** listHead, char* name);
void displayList(ShoppingList* listHead);
void insertAtBeginning(ShoppingList** listHead, char* name, float price);
void popFromBeginning(ShoppingList** listHead);
void insertAtEnd(ShoppingList** listHead, char* name, float price);
void DeleteAtEnd(ShoppingList** listHead);
void insertAfter(ShoppingList** listHead, char* prevName, char* newName, float price);




#endif // !SHOPPINGLIST_H
