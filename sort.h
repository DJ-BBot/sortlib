#ifndef SORT_H
#define SORT_H 1
/*
 This is a library of sorting functions in C
 
 Author: Roger Barker
 Last Edit: 20150831
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//------------------------------------------------------------
/*
Return size of array
*/
#define ARRLEN(x)  (sizeof(x) / sizeof((x)[0]))

//------------------------------------------------------------
typedef enum{
	SELECTION,
	INSERTION,
	MERGE,
	QUICK,
	BUBBLE,
	HEAP
}sortMode;

typedef enum{
	FALSE,
	TRUE
}BOOL;

//------------------------------------------------------------
void printArray( int* array, int size, int mod );

void randomizeArray( int* array, int size, int mod );

//------------------------------------------------------------
/* 
Selection Sort:
 For i = 1 to n do 
 	min <- i
 	For j = i +1 to n do
 		if A[j] < A[min] then 
 			min <- j
 	
 	temp   <- A[i]
 	A[i]   <- A[min]
 	A[min] <- temp
 	
*/
void selectionSort( int* arrayToSort, int size );

/*
Insertion Sort:
 For j = 2 to n do
 	key <- A[j]
 	i <- j - 1
 	while i > 0 and key < A[i]
 		A[i+1] <- A[i]
 		i <- i - 1
 	A[i+1] <- key
*/
void insertionSort( int* arrayToSort, int size );

/*
 mergeSort(A,p,r):
 if(p < r)
	then q <- floor((p+r)/2)
		mergeSort(A,p,q)
		mergeSort(A,q+1,r)
		merge(A,p,q,r)
*/
void mergeSort( int* arrayToSort, int lhv, int rhv );

/*
Quick(A,p,r):
	if p < r
		q = partition(A,p,r)
		quicksort(A,p,q-1)
		quicksort(A,q+1,r)
*/
void quickSort( int* arrayToSort,int lhv, int rhv);

/*
bubbleSort( A, n  ):
   repeat 
     swapped = false
     for i = 1 to n-1 inclusive do
       // if this pair is out of order
       if A[i-1] > A[i] then
         // swap them and remember something changed
         swap( A[i-1], A[i] )
         swapped = true
       end if
     end for
   until not swapped
end procedure
*/
void bubbleSort( int* arrayToSort, int size );

/*
procedure heapsort(a, count) is
    input: an unordered array a of length count
 
    (Build the heap in array a so that largest value is at the root)
    heapify(a, count)

    (The following loop maintains the invariants that a[0:end] is a heap and every element
     beyond end is greater than everything before it (so a[end:count] is in sorted order))
    end ← count - 1
    while end > 0 do
        (a[0] is the root and largest value. The swap moves it in front of the sorted elements.)
        swap(a[end], a[0])
        (the heap size is reduced by one)
        end ← end - 1
        (the swap ruined the heap property, so restore it)
        siftDown(a, 0, end)
*/
void heapSort( int* arrayToSort, int size );


#endif

/*******************************************************************\
EOF
\*******************************************************************/