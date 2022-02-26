#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 10;
    vector<int> arr(x, 0);
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 0; i < x; i++)
    {
        arr[i + 1] += arr[i];
        arr[i + 2] += arr[i];
    }
    for (int j : arr)
        cout << j << ' ';
}