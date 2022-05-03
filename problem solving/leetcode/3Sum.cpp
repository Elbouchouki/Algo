#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  static vector<vector<int>> threeSum(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); i++)
    {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int l = i + 1, r = nums.size() - 1;
      while (l < r)
      {
        long long sum = nums[i] + nums[l] + nums[r];
        if (sum < 0)
          l++;
        else if (sum > 0)
          r--;
        else
        {

          res.push_back({nums[i], nums[l], nums[r]});
          l++;
          while (nums[l] == nums[l - 1] && l < r)
            l++;
        }
      }
    }
    return res;
  }
};

int main()
{
  vector<vector<int>> inputs = {{-1, 0, 1, 2, -1, -4}, {}, {0}};
  for (vector<int> in : inputs)
  {
    vector<vector<int>> res = Solution::threeSum(in);
    for (vector<int> single : res)
    {
      cout << "[";
      for (int i = 0; i < single.size(); i++)
      {
        cout << i;
        if (i != single.size() - 1)
          cout << ",";
      }
      cout << "]";
    }
    cout << "\n";
  }
  return 0;
}