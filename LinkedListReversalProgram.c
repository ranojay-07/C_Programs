/*This C code implements a program that creates a singly linked list from user input, displays the original 
elements, reverses the linked list, and then displays the reversed elements. It begins by defining a node 
structure with integer data and a pointer to the next node. The create function prompts the user to input 
the number of elements and their values, dynamically allocates memory for each node, and links them 
together to form a linked list. The reverse function reverses the order of the nodes in the list by 
adjusting the next pointers. The display function recursively prints the data of each node in the list. 
In the main function, the program creates the linked list, displays the original elements, reverses the 
list, and displays the reversed elements. Overall, this program demonstrates basic operations of linked 
lists, including creation and reversal, using user input.*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data ;
    struct Node *next ;
} *first = NULL ;  // Global variable to store the address of the first node

void create ( )
{
    struct Node *t , *last ;  // Pointers to create new nodes and track the last node
    printf ( "Enter the no. of inputs you wanna give: " ) ;  // Prompt user to enter the number of inputs
    int n ;
    scanf ( "%d" , &n ) ;  // Read the number of inputs
    first = ( struct Node * ) malloc ( sizeof ( struct Node ) ) ;  // Allocate memory for the first node
    printf ( "Enter numbers:\n" ) ;  // Prompt user to enter the numbers
    scanf ( "%d" , &first -> data ) ;  // Read the first number and store it in the data field of the first node
    first -> next = NULL ;  // Set the next pointer of the first node to NULL
    last = first ;  // Set the last pointer to point to the first node

    for ( int i = 1 ; i < n ; i ++ )  // Loop to create remaining nodes
    {
        t = ( struct Node * ) malloc ( sizeof ( struct Node ) ) ;  // Allocate memory for a new node
        scanf ( "%d", &t -> data ) ;  // Read the data for the new node
        t -> next = NULL ;  // Set the next pointer of the new node to NULL
        last -> next = t ;  // Link the new node to the list
        last = t ;  // Move the last pointer to the newly created node
    }
}

void reverse ( struct Node *p )
{
    struct Node *q , *r ;  // Pointers to track the current, previous, and next nodes
    q = NULL ;  // Initialize previous pointer to NULL
    r = NULL ;  // Initialize next pointer to NULL
    while ( p != NULL )  // Loop through the list until the end is reached
    {
        r = q ;  // Set the next pointer to the current node
        q = p ;  // Move the current pointer to the next node
        p = p->next ;  // Move to the next node in the list
        q->next = r ;  // Reverse the link
    }
    first = q ;  // Update the first pointer to point to the new first node
}

void display ( struct Node *p )
{
    printf ( "%d " , p->data ) ;  // Print the data of the current node
    if ( p->next != NULL )  // Check if there are more nodes in the list
        display ( p->next ) ;  // Recursively call display function for the next node
}

void main ( )
{
    create ( first ) ;  // Create the linked list

    printf ( "Entered elements: " ) ;  // Display a message indicating the entered elements
    display ( first ) ;  // Display the elements of the linked list

    reverse ( first ) ;  // Reverse the linked list
    printf ( "\nReversing the linked list: " ) ;  // Display a message indicating the reversal
    display ( first ) ;  // Display the elements of the reversed linked list
}