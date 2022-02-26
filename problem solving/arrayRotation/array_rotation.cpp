
#include <bits/stdc++.h>

using namespace std;

void rotate(long long arr[], long long arrd[], long long n, long long k)
{
    k = k % n;
    long long j = 0;
    for (long long i = n - k; i < n; i++)
        arr[j++] = arrd[i];
    for (long long i = 0; i < n - k; i++)
        arr[j++] = arrd[i];
}

int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        long long k, n, i, j = 0, x, temp;
        cin >> n >> k;
        long long arr[n], arrd[n];
        for (long long i = 0; i < n; i++)
        {
            cin >> arr[i];
            arrd[i] = arr[i];
        }
        rotate(arr, arrd, n, k);
        for (long long i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
