#include <bits/stdc++.h>
using namespace std;

int lonelyinteger(vector<int> a)
{
    set<int> ss;
    int ret;
    for (size_t i = 0; i < a.size(); i++)
    {
        if (ss.find(a[i]) == ss.end())
        {
            ss.insert(a[i]);
            ret = a[i];
        }
    }
    return ret;
}

int main()
{
    vector<int> input = {1, 2, 3, 4, 3, 2, 1};
    cout << lonelyinteger(input) << endl;
}