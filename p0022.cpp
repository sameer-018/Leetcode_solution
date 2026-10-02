#include<iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
vector<string> ans;
    void genpar(string cur, int ob, int cb, int n){
        if(cur.size()==2*n){
            ans.push_back(cur);
            return;
        }
        if(ob<n){
            cur.push_back('(');
            genpar(cur, ob+1, cb, n);
            cur.pop_back();
        }
        if(cb<ob){
            cur.push_back(')');
            genpar(cur, ob, cb+1, n);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        genpar("", 0, 0, n);
        return ans;
    }
};