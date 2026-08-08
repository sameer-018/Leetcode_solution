// implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

// The algorithm for myAtoi(string s) is as follows:

// Whitespace: Ignore any leading whitespace (" ").
// Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
// Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
// Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
// Return the integer as the final result.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n = s.length();
        vector<int> num;
        int sign = 1;
        while(s[i]==' ' && i<n){
            i++;
        }
        if(s[i]=='-' && i<n){
            sign = -1;
            i++;
        }
        if(s[i]=='+' && (sign==1) && i<n) i++;

        while(s[i]=='0' && i<n){
            i++;
        }

        while('0'<=s[i] && s[i]<='9' && i<n){
            num.push_back(s[i]-48);
            i++;
        }

        long sum = 0, place = 1;
        for(int j=num.size()-1; j>=0; j--){
            sum += place*num[j];
            place *= 10;
            if(j>10 && sign==1) return INT_MAX;
            if(j>10 && sign==-1) return INT_MIN;
            if(sum*sign <= INT_MIN) return INT_MIN;
            if(sum*sign >= INT_MAX) return INT_MAX;
        }
        return sum*sign;
    }
};