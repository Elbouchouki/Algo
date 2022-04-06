#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
           if(s.find(nums[i]) != s.end())return true;
           s.insert(nums[i]);
        }
        return false;
    }
};

int main(){

    Solution s;
    vector<int> input1 ={1,2,3,4,5};
    vector<int> input2 ={1,2,3,6,1};

    cout << s.containsDuplicate(input1) << endl;
    cout << s.containsDuplicate(input2) << endl;

}