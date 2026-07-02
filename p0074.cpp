//search in 2D array
// You are given an m x n integer matrix matrix with the following two properties:
// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.
// You must write a solution in O(log(m * n)) time complexity.

 
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size()-1;
        int col=matrix[0].size()-1;
        int targetrow;
        int st=0,end=row;
        int mid;
        while(st<=end){
            mid=st+(end-st)/2;
            if(matrix[mid][0]<=target && target<=matrix[mid][col]){
                targetrow=mid;
                break;
            }
            else if(matrix[mid][0]>target) end=mid-1;
            else st=mid+1;
        }
        if(st>end) return false;
        st=0,end=col;
        while(st<=end){
            mid=st+(end-st)/2;
            if(matrix[targetrow][mid]==target) return true;
            else if(matrix[targetrow][mid]>target) end=mid-1;
            else st=mid+1;
        }
        return false;
    }
};

int main(){
    return 0;
}