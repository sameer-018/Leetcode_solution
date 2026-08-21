// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
// return the next greater number for every element in nums.
// The next greater number of a number x is the first greater number to its traversing-order next in the array, 
// which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//space complexity O(n) timecomplexity O(2n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int temp;
        int n = nums.size();
        for(int i=2*n-1; i>-1; i--){
            while(!st.empty() && nums[i%n]>=st.top()) st.pop();
            temp = nums[i%n];
            if(i<n){
                nums[i] = st.empty() ? -1 : st.top();
            }
            st.push(temp);
        }
        return nums;
    }
};