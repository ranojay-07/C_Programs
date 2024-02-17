/*This C code defines a linked list data structure and includes functions to create and display the 
elements of the linked list. The structure Node represents each node in the linked list, containing an 
integer data field and a pointer to the next node. The create function initializes the linked list by 
dynamically allocating memory for each node and linking them together based on an input array. The 
display function traverses the linked list and prints the data of each node. In the main function, 
an array is initialized, a linked list is created using the array elements, and then the elements of the 
linked list are displayed. Overall, this code demonstrates the basic operations of creating and displaying 
a linked list in C.*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data ;
    struct Node *next ;
} *first = NULL ;

void create ( int A[] , int n )
{
    struct Node *t , *last ;
    first = ( struct Node * ) malloc ( sizeof ( struct Node ) ) ;  // Allocate memory for the first node
    first -> data = A [ 0 ] ;  // Assign data to the first node
    first -> next = NULL ;  // Initialize the next pointer of the first node to NULL
    last = first ;  // Set the last pointer to point to the first node

    for ( int i = 1 ; i < n ; i ++ )
    {
        t = ( struct Node * ) malloc ( sizeof ( struct Node ) ) ;  // Allocate memory for a new node
        t -> data = A [ i ] ;  // Assign data to the new node
        t -> next = NULL ;  // Initialize the next pointer of the new node to NULL
        last -> next = t ;  // Link the new node to the list
        last = t ;  // Move the last pointer to the newly created node
    }
}

void display ( struct Node *p )
{
    while ( p != NULL )
    {
        printf ( "%d ", p -> data ) ;  // Print the data of the current node
        p = p -> next ;  // Move to the next node
    }
}

void main ( )
{
    int A[] = { 3 , 5 , 7 , 10 , 15 } ;  // Array to create the linked list
    create ( A , 5 ) ;  // Create the linked list using the array

    display ( first ) ;  // Display the linked list
}