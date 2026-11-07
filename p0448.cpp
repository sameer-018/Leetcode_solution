// Given an array nums of n integers where nums[i] is in the range [1, n], 
// return an array of all the integers in the range [1, n] that do not appear in nums.

// Time COmplexity O(n) and space complexity O(n) if output counted other wise O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // we just flip the sign of all positive number respective their index
        for(int i=0; i<nums.size(); i++){
            if(nums[abs(nums[i])-1] > 0){
                nums[abs(nums[i])-1] *= -1;
            }
        }
        //count the positive index and add to answer
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0) ans.push_back(i+1);
        }
        return ans;
    }
};