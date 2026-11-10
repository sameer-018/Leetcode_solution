// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

//by observing problem we notice that it is just febonacci sequence as nth term
//timeComplexity O(n) sapceComplexity O(1)
class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int a=1, b=2;
        int i=2;
        while(i<n){
            int temp = b;
            b = b+a;
            a = temp;
            i++;
        }
        return b;
    }
};