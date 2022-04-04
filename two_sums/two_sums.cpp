#include <iostream> 
#include <fstream> 
#include <algorithm> // For std::sort
#include <vector>
#include <unordered_set> // For hashing input
#include "two_sums.h"


 
void print(std::unordered_set<int> const &s) {

    for (auto const &i: s) {
        std::cout << i << " ";
    }
}

/*void print(std::vector<int> arr) {
    printf("{");
    for (int i=0; i<arr.size(); i++) printf("%d, ",arr.at(i));
    printf("}");
}
*/

// O(n^2)
bool brute_force(std::vector<int> arr, int key) {
    
    // For every value in the array we will iterate throught the array,
    // returning true only if that number plus the value we are checking
    // adds up to the key.
    
    for (int i=0; i<arr.size(); i++) {
        for (int j=0; j<arr.size(); j++) {
            if (arr[i]+arr[j] == key) {
                return true;
            } 
        }
    }
    return false;
}


// O(nlogn)
bool better(std::vector<int> arr, int key) {

    // First we need to sort the array, here in nlogn time
    int left=0, right=arr.size()-1;
    std::sort(arr.begin(), arr.end());

    // Now we can check for a sum at both ends of the array
    while (left < right) {
        if(arr[left]+arr[right]==key)  
            return true;

        else if (arr[left]+arr[right]<key) left++; 
        else if (arr[left]+arr[right]>key) right--;
    } 

    return false;
}

// O(n)
bool best(std::vector<int> arr, int key) {

    int temp; // this will hold the value that
              // we are looking for
    std::unordered_set<int> map;

    for (int i=0; i<arr.size(); i++) {

        temp= key-arr[i];
        // .find() returns itorator
        // this means it isn't there
        if ( map.find(temp) != map.end()) {
            return true;
        } 
        // serach a hash table for temp
        // return true if found

        // if not found insert arr[i] into table
        map.insert(arr[i]);
    }
    print(map);
    return false;
}



