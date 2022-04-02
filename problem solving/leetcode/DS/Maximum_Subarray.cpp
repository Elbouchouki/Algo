#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int maxSubArray(vector<int>& nums){
        int max_sum = INT16_MIN;
        map<int,int> s;
        for(int i=0;i<nums.size();i++){

            if(s.find(i-1)==s.end()){
                s.insert({i,nums[i]});
            }else{
                int temp = nums[i] > (s[i-1]+nums[i]) ? nums[i] : s[i-1] + nums[i];
                s.insert({i,temp});
            }
            if( s[i]  > max_sum ) max_sum = s[i];
        }
        return max_sum;
    }
    static int maxSubArray_optimization(vector<int>& nums){
        int curr = nums[0];
        int result = nums[0];
        for(int i=1 ; i < nums.size() ; i++){
            // curr  = curr + nums[i] >nums[i]  ? curr + nums[i] : nums[i];
            curr = max(curr + nums[i], nums[i]);
            // result = result > curr ? result : curr;
            result = max(result, curr);
        }
        return result;
    }
};

int main(){
    vector<int> input = {-2,1,-3,4,-1,2,1,-5,4} ;
    cout << Solution::maxSubArray_optimization(input) << endl;
}