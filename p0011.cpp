// Container With Most Water

// You are given an integer array height of length n. 
// There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // O(n) time complexity and O(1) space complexity
    int maxArea(vector<int>& height) {
        int left = 0;
        int right  = height.size()-1;
        int maxarea =0;
        while(left<=right){
            int length = right-left;
            if(height[left]>height[right]){
                maxarea = max(maxarea,length*height[right]);
                right--;
            }
            else{
                maxarea = max(maxarea,length*height[left]);
                left++;
            }
        }
        return maxarea;
    }
};