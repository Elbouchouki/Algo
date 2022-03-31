#include <bits/stdc++.h>
using namespace std;

int hourglassSum(vector<vector<int>> arr);
void printArray(vector<vector<int>> a);

int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i].resize(6);
        for (int j = 0; j < arr.size(); j++)
            cin >> arr[i][j];
    }
    cout << hourglassSum(arr) << endl;
}
int hourglassSum(vector<vector<int>> arr)
{
    int best = numeric_limits<int>::min();
    for (int i = 0; i < arr.size() - 2; i++)
    {
        for (int j = 0; j < arr.size() - 2; j++)
        {
            int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1] + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
            cout << sum << endl;
            if (sum > best)
                best = sum;
        }
    }
    return best;
}
void printArray(vector<vector<int>> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            if (j != 0)
                cout << ",";
            cout << a[i][j];
        }
        cout << endl;
    }
}