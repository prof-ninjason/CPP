//
//  SortingComparison.cpp
//  Sorting Examples
//
//  Created by Dale Reed on 8/18/14.
//

#include <stdlib.h>
#include <stdio.h>
#include <ctime>      // For time functions
#include <math.h>     // For pow()
using namespace std;


// For debugging:
void displayArray( int theArray[], int start, int end)
{
    for( int j=0; j<=start; j++) {
        printf("  ");
    }
    for( int i=start; i<=end; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    for( int j=0; j<=start; j++) {
        printf("  ");
    }
    for( int i=start; i<=end; i++) {
        printf("%2d ", theArray[ i]);
    }
    printf("\n");
}


// Swap two array elements.  Used in sorting.
void swap( int theArray [], int i, int j)
{
    int temp = theArray[i];     // store temporarily
    theArray[i] = theArray[j];
    theArray[j] = temp;
}


// Bubble sort array to put into ascending order
void bubbleSort( int theArray[], int arraySize)
{
    for( int pass=1; pass < arraySize; pass++)  {
        for( int current=0; current < arraySize-pass; current++) {
            if ( theArray[ current] > theArray[ current+1]) {
                // swap the two array elements
                swap( theArray, current, current+1);
            }
        }//end for ( current
    }//end for (pass
}//end bubbleSort


// Selection sort array to put into ascending order
void selectionSort( int theArray[], int arraySize)
{
    int indexOfSmallest = 0;

    for( int pass=0; pass < arraySize; pass++)  {
        indexOfSmallest = pass;
        // Find smallest element among those still being sorted
        for ( int i=pass+1; i < arraySize; i++) {
            if ( theArray[ i] < theArray[ indexOfSmallest]) {
                // we have a new smallest value, so record it
                indexOfSmallest = i;
            }
        }//end for ( int i...

        // swap the smallest value found on this pass into place
        swap( theArray, pass, indexOfSmallest);
    }//end for (pass
}//end selectionSort()


// Insertion sort array to put into ascending order
void insertionSort( int theArray[], int arraySize)
{
    int indexOfSmallest = 0;

    for( int pass=1; pass<arraySize; pass++)  {
        indexOfSmallest = pass;
        // Choose next element among those still being sorted and slide it into place
        while( (indexOfSmallest > 0) && (theArray[ indexOfSmallest] < theArray[indexOfSmallest - 1]))  {
            swap( theArray, indexOfSmallest, indexOfSmallest-1);
            indexOfSmallest--;
        }

    }//end for ( int pass=1...
}//end selectionSort()


// Partition() - used as part of quickSort()
//    Partition array on a pivot so that all elements < pivot
// are to the left of the pivot position, and all elements >= pivot
// are to the right of the pivot position.
//   Select the pivot as the middle array element, then store it
// out of the way at the far right end of the array, swapping it
// back into the middle at the end of the partitioning.
int partition( int theArray[],   // the array
               int left,     // index of left-most element
               int right)    // index of right-most element
{
    // To find index of middle do it the funky way shown below to avoid integer overflow
    int pivotIndex = left + (right-left) / 2;
    int pivotValue = theArray[ pivotIndex];
    int storeIndex = left;    // destination on the left for first swap
    // Number of elements in subarray is: right-left+1

    // Put pivot value out of the way at far right of array, to be swapped back
    // into place at the end.
    swap( theArray, pivotIndex, right);

    // Go through the current range being considered of array elements,
    // moving each element into the left part of the partition if its value
    // is less than the pivot value.
    for( int i=left; i<right; i++) {
        if( theArray[i] < pivotValue) {
            swap( theArray, i, storeIndex);
            storeIndex++;
        }
    }
    // storeIndex is now the index of the location just to the right of the last
    // element that is < pivot, so its value >= pivot.  Swap the pivot back
    // into this spot.
    swap( theArray, storeIndex, right);    // Move pivot to its final place
    return storeIndex;
} // end partition()


void quickSort(int theArray[ ], int first, int last)
{
    int pivotIndex;

    if( first < last) {
        // Partition around a pivot and return index of pivot
        pivotIndex = partition( theArray, first, last);
        // recursively sort the portion to the left of the pivot
        quickSort(theArray, first, pivotIndex - 1);
        // recursively sort the portion to the RIGHT of the pivot
        quickSort(theArray, pivotIndex + 1, last);
    }
}// end quickSort()


int main()
{
    int arraySize;
    time_t beginTime = time( NULL);  // set the start time

    printf("Welcome to the Sort timing example program. \n\n");
    printf(" Elapsed    Array Size     Sort Time  \n");
    printf("(seconds)   (thousands)    (seconds)  \n");

    // Main loop, doing multiple iterations for different array sizees
    for( int i=2; i<pow(2,20); i=i*2) {
        arraySize = 1000 * i;


        // allocate space for the array
        int *pTheArray = (int *) malloc( sizeof(int) * arraySize);

        // initialize each array element to some random value 0..(arraySize-1)
        for( int j=0; j<arraySize; j++) {
            pTheArray[ j] = rand()%arraySize;  // on unix or Mac change rand() to random()
        }

        // Store the start time
        clock_t startTime = clock();

        // Sort the array, using one of the sorting approaches shown below:
        // bubbleSort( pTheArray, arraySize);
        // selectionSort( pTheArray, arraySize);
        // insertionSort( pTheArray, arraySize);
        quickSort( pTheArray, 0, arraySize-1);  // send indices of first and last elements

        // displayArray( pTheArray, 0, arraySize-1);   // for debugging, set size of array to be < 30

        // Display number of seconds elapsed.
        printf("%5.0f     %8d %15.4f\n", difftime(time( NULL), beginTime), i,
                                        (clock() - startTime)/(double)CLOCKS_PER_SEC);
    }

    printf("Press return to continue...\n");
    char c;
    scanf("%c", &c);
    return 0;
}
