#ifndef SORT_H
#define SORT_H 1
/*
 This is a library of sorting functions in C
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
	QUICK
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
merge(A,p,q,r):
 n1 <- q - p + 1
 n2 <- r - q
 for i<-1 to n1 do
 	L[i] <- A[p+i-1]
 for j<-1 to n2 do
 	R[j] <- A[q+j]
 
 i = 1, j = 1
 for k<-p to r do
 	if L[i] <= R[j]
 		then A[k] = L[i]
 		i <- i+1
 	else
 		then A[k] = R[j]
 		j <- j+1
*/
void merge( int* arrayToSort, int lhv, int mv, int rhv );

/*
Quick(A,p,r):
	if p < r
		q = partition(A,p,r)
		quicksort(A,p,q-1)
		quicksort(A,q+1,r)
*/
void quickSort( int* arrayToSort,int lhv, int rhv);

/*
Partition(A,p,r):
	x = A[r]
	i = p - 1
	for j = p to r - 1 do
		if A[j] <= x
			i++
			swap A[i] and A[j]
	swap A[i+1] with A[r]
	return i+1
*/
int partition( int* A, int p, int r);

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

/*
(Put elements of 'a' in heap order, in-place)
procedure heapify(a, count) is
    (start is assigned the index in 'a' of the last parent node)
    (the last element in a 0-based array is at index count-1; find the parent of that element)
    start ← floor ((count - 2) / 2)
    
    while start ≥ 0 do
        (sift down the node at index 'start' to the proper place such that all nodes below
         the start index are in heap order)
        siftDown(a, start, count - 1)
        (go to the next parent node)
        start ← start - 1
    (after sifting down the root all nodes/elements are in heap order)
*/
void heapify( int* arrayToSort, int size );

/*
(Repair the heap whose root element is at index 'start', assuming the heaps rooted at its children are valid)
procedure siftDown(a, start, end) is
    root ← start

    while root * 2 + 1 ≤ end do    (While the root has at least one child)
        child ← root * 2 + 1       (Left child)
        swap ← root                (Keeps track of child to swap with)

        if a[swap] < a[child]
            swap ← child
        (If there is a right child and that child is greater)
        if child+1 ≤ end and a[swap] < a[child+1]
            swap ← child + 1
        if swap = root
            (The root holds the largest element. Since we assume the heaps rooted at the
             children are valid, this means that we are done.)
            return
        else
            swap(a[root], a[swap])
            root ← swap            (repeat to continue sifting down the child now)
*/
void siftDown( int* arrayToSort, int start, int end );


#endif

/*******************************************************************\
EOF
\*******************************************************************/