#include <iostream>
#include <iomanip>
#include "test.h"

void set_rand(int *arr, int n) {
    
    for (int i=0; i<n; i++) {
        arr[i] = rand()%(max_number+1);
    }

}
void print_arr(int *arr, int n) {
    int written = 0;
    std::cout << "\n{\n";
    for (int i=0; i<n; i++) {
        written++;
        std::cout<< std::setw(3) <<arr[i] <<", ";
        if (written == 20) { 
            written = 0;
            std::cout<< "\n";
        }
    }
    std::cout<< "}";
}
