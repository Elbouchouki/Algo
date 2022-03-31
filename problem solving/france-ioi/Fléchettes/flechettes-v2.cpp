#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int nbLettres;
    cin >> nbLettres;
    char a = 'a';
    int len = nbLettres * 2 - 1;
    for (int i = 0; i < nbLettres; i++)
    {
        char aa = 'a';
        for (int j = 0; j < i; j++)
        {
            cout << aa++;
        }
        for (int j = 0; j < len - (i * 2); j++)
        {
            cout << a;
        }
        for (int j = 0; j < i; j++)
        {
            cout << --aa;
        }
        cout << "\n";
        a++;
    }
    --a;
    for (int i = nbLettres - 1; i > 0; i--)
    {
        --a;
        char aa = 'a';
        for (int j = 0; j < i; j++)
        {
            cout << aa++;
        }
        for (int j = 0; j < len - (i * 2); j++)
        {
            cout << a;
        }
        for (int j = 0; j < i; j++)
        {
            cout << --aa;
        }
        cout << "\n";
    }
}

int main()
{
    solve();
    return 0;
}