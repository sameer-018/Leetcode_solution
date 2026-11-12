// You are given an array of integers nums. 
// Return the length of the longest subarray of nums which is either strictly increasing or strictly decreasing.

#include <bits/stdc++.h>
using namespace std;

//Time Complexit O(n) space complexity O(1)
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        //mainting two varible to store max number of element in increaing / decreasing array
        int inc=1, dec=1;
        //two curr eleement to track curr sub array
        int curr1=1, curr2=1;
        // in one iteration checking both
        for(int i=1; i<nums.size(); i++){
            //if next is strickly increasing update curr1
            if(nums[i-1]<nums[i]) curr1++;
            //other wise setback curr1 =1
            else curr1=1;
            //update inc
            inc = max(inc, curr1);
            //if next is strictly decreasing update curr2
            if(nums[i-1]>nums[i]) curr2++;
            //otherwise set back curr2 =1
            else curr2=1;
            dec = max(dec, curr2);
        }
        //return max of dec, inc
        return max(dec, inc);
    }
};