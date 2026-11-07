//Similar problem like MAX NUMBER OF PLATFORM REQUIRED
//You are given a 2D integer array intervals where intervals[i] = [lefti, righti] represents the inclusive interval [lefti, righti].
// You have to divide the intervals into one or more groups such that each interval is in exactly one group, 
// and no two intervals that are in the same group intersect each other.
// Return the minimum number of groups you need to make.
// Two intervals intersect if there is at least one common number between them. For example, the intervals [1, 5] and [5, 8] intersect.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        //creating two arrays to store time of arrival and departure 
        vector<int> arrival;
        vector<int> departure;
        for(auto val : intervals){
            arrival.push_back(val[0]);
            departure.push_back(val[1]);
        }
        //sorting these two arrays
        sort(arrival.begin(), arrival.end());
        sort(departure.begin(), departure.end());
        //creating each pointer for each array
        int i=0, j=0;
        //two variable to store engaged platform and maxrequired platform
        int platform=0;
        int maxplat=0;
        //traversing through the array of arrival
        while(i<arrival.size()){
            //if train arriving we need a platform
            if(arrival[i]<=departure[j]){
                i++;
                platform++;
            }
            //if train is departing the platform is getting free
            else{
                j++;
                platform--;
            }
            // updating the max required platforms
            maxplat = max(maxplat, platform);
        }
        return maxplat;
    }
};