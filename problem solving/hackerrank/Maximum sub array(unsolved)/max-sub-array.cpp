#include <bits\stdc++.h>
using namespace std;
long maxSubSum(vector<int> arr)
{
    int sign = 1;
    long sum, msum;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0)
        {
            if (arr[i] < 0)
                sign = -1;
            else
                sign = 1;
            sum = abs(arr[i]);
            msum = sum;
        }
        else
        {
            if (max(sum + (arr[i]), (long)arr[i]) < 0)
                sign = -1;
            else
                sign = 1;
            sum = max(sum + abs(arr[i]), (long)arr[i]);
            msum = max(sum, msum);
        }
    }
    cout << msum << endl;
    return sign * msum;
}
long maxSubarrayValue(vector<int> arr)
{
    vector<int> even;
    vector<int> odd;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 2 == 0 || arr[i] == 1)
            even.push_back(arr[i]);
        else
            odd.push_back(arr[i]);
    }
    for (int i = 0; i < even.size(); i++)
        cout << even[i] << " ";
    cout << endl;
    for (int i = 0; i < odd.size(); i++)
        cout << odd[i] << " ";
    cout << endl;

    long even_sum = maxSubSum(even);
    long odd_sum = maxSubSum(odd);
    long rt = even_sum - odd_sum;
    cout << even_sum << " " << odd_sum << endl;
    return rt * rt;
}

int main()
{
    vector<int> arr = {1, -1, 1, -1, 1};
    vector<int> arr2 = {-1, 2, 3, 4, -5};

    cout << maxSubarrayValue(arr) << endl;
    cout << endl
         << endl;

    cout << maxSubarrayValue(arr2) << endl;

    return 0;
}