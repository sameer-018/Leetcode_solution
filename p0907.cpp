// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
// Since the answer may be large, return the answer modulo 109 + 7.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1000000007;
        int n = arr.size(); long long ans = 0;
        //two vector storing INdex of PREVIOUS/NEXT min value
        vector<int> PMV(n, -1), NMV(n, n);
        stack<int> st1, st2;
        for(int i=0; i<n; i++){
            while(!st1.empty() && arr[i]<=arr[st1.top()]) st1.pop();
            PMV[i] = (!st1.empty()) ? st1.top() : -1;
            st1.push(i);
        }
        for(int i=n-1; i>-1; i--){
            while(!st2.empty() && arr[i]<arr[st2.top()]) st2.pop();
            NMV[i] = (st2.empty()) ? n : st2.top();
            st2.push(i); 
        }
        for(int i=0; i<n; i++){
            ans = (1LL*arr[i]*(NMV[i]-i)*(i-PMV[i]) + ans)%MOD;
        }
        return ans;
    }
};