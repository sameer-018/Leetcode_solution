#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int st = 0, end = 1;
        while(st<n && end<n){
            if(end<=st && st<n-1) end=st+1;
            if(nums[st]==0 && nums[end]!=0){
                swap(nums[st], nums[end]);
                st++; end++;
                continue;
            }
            if(nums[st]!=0){
                st++;
                continue;
            }
            if(nums[end]==0) end++;
        }
    }
};