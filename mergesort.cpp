
#include <iostream>
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

void print(int arr[], int n)        //Print Array
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7, 9, 25, 14, 19};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted Array \n";
    print(arr, size);

    mergeSort(arr, 0, size - 1);

    cout << "\nSorted Arr \n";
    print(arr, size);
    return 0;
}