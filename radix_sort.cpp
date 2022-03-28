#include <iostream>
int number_digits(int max) {
    int count = 1,
    temp = 10;

    while (max/temp != 0) {
        count++;
        temp *= 10;
    }
    return count+1;
}

int get_digit(int d, int input) { //div is calulated in radix sort
    
    int count = d;
    int divider = 1;
    while(count>1) {
        count--;
        divider *= 10;
    }

    return (input/divider)%10;    
}

void radix_sort(int *A, int k, int n){
    
    int output[n]; // output array
    int temp[10]; // temp array to hold count
    int i; // var to iterate throught the arrray

    for (int digit = 1; digit < number_digits(k); digit++) { //iterates through each base 10 digit

        // init count arr
        for (i = 0; i<10; i++) {
            temp[i] = 0;
        }      
        
        // getting count
        for (i = 0; i < n; i++)
            temp[(get_digit(digit, A[i]))]++;

        // accumulating temp
        for (i = 1; i < 10; i++)
            temp[i] += temp[i - 1];
 
        // putting values into the output array
        for (i = n - 1; i >= 0; i--) {
            output[temp[(get_digit(digit, A[i]))] - 1] = A[i];
            temp[(get_digit(digit, A[i]))]--;
        }
    
        // putting results into our og array
        for (i = 0; i < n; i++)
            A[i] = output[i];
    }
}
