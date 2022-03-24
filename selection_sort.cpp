#include <iostream>
#include "sort.h"

void selection_sort(int *arr, const int n)
{
	int a, b, Min_Index;

	for (a = 0; a < n - 1; a++)						 
	{
		Min_Index = a;							
		for (b = a + 1; b < n; b++)					

			if (arr[b] < arr[Min_Index])			
				Min_Index = b;
                std::swap( arr[Min_Index], arr[a]);				
                                                            
	}
}

