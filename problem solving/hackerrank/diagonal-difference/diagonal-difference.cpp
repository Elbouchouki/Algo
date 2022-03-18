#include <bits/stdc++.h>
using namespace std;

int diagonalDifference(vector<vector<int>> arr)
{
    int left = 0, right = 0;
    for (int i = 0, j = arr.size() - 1; i < arr.size(); i++, j--)
    {
        left += arr[i][i];
        right += arr[i][j];
    }
    return abs(left - right);
}

int main()
{
    vector<vector<int>> input;
    input.push_back({11, 2, 4});
    input.push_back({4, 5, 6});
    input.push_back({10, 8, -12});
    cout << diagonalDifference(input) << endl;
}