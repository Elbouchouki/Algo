#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

void solve()
{
    int nbrLivres, nbrJours, nbrClients, livre, duree;
    cin >> nbrLivres >> nbrJours;
    vector<int> biblio(nbrLivres, 0);
    // int biblio[nbrLivres];
    // for (int i = 0; i < nbrLivres; i++)
    //     biblio[i] = 0;
    while (nbrJours--)
    {
        cin >> nbrClients;
        while (nbrClients--)
        {
            cin >> livre >> duree;
            if (biblio[livre] == 0)
            {
                biblio[livre] = duree;
                ans.push_back(1);
            }
            else
                ans.push_back(0);
        }

        for (int i = 0; i < nbrLivres; i++)
            if (biblio[i] != 0)
                biblio[i] -= 1;
    }
}

int main()
{
    solve();
    cout << endl;
    for (int i : ans)
    {
        cout << i << "\n";
    }
}