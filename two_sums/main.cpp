#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "two_sums.h"

using namespace std;

int main()  {

    vector<int> arr;
     
    std::ifstream myfile;
    myfile.open("nums.txt");
    std::string word;
    int temp;

    // Reading from file
    while(myfile >> word) {
        temp = std::stoi(word);
        arr.insert(arr.begin(), temp);
    }
    
    cout << "Please enter a number to check: ";
    cin>> word;
    temp = stoi(word);

    if (best(arr, temp)) {
        printf("Found");
    } else {
        printf("Not found");
    }
    cout<<endl;

    return 1;
}
