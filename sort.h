
// INSERTION
void insertion_sort(int *arr, const int n); 

// SELECTION
void selection_sort(int *arr, const int n); 

// MERGE 
void merge_sort(int arr[], int left, int right);
void merge(int arr[], int left, int middle, int right);

// BUBBLE 
void bubble_sort(int arr[], int n);

// QUICK
int partition(int arr[], int left, int right);
void quick_sort(int *arr, int p, int r);

// COUNTING
void counting_sort(int *A, int k, int n);// k is the largest int in the array

// RADIX
int number_digits(int max);
int get_digit(int d, int input);
void radix_sort(int *A, int k, int n);

// HEAP
void heap_sort(int *arr, int n);
