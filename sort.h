
// Feel free to edit any funciton declerations
// write your code and just #inlcude "sort.h at the top"

void insertion_sort(int *arr, const int n);

void selection_sort(int *arr, const int n); //probably just use std::swap() 

void bubble_sort(int *arr, const int n);

void merge(int *arr, const int left, const int mid, const int right);
void merge_sort(int *arr, const int begin, const int end);

void quick_sort(int *arr, const int left, const int right);
void partition(int *arr, const int left, const int right);

void heap_sort(int *arr, int n); 
//add any other helper funcitons

void counting_sort(int *A, int *B, int k, int n); 
void radix_sort(int *A, int *B, int n, int d); 
