//minimum moves to equal array element
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxnum = nums[0];
        for(int k : nums) maxnum = max(maxnum, k);
        int step=0;
        for(int k : nums) step += maxnum-k;
        return step;
    }
};