//this will be where we test :ach sorting algotihtm that is in our .h fiile
#include <iostream>
#include <ctime>
#include <iomanip>
#include "sort.h"
#include "test.h"

int max_number = 10;
int size = 1000;
int test_number = 7;
int verbos = 1;


// Makes a random array
// prints array
// test takes in arr and a number for which function to call
void test(int *arr, int number);

int main() { 

    srand((unsigned)time(0));
    int arr[size];
    int temp; // for array reversal
    clock_t t;
    double time;

    std::cout <<" get_digit 3 of 30" << get_digit(3, 20)<< "\n";
    
    for (int i=0; i<test_number; i++) {
        printf("\nTest Case #%d\n", i+1);
        
        // Sorting a fully random array and printing the value.
        printf("Average case(random array): \n");
        set_rand(arr, size);
        if (verbos==1) {print_arr(arr, size);
            printf("\n");}
        
        t = clock(); 
        test (arr, i);
        t = clock() - t;
        time = ((double)t)/CLOCKS_PER_SEC;

        if (verbos==1) {print_arr(arr, size);
            printf("\n");}

        printf("Average case took %f seconds\n", time);

        // Sorting an array that is already in order.
        printf("Best case(sorted array): \n");
        if (verbos==1) {print_arr(arr, size);
            printf("\n");}
        
        t = clock(); 
        test (arr, i);
        t = clock() - t;
        time = ((double)t)/CLOCKS_PER_SEC;

        if (verbos==1) {print_arr(arr, size);
            printf("\n");}
        
        printf("Best case took %f seconds\n", time);
        
        // Reversing arr
        for (int j = 0; j < size / 2; j++) { 
            temp = arr[j]; 
            arr[j] = arr[size - j - 1]; 
            arr[size - j - 1] = temp; 
        } 

        // Sorting the reverse sort
        printf("Worst case(reverse array): \n");
        if (verbos==1) {print_arr(arr, size);
            printf("\n");}
        
        t = clock(); 
        test (arr, i);
        t = clock() - t;
        time = ((double)t)/CLOCKS_PER_SEC;
        
        if (verbos==1) {print_arr(arr, size);
            printf("\n");}

        printf("Worst case took %f seconds\n", time);

    }
    

    return 1;
}


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
