#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> nums;
        if(x<0) return false;
        else{
            while(x){
                nums.push_back(x%10);
                x /= 10;
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=nums[nums.size()-1-i]) return false;
        }
        return true;
    }
};