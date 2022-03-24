#include<iostream>
#include <fstream>
#include <chrono>
using namespace std;

void swap(int* sp, int* tp);
void SelectionSort(int arr[], int x);
void printArray(int arr[], int size);
void insertion_sort(int* arr, int n);

int main()
{
	std::chrono::system_clock::time_point startTime, endTime;
	int arr_size = 100;
	int increment = 1000;
	const int MAXRANGE = 50000;
	int array[MAXRANGE];

	bool run = 1;
	char option;

	while (run) {
		cout << "Enter size: ";
		cin >> arr_size;

		cout << "Average case\n";
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < arr_size; j++) {				
				array[j] = rand() % 1000;
			}
			startTime = std::chrono::system_clock::now();
			SelectionSort(array, arr_size);
			endTime = std::chrono::system_clock::now();
			cout << float(std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count()) << "\n";
		}

		cout << "\nBest case\n";
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < arr_size; j++) {				
				array[j] = rand() % 1000;
			}
			startTime = std::chrono::system_clock::now();
			SelectionSort(array, arr_size);
			endTime = std::chrono::system_clock::now();
			cout << float(std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count()) << "\n";
		}

		cout << "\nWorst case\n";
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < arr_size; j++) {				
				array[j] = rand() % 1000;
			}
			startTime = std::chrono::system_clock::now();
			insertion_sort(array, arr_size);
			endTime = std::chrono::system_clock::now();
			cout << float(std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count()) << "\n";
		}

		cout << "Continue (y/n)? ";
		cin >> option;
		if (option != 'y') run = 0;
	}

	/*
	for (int i = 0; i < arr_size; i++) {
		array[i] = rand() % 1000;
		printf("  %i", array[i]);
	}
	SelectionSort(array, arr_size);
	cout << "\nSorted array: \n";
	printArray(array, arr_size);
	*/
	
	return 0;
}
void swap(int* sp, int* tp)
{
	int temp = *sp;
	*sp = *tp;
	*tp = temp;
}
void SelectionSort(int arr[], int x)
{
	int a, b, Min_Index;							// c1
	for (a = 0; a < x - 1; a++)						// c2 (x)
	{
		Min_Index = a;								// c3
		for (b = a + 1; b < x; b++)					// c4 (x-1)(1+2+3+...+x) => c4(x-1)((x(x+1))/2)
			if (arr[b] < arr[Min_Index])			// c5 (x-1)((x(x+1))/2)
				Min_Index = b;
		swap(&arr[Min_Index], &arr[a]);				// c6 (x-1)
		//swap(&arr[Min_Index-1], &arr[a]);
	}

	/*
		c1 + c2(x) + c3 + c4((x(x+1))/2) + c5((x(x+1))/2) + c6(x-1)

		a = c1 + c3 + c6
		b = c2 + c6
		c = c4 + c5

		a + bx + c(x^2 + x +1)/2
	*/
}
void insertion_sort(int* arr, int n) {

	int key, temp;

	for (int i = 1; i < n; i++) {

		key = arr[i];
		temp = i - 1;


		while (temp >= 0 && arr[temp] > key) {

			arr[temp + 1] = arr[temp];
			temp = temp - 1;

		}

		arr[temp + 1] = key;
	}
}
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
