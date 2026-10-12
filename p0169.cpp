#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0;
        int key;
        for(int i=0; i<nums.size(); i++){
            if(freq==0) key=nums[i];
            if(key==nums[i]) freq++;
            else freq--;
        }
        return key;
    }
};