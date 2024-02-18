/*This C code defines functions to create a singly linked list based on user input, display its elements, 
and reverse the first 'n' elements of the list. The program begins by prompting the user to input the 
number of elements they want to add to the list. It then creates the linked list by dynamically allocating 
memory for each node and linking them together. After displaying the original list, the program prompts 
the user to enter a position ('n') to reverse the list up to that point. Upon receiving the input, it 
reverses the specified number of elements by adjusting the pointers accordingly. Finally, it displays 
the modified list. This code illustrates fundamental concepts of linked list manipulation, including 
dynamic memory allocation and pointer manipulation for traversal and modification.*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node
{
    int data;           // Data stored in the node
    struct Node *next;  // Pointer to the next node in the list
} *first = NULL;        // Global pointer to the first node of the linked list

// Function to create a linked list based on user input
void create()
{
    struct Node *t, *last; // Pointers for creating new nodes and keeping track of the last node
    printf("Enter the number of inputs you want to give: ");
    int n;
    scanf("%d", &n); // Read the number of inputs
    first = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for the first node
    printf("Enter numbers:\n");
    scanf("%d", &first->data); // Read data for the first node
    first->next = NULL; // Initialize the next pointer of the first node to NULL
    last = first; // Set last pointer to point to the first node

    // Loop to create remaining nodes and link them to the list
    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for a new node
        scanf("%d", &t->data); // Read data for the new node
        t->next = NULL; // Initialize the next pointer of the new node to NULL
        last->next = t; // Link the new node to the list
        last = t; // Update last pointer to point to the new node
    }
}

// Function to display the elements of the linked list
void display(struct Node *p)
{
    // Traverse the list and print data of each node
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

// Function to reverse the first n elements of a linked list
void n_reverse(struct Node *p, int n)
{
    int c = 0; // Counter variable to keep track of the number of nodes processed
    struct Node *q, *r; // Pointers for reversing the nodes
    // Traverse the list to locate the nth node
    while (c != n)
    {
        c++;
        q = p->next; // Store the next pointer of the current node
        p = p->next; // Move to the next node
    }
    r = NULL; // Initialize a pointer for reversing
    p = first; // Reset p to the first node
    c = 0; // Reset the counter
    // Traverse the list again to reverse the first n nodes
    while (p != NULL && c != n)
    {
        r = q; // Store the next pointer of the reversed node
        q = p; // Move q to the current node
        p = p->next; // Move to the next node
        q->next = r; // Reverse the link
        c++; // Increment the counter
    }
    first = q; // Update the global pointer to point to the new first node
}

// Main function
void main()
{
    create(); // Create the linked list
    printf("Elements unreversed: ");
    display(first); // Display the elements of the original linked list

    printf("\nEnter a position to reverse the linked list up to that position: ");
    int pos;
    scanf("%d", &pos); // Read the position for reversing

    printf("Elements after reversing the first %d elements of the linked list: ", pos);
    n_reverse(first, pos); // Reverse the first n elements of the linked list
    display(first); // Display the modified linked list
}