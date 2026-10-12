#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        if(n==1) return;
        k = k%n;
        vector<int> v1;
        for(int i=n-k; i<n; i++){
            v1.push_back(nums[i]);
        }
        for(int i=0; i<n-k; i++){
            v1.push_back(nums[i]);
        }
        for(int i=0; i<n; i++){
            nums[i]=v1[i];
        }
    }
};