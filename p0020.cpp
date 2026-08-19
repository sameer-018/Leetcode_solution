// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2!=0) return false;
        stack<char> s1;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                s1.push(s[i]);
                continue;
            }
            if(s1.empty()){
                if(s[i]==')' || s[i]==']' || s[i]=='}') return false;
            }
            if(!s1.empty()){
                if(s[i]==')' && s1.top()=='('){
                    s1.pop();
                    continue;
                }
                if(s[i]==']' && s1.top()=='['){
                    s1.pop();
                    continue;
                }
                if(s[i]=='}' && s1.top()=='{'){
                    s1.pop();
                    continue;
                }
                else return false;
            }
        }
        if(s1.empty()) return true;
        return false;
    }
};