#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int sr=0,er=matrix.size()-1,sc=0,ec=matrix[0].size()-1;
        vector<int> ans;
        while(sr<=er && sc<=ec){
            for(int i=sc; i<=ec; i++){
                ans.push_back(matrix[sr][i]);
            }
            for(int i=sr+1; i<=er; i++){
                ans.push_back(matrix[i][ec]);
            }
            for(int i=ec-1; i>=sc; i--){
                if(sr==er) break;
                ans.push_back(matrix[er][i]);
            }
            for(int i=er-1; i>sr; i--){
                if(sc==ec) break;
                ans.push_back(matrix[i][sc]);
            }
            sr++;sc++;er--;ec--;
        }
        return ans;
    }
};

int main(){
    return 0;
}