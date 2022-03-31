#include <bits/stdc++.h>
using namespace std;

long long sum(long long n)
{
    long long ret = 0;
    while (n)
    {
        ret = ret + n % 16;
        n = n / 16;
    }
    return ret;
}

void solve()
{
    long long l, r, cpt = 0;
    cin >> l >> r;
    for (long long i = l; i <= r; i++)
    {

        if (__gcd(i, sum(i)) > 1)

            cpt++;
    }
    cout << cpt << endl;
}

int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        solve();
    }
    return 0;
}
