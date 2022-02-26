#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test_case;
    // vector<long long> result;
    cin >> test_case;
    while (test_case--)
    {
        long long n, i, j, x;
        cin >> n;
        long long arr[j];
        for (j = 0; j < n; ++j)
            cin >> arr[j];
        long long min = (arr[0] & arr[1]) ^ (arr[0] | arr[1]);
        for (i = 1, j = i + 1; i < n - 1; i++, j++)
        {
            x = (i & j) ^ (i | j);
            if (x < min)
                min = x;
        }
        cout << min << endl;
    }
    // for (long long i : result)
    //     cout << i << endl;
    return 0;
}