#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int m = arr1.size(); //Get the length of arr1
    int n = arr2.size(); //Get the length of arr2 
    int median = (m + n) / 2; //Calculate the median of two arrays

    int* merged = new int[m + n]; //Create new array with size of m+n
    int x = 0; //Iterator to traverse the arr1 (First array) 
    int y = 0; //Iterator to traverse the arr2 (Second array)
    int index = 0; //Iterator for the merged array 

    while (index <= median) { //Make sure only iterate until median 
        if (y < n && (x >= m || arr2[y] < arr1[x])) { // First iteration: arr2[y] = 3, arr1[x] = 1, so wont run this in the first iteration  
            merged[index] = arr2[y]; //Initialize the index with value in arr2
            y++; //Increment y for the next value in arr2  
        }
        else if (x < m) { //If x is less than size of arr1, 
            merged[index] = arr1[x]; //Intialize value of arr1[x] into the merged array 
            x++; //Increment x for the next value in arr1
        }
        index++; //After each iteration index will increment 
    }

    double result = merged[median];// result = value of merged array at median position
    if ((m + n) % 2 == 0) { //If m+n has no remainder, means that it's even size
        result += merged[median - 1]; //Add the value of median with the value before median 
        result = result / 2; //After [(median)+(median-1)] divide 2, then it's the final median 
    }
    return result; //Done! 
}




int main() {
    vector<int> arr1 = { 1,2,3,4,5,6 };
    vector<int>arr2 = { 7,8,9,10,11,12,13 };
    cout << findMedianSortedArrays(arr1,arr2) << endl;


    
}
