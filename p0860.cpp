#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> cash(3,0);
        for(int val : bills){
            if(val == 5){
                cash[0]++;
            }
            else if(val == 10){
                if(cash[0]>0){
                    cash[0]--;
                    cash[1]++;
                }
                else return false;
            }
            else{
                if(cash[1]>0 && cash[0]>0){
                    cash[1]--; cash[0]--;
                    cash[2]++;
                }
                else if(cash[0]>2){
                    cash[0] -= 3;
                    cash[2]++;
                }
                else return false;
            }
        }
        return true;
    }
};