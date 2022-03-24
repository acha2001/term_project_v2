#include <iostream>
#include "sort.h"

using namespace std;

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

void mergeSort(int arr[], int left, int right)  //Recursive merge sort function
{
    if (left >= right)
        return;

    int middle = left + (right - left) / 2;
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}
