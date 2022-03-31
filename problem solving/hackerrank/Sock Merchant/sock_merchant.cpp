#include <bits/stdc++.h>
using namespace std;

int sockMerchant(int n, vector<int> ar);
void solve();

int main()
{
    // int x = 9;
    // int *p = &x;
    // int **q = &p;

    // cout << x << endl;
    // cout << *p << endl;
    // cout << **q << endl;
    // cout << p << endl;
    // cout << &x << endl;
    // cout << *q << endl;

    // **q = 5;
    // cout << x << endl;
    // cout << *p << endl;
    // cout << **q << endl;
    int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < n; i++)
    {
        cout << x + i << " " << *(x + i) << endl;
    }
    // solve();
}

void solve()
{
    vector<int> input = {10, 20, 20, 10, 10, 30, 50, 10, 20};
    vector<int> input2 = {1, 1, 3, 1, 2, 1, 3, 3, 3, 3};

    int n = 9;
    int n2 = 10;
    cout << sockMerchant(n, input) << endl;
    cout << sockMerchant(n2, input2) << endl;
}

int sockMerchant(int n, vector<int> ar)
{
    map<int, int> state;
    map<int, int>::iterator it;
    int result = 0;
    for (int x : ar)
    {
        map<int, int>::iterator it = state.find(x);

        if (it != state.end())
        {
            it->second++;
        }
        else
            state.insert({x, 1});
    }
    for (auto const &x : state)
    {
        result += x.second / 2;
    }
    return result;
}