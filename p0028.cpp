// Given two strings needle and haystack, 
// return the index of the first occurrence of needle in haystack, 
// or -1 if needle is not part of haystack.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //i just renamed needle to small , heystack to big just for ease of understanding 
    int strStr(string big, string small) {
        //using two pointer and sliding window 
        int i=0, j=0, k=0;
        //i and j for big string window and k for small
        int n=big.length(), m=small.length();
        if(m>n) return -1;

        // iterating over big string
        while(j<n && i<n){
            //if we match first element then we eill expand the window
            if(big[i]==small[0]){
                //expanding the window
                while(j<n && k<m){
                    if(big[j]==small[k]){
                        j++;
                        k++;
                    }
                    //if nay element miss match then start again from i++
                    else{
                        j=++i;
                        k=0;
                        break;
                    }
                }
                //return i if we successfully iterated over small
                if(k==m) return i;
            }
            //moving i,j further if no first element match
            else{
                i++; j++;
            }
        }
        return -1;
    }
};