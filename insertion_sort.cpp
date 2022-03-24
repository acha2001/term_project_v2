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
