// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:
// MinStack() initializes the stack object.
// void push(int value) pushes the element value onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

#include <iostream>
#include <stack>
#include <utility>
using namespace std;

//there are two ways to do it using two stack(st1(element),st2(min))/two array... two array is the fastest way
class MinStack {
public:
    stack<pair<int,int>> st1;
    int min_value;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st1.empty()){
            st1.push({value,value});
            min_value = value;
            return;
        }
        min_value = min(st1.top().second,value);
        st1.push({value,min_value});
    }
    
    void pop() {
        st1.pop();
    }
    
    int top() {
        return st1.top().first;
    }
    
    int getMin() {
        return st1.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */