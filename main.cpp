//this will be where we test :ach sorting algotihtm that is in our .h fiile
#include <iostream>
#include <ctime>
#include <iomanip>
#include "sort.h"
#include "test.h"

int max_number = 1000;
int size = 399;
int test_number = 7;
int verbos = 0;


// Makes a random array
// prints array
// test takes in arr and a number for which function to call


int main() { 

    srand((unsigned)time(0));
    int arr[size];
    //int temp; // for array reversal
    clock_t t;
    double time;

    for (int i=0; i<test_number; i++) {
        printf("\nTest Case #%d\n", i+1);
        
        set_rand(arr, size);
        t = clock(); 
        test (arr, i);
        t = clock() - t;
        time = ((double)t)/CLOCKS_PER_SEC;

        if (verbos==1) {
            printf("Input: ");
            print_arr(arr, size);
            printf("\n");}
        
        printf("Initializing took %f seconds\n", time);

        if (verbos==1) {
            printf("Input: ");
            print_arr(arr, size);
            printf("\n");}
        
        t = clock(); 
        test (arr, i);
        t = clock() - t;
        time = ((double)t)/CLOCKS_PER_SEC;

        if (verbos==1) {
            printf("\nOutput: ");
            print_arr(arr, size);
            printf("\n");}
        
        printf("Best case took %f seconds\n", time);
        

        set_worst(arr, i);
        if (verbos==1) {
            printf("Input: ");
            print_arr(arr, size);
            printf("\n");}
        
        t = clock(); 
        test (arr, i);
        t = clock() - t;
        time = ((double)t)/CLOCKS_PER_SEC;
        
        if (verbos==1) {
            printf("\nOutput: ");
            print_arr(arr, size);
            printf("\n");}

        printf("Worst case took %f seconds\n", time);

        set_rand(arr, size);
        if (verbos==1) {
            printf("Input: ");
            print_arr(arr, size);
            printf("\n");}
        
        t = clock(); 
        test (arr, i);
        t = clock() - t;
        time = ((double)t)/CLOCKS_PER_SEC;

        if (verbos==1) {
            printf("\nOutput: ");
            print_arr(arr, size);
            printf("\n");}

        printf("Average case took %f seconds\n", time);
    }
    

    return 1;
}


