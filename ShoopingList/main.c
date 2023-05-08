/*
    Post: "ShopingList"
    URL: https://github.com/DevMajed/ShoopingList/blob/master/ShoopingList/main.c
    Author: Majed Alharbi

    DISCLAIMER
   1. Even though my code is tested and aproved, i'm not responsible for any damage mentally or
      physically or socially that might occer to you due to my implmentation of it.
      Use the code at your own risk.
   2. All the comments that explain how each part of the code works are found in the ShoopingList.c file.
   3. I made this code from scratch as a demonstration of how Linked Lists work in C Langauge.

    LICENSE
    The user is free to use, modify, or reproduce the code and its derivatives.
*/


#define _CRT_SECURE_NO_WARNINGS
#include "ShoopingList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    ShoppingList* listHead = NULL;
    int choice = 0;
    char name[50];
    float price;



    while (1)
    {
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


        switch (choice)
        {
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
