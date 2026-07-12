//maximum sum of continous sub array by kadanes algorithm
// Given an integer array nums, find the subarray with the largest sum, and return its sum.

#include <iostream>
#include <vector>
using namespace std;

// solution with O(n) time complexity
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum=INT64_MIN; //or use INT_MIN
        int curr_sum =0;
        for(int i=0; i<nums.size();i++){
            curr_sum += nums[i];
            max_sum = max(max_sum,curr_sum);
            if(curr_sum<0) curr_sum=0;
        }
        return max_sum;
    }
};