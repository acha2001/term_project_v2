#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <numeric>
#include "sort.h"
#include "test.h"

int max_number = 10;
int size = 1;
int test_number = 7;
int verbos = 0;
int trials = 1; 

// Makes a random array
// prints array
// test takes in arr and a number for which function to call


int main() {

    srand((unsigned)time(0));
    int arr[size];
    //int temp; // for array reversal
    clock_t t;
    double time, time_sum;
    std::vector<double> time_vec;



    for (int i = 0; i <= test_number; i++) {

        time_sum = 0;
        printf("\n   Test Case #%d - Size: %d\n", i + 1, size);
        printf("Single run times: \n");
        set_rand(arr, size);
        t = clock();
        test(arr, i);
        t = clock() - t;
        time = ((double)t) / CLOCKS_PER_SEC;

        if (verbos == 1) {
            printf("Input: ");
            print_arr(arr, size);
            printf("\n");
        }

        // printf("Initializing took %f seconds\n", time);

        if (verbos == 1) {
            printf("Input: ");
            print_arr(arr, size);
            printf("\n");
        }

        t = clock();
        test(arr, i);
        t = clock() - t;
        time = ((double)t) / CLOCKS_PER_SEC;

        if (verbos == 1) {
            printf("\nOutput: ");
            print_arr(arr, size);
            printf("\n");
        }

        printf("    Best case took %f seconds\n", time);


        set_worst(arr, i);
        if (verbos == 1) {
            printf("Input: ");
            print_arr(arr, size);
            printf("\n");
        }

        t = clock();
        test(arr, i);
        t = clock() - t;
        time = ((double)t) / CLOCKS_PER_SEC;

        if (verbos == 1) {
            printf("\nOutput: ");
            print_arr(arr, size);
            printf("\n");
        }

        printf("    Worst case took %f seconds\n", time);

        set_rand(arr, size);
        if (verbos == 1) {
            printf("Input: ");
            print_arr(arr, size);
            printf("\n");
        }

        t = clock();
        test(arr, i);
        t = clock() - t;
        time = ((double)t) / CLOCKS_PER_SEC;

        if (verbos == 1) {
            printf("\nOutput: ");
            print_arr(arr, size);
            printf("\n");
        }

        printf("    Average case one trial took %f seconds\n", time);
        printf("Average run times: \n");

        // this is where I will prototype things to run muliple times 


        // next section will run multiple times for a sorted array
        for (int j=0; j<trials; j++) {

            t = clock();
            test(arr, i);
            t = clock() - t;
            time = ((double)t) / CLOCKS_PER_SEC;
            time_vec.push_back(time);

        }

        // acumulate the cases
        time_sum = 0;
        for (double x: time_vec) {
            time_sum += x;
        }
        time_vec.clear();

        // Must move the decimal by one for some reason
        printf("    Best case time after multiple runs: %f\n", time_sum/trials);

        // next section will run multiple times for a worst case array
        for (int j=0; j<trials; j++) {

            set_worst(arr, i); // generates worst case for algo i for input arr
            t = clock();
            test(arr, i);
            t = clock() - t;
            time = ((double)t) / CLOCKS_PER_SEC;
            time_vec.push_back(time);

        }

        // acumulate the cases
        time_sum = 0;
        for (double x: time_vec) {
            time_sum += x;
        }
        time_vec.clear();

        // Must move the decimal by one for some reason
        printf("    Worst case time after multiple runs: %f\n", time_sum/trials);



        // next section will run multiple times for a random array
        for (int j=0; j<trials; j++) {

            set_rand(arr, size);
            t = clock();
            test(arr, i);
            t = clock() - t;
            time = ((double)t) / CLOCKS_PER_SEC;
            time_vec.push_back(time);

        }

        // acumulate the cases
        time_sum = 0;
        for (double x: time_vec) {
            time_sum += x;
        }
        time_vec.clear();

        // Must move the decimal by one for some reason
        printf("    Average case time after multiple runs: %f\n", time_sum/trials);
    }


    return 1;
}
