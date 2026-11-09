// Given an integer array nums, return the number of elements that have both a strictly smaller and a strictly greater element appear in nums.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums) {
        //getting size and ans variable 
        int n=nums.size(), ans=0;
        // lets find the most greatest and smallest element in the array 
        int mn=nums[0], mx=nums[0];
        for(int i=0; i<n; i++){
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        //checking all element which are strictly between them and incrementing the ans
        for(int i=0; i<n; i++) if(mn<nums[i] && nums[i]<mx) ans++;
        return ans;
    }
};