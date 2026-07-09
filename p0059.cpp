// SPIRAL MATRIX II
// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int sr,sc,er,ec;
        sr=0,sc=0;
        er=n-1,ec=n-1;
        int k=1;
        while(sc<=ec && sr<=er){
            //upperline
            for(int i=sc; i<=ec; i++){
                ans[sr][i]=k;
                k++;
            }

            //rightline
            for(int i=sr+1; i<=er; i++){
                ans[i][ec]=k;
                k++;
            }

            //lowerline
            for(int i=ec-1; i>=sc; i--){
                ans[er][i]=k;
                k++;
            }

            //leftline
            for(int i=er-1; i>sr; i--){
                ans[i][sc]=k;
                k++;
            }
            sr++;sc++;
            er--;ec--;
        }
        return ans;

    }
};

int main(){
    return 0;
}
