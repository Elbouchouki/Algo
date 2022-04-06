#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0 ; i<nums.size() ; i++){
            if( m.find(target - nums[i]) != m.end() ){
                return vector<int>({m[target - nums[i]],i});
            }
            m[nums[i]]=i;
        }
        return {};
    }
};

int main(){
    vector<int> nums ({2,7,11,15});
    int target(9);
    vector<int> result = Solution::twoSum(nums,target);
    cout << result[0] << " " << result[1] <<endl;
    nums = {3,2,4};
    target = 6;
    result = Solution::twoSum(nums,target);
    cout << result[0] << " " << result[1] <<endl;
    nums = {3,3};
    target = 6;
    result = Solution::twoSum(nums,target);
    cout << result[0] << " " << result[1] <<endl;
}