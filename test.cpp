#include <iostream>
#include <iomanip>
#include <ctime>
#include "test.h"
#include "sort.h"

void set_rand(int *arr, int n) {
    
    for (int i=0; i<n; i++) {
        arr[i] = rand()%(max_number+1);
    }

}
void print_arr(int *arr, int n) {
    int written = 0;
    
    std::cout << "\n{"; 
    for (int i=0; i<n; i++) { 
        written++; 
        std::cout<< std::setw(3) <<arr[i]; printf(", ");
        if (written == 25) { written = 0; printf("\n");}
    }
    printf("}");
}

//This funciton simply calls sort function
void test(int *arr, int number) {


    if (number == 0) {
        // void insertion_sort(int *arr, const int n); 
        printf("Insertion Sort - ");
        insertion_sort(arr, size) ;

    } else if (number == 1) {
        // void selection_sort(int *arr, const int n); 
        printf("Selection Sort - ");
        selection_sort(arr, size);

    } else if (number == 2) {

        // void merge_sort(int arr[], int left, int right);
        printf("Merge Sort - ");
        merge_sort(arr, 0, size-1);

    } else if (number == 3) {

        // void bubble_sort(int arr[], int n);
        printf("Bubble Sort - ");
        bubble_sort(arr, size); 

    } else if (number == 4) { 

        // void counting_sort(int *A, int k, int n);// k is the largest int in the array
        printf("Counting Sort - ");
        counting_sort(arr, max_number, size);

    } else if (number == 5) {

        //i void radix_sort(int *A, int k, int n);
        printf("Radix Sort - ");
        radix_sort(arr, max_number, size);

    } else if (number == 6) {

        // void heap_sort(int *arr, int n);
        printf("Heap Sort - ");
        heap_sort(arr, size);
    } 
}

// This function will set the input array to the worst case for each sorting algo
void set_worst(int *arr, int number) {
    //function will take a sorted array and rerange it for the worst case of each function

    if (number == 0) {
        // void insertion_sort(int *arr, const int n); 
        
        int temp;
        for (int j = 0; j < size / 2; j++) { 
            temp = arr[j]; 
            arr[j] = arr[size - j - 1]; 
            arr[size - j - 1] = temp; 
        } 

    } else if (number == 1) {
        // void selection_sort(int *arr, const int n); 
        int temp;
        for (int j = 0; j < size / 2; j++) { 
            temp = arr[j]; 
            arr[j] = arr[size - j - 1]; 
            arr[size - j - 1] = temp; 
        } 

    } else if (number == 2) {

        // void merge_sort(int arr[], int left, int right);
        // generateWorstCaseMerge(arr, 0, size-1);
        int temp;
        for (int j = 0; j < size / 2; j++) { 
            temp = arr[j]; 
            arr[j] = arr[size - j - 1]; 
            arr[size - j - 1] = temp; 
        } 

    } else if (number == 3) {

        // void bubble_sort(int arr[], int n);
        // reversing array
        int temp;
        for (int j = 0; j < size / 2; j++) { 
            temp = arr[j]; 
            arr[j] = arr[size - j - 1]; 
            arr[size - j - 1] = temp; 
        } 

    } else if (number == 4) { 

        // void counting_sort(int *A, int k, int n);// k is the largest int in the array
        // reversing array might not be correct 
        int temp;
        for (int j = 0; j < size / 2; j++) { 
            temp = arr[j]; 
            arr[j] = arr[size - j - 1]; 
            arr[size - j - 1] = temp; 
        } 
    } else if (number == 5) {

        //i void radix_sort(int *A, int k, int n);
        // reversing array might not be correct 
        int temp;
        for (int j = 0; j < size / 2; j++) { 
            temp = arr[j]; 
            arr[j] = arr[size - j - 1]; 
            arr[size - j - 1] = temp; 
        } 
    } else if (number == 6) {


        // reversing array might not be correct 
        int temp;
        for (int j = 0; j < size / 2; j++) { 
            temp = arr[j]; 
            arr[j] = arr[size - j - 1]; 
            arr[size - j - 1] = temp; 
        } 
    } 

}

// The next three functions are utility funcitons for merge worst case.
// Function to join left and right subarray
void join(int arr[], int left[], int right[], int l, int m, int r) {

    int i;
    for(i = 0; i <= m - l; i++)
        arr[i] = left[i];

    for(int j = 0; j < r - m; j++)
    {
        arr[i + j] = right[j];
    }
}

// Function to store alternate elements in
// left and right subarray
void split(int arr[], int left[], int right[], int l, int m, int r) {

    for(int i = 0; i <= m - l; i++)
        left[i] = arr[i * 2];

    for(int i = 0; i < r - m; i++)
        right[i] = arr[i * 2 + 1];
}

// Function to generate Worst Case
// of Merge Sort
void generateWorstCaseMerge(int arr[], int l, int r) {

    if (l < r)
    {
        int m = l + (r - l) / 2;

        // Create two auxiliary arrays
        int left[m - l + 1];
        int right[r - m];

        // Store alternate array elements
        // in left and right subarray
        split(arr, left, right, l, m, r);

        // Recurse first and second halves
        generateWorstCaseMerge(left, l, m);
        generateWorstCaseMerge(right, m + 1, r);

        // Join left and right subarray
        join(arr, left, right, l, m, r);
    }
}

