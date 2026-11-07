//Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
// and return an array of the non-overlapping intervals that cover all the intervals in the input.

//Timeomplexity O(nlogn), SpaceComplexity O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intr) {
        //creating ans 2d array for storing merged intervals
        vector<vector<int>> ans;
        //sorting intervals to easily compare with others
        sort(intr.begin(), intr.end());
        //two pointer/ sliding window approach to get all overlapping intervals
        //setting both pointers at start
        int i=0, j=0;
        int n=intr.size();
        //iterating over interval O(n)
        while(j<n && i<n){
            //our lower bound is intr[i][0] and it wont change cause array is sorted
            //but upper bound may change so we will store it and keep updating
            int upperbound = intr[i][1];
            // increasing window of overlapping intervels
            while(j+1<n && upperbound>=intr[j+1][0]){
                j++;
                //updating the upper bound
                upperbound = max(upperbound, intr[j][1]);
            }
            //inserting window
            ans.push_back({intr[i][0], upperbound});
            //setting pointers after ward
            i = ++j;
        }
        return ans;
    }
};