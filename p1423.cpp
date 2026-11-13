
// There are several cards arranged in a row, and each card has an associated number of points. 
// The points are given in the integer array cardPoints.
// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
// Your score is the sum of the points of the cards you have taken.
// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

#include <bits/stdc++.h>
using namespace std;

//time complexity O(k)
 class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum =0;
        int i, j=cardPoints.size()-1;
        //first we take sum of all starting cards 
        for(i=0; i<k; i++) sum += cardPoints[i];
        //if cards size is same as the whole array size we will return it
        if(k==j+1) return sum;
        //keep track of max points
        int maxpoints = sum;
        //now removing cards from starting end and adding from end of array
        while(i>0 && j>=0){
            sum -= cardPoints[--i];
            sum += cardPoints[j--];
            //updating max
            maxpoints = max(maxpoints, sum);
        }
        return maxpoints;
    }
};