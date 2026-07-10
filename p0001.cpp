// this is first problem of leetcode TWO SUM
//Problem:
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//this solution will have O(n^2) time complexity
class Solution{
    public:
        vector<int> twosum(vector<int> &nums, int target){
            for(int i=0; i<nums.size(); i++){
                for(int j=0; j<nums.size(); j++){
                    if(nums[i]+nums[j]==target && i!=j){
                        return {i,j};
                    }
                }
            }
            return {0,1};
        }
};

//this solution will have O(n) time complexity;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; //map key as subs and value as index
        int subs;
        for(int i=0; i<nums.size(); i++){
            subs = target-nums[i];
            if(mp.find(subs) != mp.end()){
                return {mp[subs],i};
            }
            mp[nums[i]]=i;
        }

        return{0,1};
    }
};

int main(){

    return 0;
}