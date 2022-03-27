#include <iostream>
#include "sort.h"

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


