#include <bits/stdc++.h>
using namespace std;

int lonelyinteger(vector<int> a)
{
    int res = 0;
    for (size_t i = 0; i < a.size(); i++)
        res = res ^ a[i];
    return res;
}

int main()
{
    vector<int> input = {1, 2, 3, 4, 3, 2, 1};
    cout << lonelyinteger(input) << endl;
}