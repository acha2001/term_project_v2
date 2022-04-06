#ifndef _Test
#define _Test
#include <iostream>
#include <iomanip>
#include <ctime>
//#include "test.h"
#include "sort.h"

extern int max_number;
extern int size;
extern int test_number;
extern int verbos;

void set_rand(int* arr, int n);
void print_arr(int* arr, int n);
//This funciton simply calls sort function
void test(int* arr, int number); 
// This function will set the input array to the worst case for each sorting algo
void set_worst(int* arr, int number);
// The next three functions are utility funcitons for merge worst case.
// Function to join left and right subarray
void join(int arr[], int left[], int right[], int l, int m, int r);
// Function to store alternate elements in
// left and right subarray
void split(int arr[], int left[], int right[], int l, int m, int r);
// Function to generate Worst Case
// of Merge Sort
void generateWorstCaseMerge(int arr[], int l, int r); 

#endif
