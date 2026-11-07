#include <bits/stdc++.h>
using namespace std;

// Given an integer n, return true if it is a power of two. Otherwise, return false.


class Solution {
public:
    //O(logn) solution
     bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }

        while (n % 2 == 0) {
            n = n / 2;
        }

        return n == 1;
    }

    //O(1) solution
    bool isPowerOfTwo(int n) {
    return n>0 && (n&(n-1))==0;// for evry 2^n number its previous numbers bitwise and is zero
    }
};