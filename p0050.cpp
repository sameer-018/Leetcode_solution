// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(x==1) return 1;
        long N =n;
        if(n<0){
            x = 1/x;
            N = -N;
        }
        int rem;
        double ans = 1;
        while(N){
            rem = N%2;
            if(rem == 1){
                ans *= x;
            }
            x *= x;
            N /= 2;
        }
        return ans;
    }
};