
/* --------------------------- 17/20 test cases -------------------------- */
#include <bits/stdc++.h>

using namespace std;

void solve();
void tourCheck(vector<int> *game, vector<int> *top, int nbGrenouilles);

int main()
{
    solve();
    return 0;
}

void solve()
{
    int nbTours, nbGrenouilles;
    cin >> nbGrenouilles >> nbTours;
    vector<int> game(nbGrenouilles, 0);
    vector<int> top(nbGrenouilles, 0);
    int grenouilles, tour;
    for (int i = 0; i < nbTours; i++)
    {
        tourCheck(&game, &top, nbGrenouilles);
        cin >> grenouilles >> tour;
        game[grenouilles - 1] += tour;
    }
    int winner = 0;
    for (int i = 1; i < nbGrenouilles; i++)
    {
        if (top[i] > top[winner])
        {
            winner = i;
        }
    }
    cout << winner + 1 << endl;
}

void tourCheck(vector<int> *game, vector<int> *top, int nbGrenouilles)
{
    int top_tour = 0;
    for (int i = 1; i < nbGrenouilles; i++)
    {
        if ((*game)[i] > (*game)[top_tour])
            top_tour = i;
    }
    if ((*game)[top_tour] != 0)
        (*top)[top_tour] += 1;
}