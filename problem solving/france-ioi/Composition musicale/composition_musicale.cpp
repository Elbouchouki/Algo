#include <bits/stdc++.h>

using namespace std;

void solve();
bool has_double(string *m);

int main()
{
    solve();
}

// baaabbacddc

void solve()
{
    string morceau;
    cin >> morceau;
    while (has_double(&morceau))
        ;
    cout << morceau << endl;
}
bool has_double(string *m)
{
    for (int i = (*m).size(); i > 0; i--)
    {
        if ((*m)[i] == (*m)[i - 1])
        {
            (*m).erase(i - 1, 2);
            return true;
        }
    }
    return false;
}