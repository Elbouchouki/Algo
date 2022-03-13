#include <bits/stdc++.h>
using namespace std;

void miniMaxSum(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    long long int min = 0, max = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (i != 0)
            max += arr[i];
        if (i != arr.size() - 1)
            min += arr[i];
    }
    cout << min << " " << max;
}

int main()
{
    vector<int> input_1 = {1, 2, 3, 4, 5};
    miniMaxSum(input_1);
}