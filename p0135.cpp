// There are n children standing in a line.
// Each child is assigned a rating value given in the integer array ratings.
// You are giving candies to these children subjected to the following requirements:
// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies to the children.

#include <bits/stdc++.h>
using namespace std;

//timecomplexity O(n), spacecomplexityO(2n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        //getting size of rating inside n
        int n = ratings.size();
        //creating two vwctors to store next and prev greater element and store candy according it
        vector<int> prev(n,1), next(n,1);
        //initialising candy with one cause each extreme element will have atleast one
        int candy = 1;
        //checking strictly greater and increment candy otherwise just again 1
        for(int i=1; i<n; i++){
            candy = (ratings[i-1]<ratings[i]) ? candy+1 : 1;
            prev[i] = candy;
        }
        //same goes for next one
        candy = 1;
        for(int i=n-2; i>=0; i--){
            candy = (ratings[i]>ratings[i+1]) ? candy+1 : 1;
            next[i] = candy;
        }
        // adding total number of candies in sum as getting max of next,prev caue it will satiesfy both
        int sum =0;
        for(int i=0; i<n; i++) sum += max(prev[i], next[i]);
        return sum;
    }
};