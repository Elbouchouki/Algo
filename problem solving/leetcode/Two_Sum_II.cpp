#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    static vector<int> twoSum(vector<int> &numbers, int target)
    {
        int low = 0;
        int high = numbers.size() - 1;
        while (low < high)
        {
            if (numbers[low] + numbers[high] == target)
                break;
            if (numbers[low] + numbers[high] < target)
            {
                low++;
                continue;
            }
            high--;
        }
        return {low + 1, high + 1};
    }
};

int32_t main()
{

    vector<int> input_1 = {5, 25, 75};
    vector<int> res_1 = Solution::twoSum(input_1, 100);
    for (auto x : res_1)
        cout << x << " ";
    cout << "\n";
    return 0;
}