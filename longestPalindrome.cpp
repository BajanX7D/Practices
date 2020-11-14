#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    if (s.empty()) { //If string is empty then return 0 
        return "0";
    }

    if (s.size() < 2) {
        return s; //If string only have 1 element, then return that 1 element only 
    }

    int start = 0; 
    int end = 0; 
    int i = 0; 
    int n = s.size();
    int left = 0;
    int right = 0; 

    while (i < n) { 
        start = i; 
        end = i; 
        i++; 

        while (i < n && s[i] == s[start]) {  
            i++; //If the current character is same with the next character then keep increasing 
        }
        end = i - 1; //The end will be the position of i - 1 

        while (start - 1 >= 0 && end + 1 < n && s[start - 1] == s[end + 1]) { //If this condition is true 
            start--; //Means that there are palindrome 
            end++;  //Then this function will detect the start and end of the palindrome 
        }

        if (right - left <= end - start) {
            left = start; 
            right = end; 
        }
    }
    return s.substr(left, right - left + 1);
}

int main() {
    string one = "aaaaaaaaaaaaaa";
    cout << longestPalindrome(one) << endl;

    string two = "babad";
    cout << longestPalindrome(two) << endl;

    string three = "ac";
    cout << longestPalindrome(three) << endl;

    string four = "";
    cout << longestPalindrome(four) << endl;


    
}
