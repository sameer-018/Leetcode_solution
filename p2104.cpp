// You are given an integer array nums. 
// The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
// Return the sum of all subarray ranges of nums.
// A subarray is a contiguous non-empty sequence of elements within an array.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int const MOD = 1000000007; //no need
        int n = nums.size();


        //first we are goig to find sum of min values
        stack<int> st1, st2;
        vector<int> PMV(n), NMV(n);
        long long sum_min = 0;
        //PMV Previous min value
        for(int i=0; i<nums.size(); i++){
            while(!st1.empty() && nums[i]<=nums[st1.top()]) st1.pop();
            PMV[i] = st1.empty() ? -1 : st1.top();
            st1.push(i);
        }
        //NMV Next Min Value
        for(int i=n-1; i>=0; i--){
            while(!st2.empty() && nums[i]<nums[st2.top()]) st2.pop();
            NMV[i] = st2.empty() ? n : st2.top();
            st2.push(i);
        }
        for(int i=0; i<n; i++){
            sum_min += 1LL * (i - PMV[i]) * (NMV[i] - i) * nums[i];
        }

        //here we aare going to find sum of max values
        vector<int> NGE(n), PGE(n);
        stack<int> st3, st4;
        long long sum_max = 0;
        //PGE Prevoius greater value
        for(int i=0; i<n; i++){
            while(!st3.empty() && nums[i]>=nums[st3.top()]) st3.pop();
            PGE[i] = st3.empty() ? -1 : st3.top();
            st3.push(i);
        }
        //NGE next greater value
        for(int i=n-1; i>=0; i--){
            while(!st4.empty() && nums[i]>nums[st4.top()]) st4.pop();
            NGE[i] = st4.empty() ? n : st4.top();
            st4.push(i);
        }
        for(int i=0; i<n; i++){
            sum_max += 1LL * (i - PGE[i]) * (NGE[i] - i) * nums[i];
        }

        //final answer
        return sum_max-sum_min;
    }
};