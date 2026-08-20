// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:
// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int op1, op2, ans;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();
                if(tokens[i]=="+") ans = op1+op2;
                else if(tokens[i]=="-") ans = op1-op2;
                else if(tokens[i]=="*") ans = op1*op2;
                else ans = op1/op2;
                st.push(ans);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
