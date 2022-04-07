#include <bits/stdc++.h>
using namespace std;
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

int one_nth_pow(int n){
    if(n==0) return 1;
    return (n%2 == 0) ? 1 : -1;
}  

void solve()
{
    int degree;
    cin >> degree;
    int coeffs[degree];
    long long int beauty(0);
    long long int root_cumul(1);
    for(int i=0;i<degree;i++) {
        cin >> coeffs[i];
        int curr_root = ((one_nth_pow(i+1)*coeffs[i])/ root_cumul);
        root_cumul *= curr_root;
        beauty += (coeffs[i]*coeffs[i]) - (curr_root*curr_root);
    }
    cout << beauty;
}