// you are given two integers n and t. Return the smallest number greater than or equal to n such that 
// the product of its digits is divisible by t.

#include <iostream>
using namespace std;

class Solution {
public:
    int product(int num){
        int product = 1, rem;
        while(num){
            rem = num%10;
            product *= rem;
            num /= 10;
        }
        return product;
    }
    
    int smallestNumber(int n, int t) {
        while(true){
            if(product(n)%t == 0){
                return n;
            }
            else n += 1;
        }
        return n;
    }
};