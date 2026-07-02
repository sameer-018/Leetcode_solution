#include <iostream>
#include <vector>
using namespace std;

class Solutions{
    public:
        bool searchMatrix(vector<vector<int>> &matrix, int target){
            int row = matrix.size();
            int col = matrix[0].size();
            //to search that element we start from a off diagonal extreme point to another
            //cause if we are at extreme point diagonal we have only two ways to move and answer will be in one that way
            //so we can eleminate other way elements

            //im start searching from matrix[0][col-1] to matrix[row-1][0]
            int r=0,c=col-1;
            while(r<row && c>=0){
                if(matrix[r][c]==target) return true;
                else if(matrix[r][c]>target) c--;
                else r++;
            }
            return false;
        }
};
int main(){
    return 0;
}
