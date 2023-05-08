# ShoopingList

This Code  implements a shopping list using a linked list data structure in C (not C++)   

The shopping list consists of items, each of which has a name and a price.  
The program defines a struct called shopping_list which has fields for the name, price, and a pointer to the next item in the list.  
The program provides several functions to manipulate the list:

1. createItem:  
This function takes a name and a price and returns a new ShoppingList item with those values.  
If memory allocation fails, it prints an error message and returns NULL.

2. addItem:
This function takes a pointer to the head of the list, a name, and a price,  
and adds a new item with those values to the end of the list.

3. removeItem:
This function takes a pointer to the head of the list and a name,  
and removes the item with that name from the list. If the item is not found, it prints an error message.

4. displayList:
This function takes a pointer to the head of the list and displays  
the contents of the list, including the name and price of each item.

5. insertAtBeginning:  
This function takes a pointer to the head of the list, a name,  
and a price, and adds a new item with those values to the beginning of the list.

6. popFromBeginning:  
This function takes a pointer to the head of the list  
and removes the first item in the list. If the list is empty, it prints an error message and returns NULL.

7. insertAtEnd:  
This function takes a pointer to the head of the list,  
a name, and a price, and adds a new item with those values to the end of the list.

8. DeleteAtEnd:  
This function takes a pointer to the head of the list and removes the last item  
in the list. If the list is empty, it prints an error message and returns NULL.

9. insertAfter:  
This function takes a pointer to the head of the list,  
the name of an existing item in the list, a new name, and a price.  
It adds a new item with the given name and price after the item with the given existing name.  
If the existing item is not found, it prints an error message.  


In the main function of the program, the user is prompted to enter commands to manipulate the list.  
These commands include  
"add", "remove", "display", "insert at beginning", "pop from beginning",  
"insert at end", "delete from end", and "insert after".   

The user can enter these commands along with the necessary arguments (item name and price)  
to perform the corresponding operation on the list.  
The program continues to prompt the user for input until the user enters the command "quit",   
at which point the program exits.  
