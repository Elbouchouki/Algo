#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int countOdds(int low, int high) {
        int res = 0;
        if(low % 2 != 0){
             res++;
        }else if(high % 2 != 0) res++;
        res+= ((high-low)/2);
        return res;
    }
    static int countOdds_optimized(int low, int high) {
        if(low % 2 == 0) low++;
        if(high % 2 == 0) high--;
        return ((high-low)/2)+1;
    }
};

int main(){
    cout << Solution::countOdds_optimized(3,7) << endl;
    cout << Solution::countOdds_optimized(8,10) << endl;
    cout << Solution::countOdds_optimized(21,22) << endl;
    cout << Solution::countOdds_optimized(14,17) << endl;

}