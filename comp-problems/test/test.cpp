#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<long> freq = {3,
                         5,
                         4,
                         3};
    long sum = 0;
    for (long x : freq)
    {
        sum += x;
    }
    cout << sum << endl;
    cout << sum / 2;
}
