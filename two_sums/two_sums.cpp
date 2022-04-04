#include <iostream> 
#include <fstream> 
#include <algorithm> // For std::sort
#include <vector>
#include <unordered_set> // For hashing input
#include "two_sums.h"


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

    int left=0, right=arr.size()-1;             // First we need to sort the array,     
    std::sort(arr.begin(), arr.end());          // here in nlogn time

    while (left < right) {                      // Now we can check for 
        if(arr[left]+arr[right]==key)           // a sum at both ends of the array    
            return true;

        else if (arr[left]+arr[right]<key) left++; 
        else if (arr[left]+arr[right]>key) right--;
    } 

    return false;
}

// O(n)
bool best(std::vector<int> arr, int key) {

    int temp;                                   // this will hold the value that
                                                // we are looking for
    std::unordered_set<int> map;

    for (int i=0; i<arr.size(); i++) {

        temp= key-arr[i];
        if ( map.find(temp) != map.end()) {     // .find() returns itorator
            return true;                        // this means it isn't there
        } 
                                                // serach a hash table for temp
                                                // return true if found

        map.insert(arr[i]);                     // if not found insert arr[i] into table
        
    }
    return false;
}



