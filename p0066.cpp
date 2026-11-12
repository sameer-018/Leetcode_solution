// You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. 
// The digits are ordered from most significant to least significant in left-to-right order. 
// The large integer does not contain any leading 0's.
// Increment the large integer by one and return the resulting array of digits.

//TIme Complexity O(n) Space Complexity O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //initially we have to add 1 to last element so set c=1;
        int ans, c=1;
        //vector for storing ans 
        vector<int> res;
        for(int i=digits.size()-1; i>=0; i--){
            //getting last element one by one and adding carry to it
            ans = digits[i] + c;
            //updating the carry
            c = ans/10;
            //pushing answer to resultant
            res.push_back(ans%10);
        }
        //for last if still carry remain adding to resultant
        if(c) res.push_back(c);
        //at the end reversing the vector to get result
        reverse(res.begin(), res.end());
        return res;
    }
};