// Given n non-negative integers representing an elevation map where the width of each bar is 1, 
// compute how much water it can trap after raining.

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// timecomplexity O(3n) space complexity O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int max = height[0];
        int ans = 0, min_height;
        vector<int> leftmax(n,-1);
        vector<int> rightmax(n, -1);

        for(int i=1; i<n; i++){
            if(max<=height[i]) max = height[i];
            else leftmax[i] = max;
        }

        max = height[n-1];
        for(int i=n-2; i>-1; i--){
            if(max<=height[i]) max = height[i];
            else rightmax[i] = max;
        }
        for(int i=0; i<height.size(); i++){
            if(height[i]<leftmax[i] && height[i]<rightmax[i]){
                min_height = min(leftmax[i], rightmax[i]);
                ans += (min_height-height[i]);
            }
        }
        return ans;
    }
};

// timecomplexity O(n) spacecomplexity O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int i=0, j=n-1;
        int L=height[i], R=height[j];
        while(i<j){
            if(L<height[i]) L=height[i];
            if(R<height[j]) R=height[j];
            if(height[i]<height[j]){
                if(L>height[i] && R>height[i]) ans += min(L, R)-height[i];
                i++;
            }
            else{
                if(L>height[j] && R>height[j]) ans += min(L, R)-height[j];
                j--;
            }
        }
        return ans;
    }
};