#include <iostream>
using namespace std; 


int lengthOfLongestSubstring(string s) {

    if (s.size() == 0) { //If string is empty 
        return 0; //Return 0 
     }

    const int Max = 300; //Size of hash table 
    int hashtable[Max] = { -1 }; // Let us initialize the hash table value to -1
    int i = 0; 

   
    for (i = 0; i < Max; i++) {
        hashtable[i] = -1; //Insert -1 to every slot in hashtable
     }

     int longest = 0;
     int start = 0;

     for (i = 0; i < s.size(); i++) {
         char c = s[i];
         if (hashtable[c] != -1) { //If hash table value is not equal to -1 
                // Means that is a duplicate character                  
                // Keep the length if more than the previous value
                longest = (int)max(longest, i - start);

                // Reset the hashtable value for all characters that are 
                // before previous character position
                for (int j = start; j < hashtable[c]; j++) {
                    hashtable[s[j]] = -1;
                }

                // Move the start position
                start = hashtable[c] + 1;
            }
            hashtable[c] = i;
        }

        // keep the length if more than the previous value
        return max(longest, i - start);
 }



int main() {
    cout << "Longest Substring: " << endl;
   
	string a = "abcabcbb";
    cout << "Input: " << a << " , length of " << lengthOfLongestSubstring(a) << endl;

    string b = "bbbbb";
    cout << "Input: " << b << " , length of " << lengthOfLongestSubstring(b) << endl;

    string c = "abdce";
    cout << "Input: " << c << " , length of " << lengthOfLongestSubstring(c) << endl;


    
}
