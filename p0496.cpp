// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. 
// If there is no next greater element, then the answer for this query is -1.
// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

//time complexity O(m+n) and space complexity O(n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        int temp;
        //vector<int> ans(nums1.size(), -1);
        for(int i=nums2.size()-1; i>-1; i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(!st.empty() && nums2[i]<st.top()){
                mp[nums2[i]] = i;
                temp = nums2[i];
                nums2[i] = st.top();
                st.push(temp);
            }
            else{ 
                mp[nums2[i]] = i;
                st.push(nums2[i]);
                nums2[i] = -1;
            }
        }
        for(int i=0; i<nums1.size(); i++){
            nums1[i] = nums2[mp[nums1[i]]];
        }
        return nums1;
    }
};