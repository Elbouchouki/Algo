#include <bits/stdc++.h>

using namespace std;
long long int findBestSum(long long int arr[], long long int n, long long int start)
{
    long long int sum = 0;
    int step = 1;
    for (int i = start; i < n && (n - i) >= step; i++, step++)
    {
        sum += arr[i];
    }
    return sum;
}
long long int solve(long long int arr[], long long int n)
{
    long long int bestSum = 0;
    for (int i = 0; i < n; i++)
    {
        long long int temp = findBestSum(arr, n, i);
        if (temp > bestSum || !bestSum)
            bestSum = temp;
    }
    return bestSum;
}

int main()
{
    long long int n;
    cin >> n;
    long long int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << solve(arr, n) << endl;

    return 0;
}
