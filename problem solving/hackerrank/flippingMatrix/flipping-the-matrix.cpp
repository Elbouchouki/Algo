#include <bits/stdc++.h>
using namespace std;

int flippingMatrix(vector<vector<int>> matrix)
{
    int sum = 0;
    int n = matrix.size(), m = matrix[0].size();
    int cur, right, down, diag, ans;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < m / 2; j++)
        {
            cur = matrix[i][j];
            right = matrix[i][m - j - 1];
            down = matrix[n - i - 1][j];
            diag = matrix[n - i - 1][m - j - 1];
            ans = max({cur, right, down, diag});
            cout << cur << " " << right << " " << down << " " << diag << " " << endl;
            sum += ans;
        }
    }
    return sum;
}

int main()
{
    vector<vector<int>> input;
    vector<vector<int>> matrix = {{112, 42, 83, 119},
                                  {56, 125, 56, 49},
                                  {15, 78, 101, 43},
                                  {62, 98, 114, 108}};

    input.push_back({1, 2});
    input.push_back({3, 4});
    // cout << flippingMatrix(input) << endl;
    cout << flippingMatrix(matrix) << endl;

    return 0;
}