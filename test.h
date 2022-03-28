
extern int max_number;
extern int size;

void print_arr(int *arr, int n);
void set_rand(int *arr, int n); 
void test(int *arr, int number);
void set_worst(int *arr, int number);

void generateWorstCaseMerge(int arr[], int l, int r);
void split(int arr[], int left[], int right[], int l, int m, int r);
