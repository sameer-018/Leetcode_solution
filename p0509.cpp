#include <iostream>
using namespace std;

class Solution {
public:
    //time complexity O(n) space complexity O(1)
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int a=0, b=1,c;
        for(int i=0; i<n-1; i++){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }

    //time complexity O(2^n); spacecomplexity O(n)
    int fib(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        else return fib(n-1)+fib(n-2);
    }
};

