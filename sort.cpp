#include <iostream>
#include "sort.h"

void insertion_sort(int *arr, int n) {

    int key, temp;
    
    for (int i=1; i<n; i++) {
        key = arr[i];
        temp = i -1;

        while (temp >= 0 && arr[temp] > key) {
            arr[temp + 1] = arr[temp];
            temp = temp-1;
        }
    
        arr[temp + 1] = key;
    }
}

void selection_sort(int *arr, const int n)
{
	int a, b, Min_Index;

	for (a = 0; a < n - 1; a++)						 
	{
		Min_Index = a;							
		for (b = a + 1; b < n; b++)					

			if (arr[b] < arr[Min_Index])			
				Min_Index = b;
                std::swap( arr[Min_Index], arr[a]);				
                                                            
	}
}

void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)    
     
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            std::swap(arr[j], arr[j+1]);
}

void merge(int arr[], int left, int middle, int right) //Merge two sub arrays
{
    int S1 = middle - left + 1;
    int S2 = right - middle;

    int *leftArr = new int[S1],
        *rightarr = new int[S2];

    for (int i = 0; i < S1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < S2; j++)
        rightarr[j] = arr[middle + 1 + j];

    int index_One = 0;
    int index_Two = 0;
    int index_Merged = left;

    while (index_One < S1 && index_Two < S2)        //Merging from left to right temp->original array
    {
        if (leftArr[index_One] <= rightarr[index_Two])
        {
            arr[index_Merged] = leftArr[index_One];
            index_One++;
        }
        else
        {
            arr[index_Merged] = rightarr[index_Two];
            index_Two++;
        }
        index_Merged++;
    }

    while (index_One < S1)  //Copying left elements
    {
        arr[index_Merged] = leftArr[index_One];
        index_One++;
        index_Merged++;
    }

    while (index_Two < S2)  //Copying right elements
    {
        arr[index_Merged] = rightarr[index_Two];
        index_Two++;
        index_Merged++;
    }
}

void merge_sort(int arr[], int left, int right)  //Recursive merge sort function
{
    if (left >= right)
        return;

    int middle = left + (right - left) / 2;
    merge_sort(arr, left, middle);
    merge_sort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

int partition(int arr[], int left, int right) {

    int pivot = arr[left];
    int i = left - 1, j = right + 1;
 
    while (true) {
        do {
            j--;
        } while (arr[j] > pivot);
 
        do {
            i++;
        } while (arr[i] < pivot);
        
        if (i < j) {
            std::swap(arr[i], arr[j]);
        } else {
        return j;
        }
    }
}

void quick_sort(int *arr, int p, int r) {
    
    if (p < r) {
        int q = partition(arr, p, r);
        quick_sort(arr, p, q);
        quick_sort(arr, q+1, r);
    }
}

void max_heapify(int *arr, int n,int i) {
    //all of these are idxs
    int leftChild = (i*2)+1;
    int rightChild = (i*2)+2;
    int largestNode = i;
    
    if (i > n/2) { //we are at a leaf node
        return;
    }
    if (leftChild < n && arr[leftChild] > arr[i]) {
        largestNode = leftChild;
    }
    if (rightChild < n && arr[rightChild] > arr[largestNode]) {
        largestNode = rightChild;
    }
    if (largestNode != i) {
        std::swap(arr[i], arr[largestNode]);
        max_heapify(arr, n, largestNode);
    }
}

void heap_sort(int *arr, int n) {
    for (int i = (n/2)-1; i >-1; i--) {
        max_heapify(arr, n, i);
    }
}

void counting_sort(int *A, int k, int n) {

    int a[k+1], // counter array
    temp[n]; // temp array to hold output
    int i;

    for(i=0; i<k+1; i++){ //set acum arr to 0
        a[i] = 0;
    }

    for (i=0; i<n; i++){//acum values in A
        ++a[A[i]];
    }

    for(i=1; i<k+1; i++) {//add up acum arr
        a[i] = a[i] + a[i-1];
    for (i=n-1; i>-1; i--){//insert into ouput array
        temp[a[A[i]]-1] = A[i];
        --a[A[i]] ;
    }
 
    // setting A to output
    for(i=0; i<n; i++){
        A[i] = temp[i];
    }
}

int number_digits(int max) {
    int count = 1,
    temp = 10;

    while (max/temp != 0) {
        count++;
        temp *= 10;
    }
    return count+1;
}

int get_digit(int d, int input) { //div is calulated in radix sort
    
    int count = d;
    int divider = 1;
    while(count>1) {
        count--;
        divider *= 10;
    }

    return (input/divider)%10;    
}

void radix_sort(int *A, int k, int n){
    
    int output[n]; // output array
    int temp[10]; // temp array to hold count
    int i; // var to iterate throught the arrray

    for (int digit = 1; digit < number_digits(k); digit++) { //iterates through each base 10 digit

        // init count arr
        for (i = 0; i<10; i++) {
            temp[i] = 0;
        }      
        
        // getting count
        for (i = 0; i < n; i++)
            temp[(get_digit(digit, A[i]))]++;

        // accumulating temp
        for (i = 1; i < 10; i++)
            temp[i] += temp[i - 1];
 
        // putting values into the output array
        for (i = n - 1; i >= 0; i--) {
            output[temp[(get_digit(digit, A[i]))] - 1] = A[i];
            temp[(get_digit(digit, A[i]))]--;
        }
    
        // putting results into our og array
        for (i = 0; i < n; i++)
            A[i] = output[i];
    }
}


