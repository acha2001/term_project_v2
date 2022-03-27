#include <iostream>
#include "sort.h"
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


