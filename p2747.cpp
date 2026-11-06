#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m=logs.size();
       sort(logs.begin(), logs.end(), [](vector<int> a, vector<int> b){ return a[1]<b[1]; });

       vector<int> ans(queries.size());
       vector<pair<int, int>> timeIndex;
       for(int i=0; i<queries.size(); i++) timeIndex.push_back({queries[i], i});
       sort(timeIndex.begin(), timeIndex.end());

       unordered_map<int, int> mp;
       int i=0, j=0;
       for(auto p : timeIndex){
        int start = p.first-x;
        int end = p.first;

        while(j<m && logs[j][1]<=end){
            mp[logs[j][0]]++;
            j++;
        }
        while(i<m && logs[i][1]<start){
            mp[logs[i][0]]--;
            if(mp[logs[i][0]]==0){
                mp.erase(logs[i][0]);
            }
            i++;
        }
        ans[p.second]=n-mp.size();
       }
       return ans;
    }
};