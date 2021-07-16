class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int m = arr1.size();
    int n = arr2.size(); 
    int median = (m + n) / 2; 

    int* merged = new int[m + n]; 
    int x = 0; 
    int y = 0; 
    int index = 0; 

    while (index <= median) {  
        if (y < n && (x>=m||arr2[y] < arr1[x])) { 
            merged[index] = arr2[y]; 
            y++;   
        }
        else if (x < m) { 
            merged[index] = arr1[x];
            x++;
        }
        index++; 
    }

    double result = (double)merged[median];
    if ((m + n) % 2 == 0) { 
        result += merged[median - 1]; 
        result = result / 2; 
    }
    return result; 
      
    
}
};
