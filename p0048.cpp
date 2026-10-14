#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n/2; i++){
            queue<int> q1;
            queue<int> q2;
            queue<int> q3;
            queue<int> q4;

            for(int k=i; k<n-i; k++){
                q1.push(matrix[i][k]);
                q2.push(matrix[k][n-1-i]);
                q3.push(matrix[n-1-i][n-1-k]);
                q4.push(matrix[n-1-k][i]);
            }

            for(int k=i; k<n-i; k++){
                matrix[i][k] = q4.front();
                matrix[k][n-1-i] = q1.front();
                matrix[n-1-i][n-1-k] = q2.front();
                matrix[n-1-k][i] = q3.front();
                q1.pop(); q2.pop(); q3.pop(); q4.pop();
            }
        }
    }
};