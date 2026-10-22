#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        unordered_set<int> st;
        for(int val : nums){
            st.insert(val);
        }
        int longest = 1;
        for(int val : st){
            if(st.find(val-1) == st.end()){
                int cnt = 1;
                int el = val;
                while(st.find(el+1) != st.end()){
                    cnt++;
                    el++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};