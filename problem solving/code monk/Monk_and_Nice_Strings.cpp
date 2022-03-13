#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, j;
    multiset<string> se;
    multiset<string>::iterator it;
    cin >> n;
    string s;
    int k;
    for (i = 0; i < n; ++i)
    {
        cin >> s;
        k = 0;
        for (it = se.begin(); it != se.end(); ++it)
        {
            k += (*it < s);
        }
        cout << k << endl;
        se.insert(s);
    }
    return 0;
}