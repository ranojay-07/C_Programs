/*This C code performs Matrix Multiplication between two matrices entered by the user. It prompts the user 
to input the dimensions of the two matrices and then takes the elements of each matrix as input. It 
verifies whether the matrices can be multiplied by checking if the number of columns of the first matrix 
matches the number of rows of the second matrix. If the multiplication is possible, it calculates the 
product matrix by iterating through the rows and columns of the result matrix and computing each element 
using the corresponding elements of the input matrices. Finally, it prints the resulting matrix. If the 
dimensions are incompatible for multiplication, it displays an error message.*/

#include <stdio.h>

void main ()
{
    int r1 , r2 , c1 , c2 ;  // Declare variables for dimensions of matrices
    printf ( "Enter the number of row/s of the 1st matrix: " ) ;
    scanf ( "%d" , &r1 ) ;  // Input number of rows of first matrix
    printf ( "Enter the number of column/s of the 1st matrix: " ) ;
    scanf ( "%d" , &c1 ) ;  // Input number of columns of first matrix
    printf ( "Enter the number of row/s of the 2nd matrix: " ) ;
    scanf ( "%d" , &r2 ) ;  // Input number of rows of second matrix
    printf ( "Enter the number of column/s of the 1st matrix: " ) ;
    scanf ( "%d" , &c2 ) ;  // Input number of columns of second matrix

    if ( c1 == r2 )  // Check if multiplication is possible
    {
        int arr1 [ r1 ] [ c1 ] ;  // Declare array for first matrix
        int arr2 [ r2 ] [ c2 ] ;  // Declare array for second matrix

        printf ( "Enter the elements of the 1st matrix:\n" ) ;
        for ( int i = 0 ; i < r1 ; i ++ )  // Input elements of first matrix
        {
            for ( int j = 0 ; j < c1 ; j ++ )
                scanf ( "%d" , &arr1 [ i ] [ j ] ) ;
        }

        printf ( "Enter the elements of the 2nd matrix:\n" ) ;
        for ( int i = 0 ; i < r2 ; i ++ )  // Input elements of second matrix
        {
            for ( int j = 0 ; j < c2 ; j ++ )
                scanf ( "%d" , &arr2 [ i ] [ j ] ) ;
        }
        
        printf ( "Result of array multiplication:\n" ) ;
        for ( int i = 0 ; i < r1 ; i ++ )  // Perform matrix multiplication
        {
            for ( int k = 0 ; k < c2 ; k ++ )
            {
                int s = 0 ;  // Initialize sum for each element of result matrix
                for ( int j = 0 ; j < c1 ; j ++ )
                    s += arr1 [ i ] [ j ] * arr2 [ j ] [ k ] ;  // Compute element of result matrix
                printf ( "%d\t" , s ) ;  // Print element of result matrix
            }
            printf ( "\n" ) ;  // Move to next row of result matrix
        }
    }
    else
        printf ( "ERROR: Colomn of 1st matrix is not matching with the row of the second matrix" ) ;  // Print error if multiplication not possible
}