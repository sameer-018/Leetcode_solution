#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intr) {
        sort(intr.begin(), intr.end(), [](vector<int> a, vector<int> b){ return a[1]<b[1]; });
        int meet=1;
        int freetime=intr[0][1];
        for(int i=1; i<intr.size(); i++){
            if(intr[i][0]>=freetime){
                meet++;
                freetime=intr[i][1];
            }
        }
        return intr.size()-meet;
    }
};