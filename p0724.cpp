#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long Sum(vector<int> nums){
        long long ans=0;
        for(int val : nums) ans+=val;
        return ans;
    }
    int pivotIndex(vector<int>& nums) {
        long long sum = Sum(nums);
        long long LS=0, RS=sum;
        for(int i=0; i<nums.size(); i++){
            if(LS==(RS-nums[i])) return i;
            LS += nums[i];
            RS -= nums[i];
        }
        return -1;
    }
};