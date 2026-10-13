#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            if(i==0){
                ans.push_back({1});
                continue;
            }
            if(i==1){
                ans.push_back({1,1});
                continue;
            }
            vector<int> v1(i+1,1);
            for(int j=0; j<ans.back().size()-1; j++){
                v1[j+1] = ans.back()[j]+ans.back()[j+1];
            }
            ans.push_back(v1);
        }
        return ans;
    }
};