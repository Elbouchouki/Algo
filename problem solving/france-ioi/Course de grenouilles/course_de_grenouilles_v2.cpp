#include <bits/stdc++.h>

using namespace std;
void solve();
void tour(vector<int> &course);
int tourWinner(vector<int> &course);
int courserWinner(vector<int> &tours);

int main()
{
    solve();
    return 0;
}

void solve()
{
    int nbGrenouilles, nbTours;
    cin >> nbGrenouilles >> nbTours;
    vector<int> course(nbGrenouilles, 0);
    vector<int> tours(nbGrenouilles, 0);
    while (nbTours--)
    {
        tour(course);
        tours[tourWinner(course)]++;
    }
    cout << courserWinner(tours);
}

void tour(vector<int> &course)
{
    int grenouille, distance;
    cin >> grenouille >> distance;
    course[grenouille - 1] += distance;
}
int courserWinner(vector<int> &tours)
{
    int winner = 0;
    for (int i = 1; i < tours.size(); i++)
        if (tours[i] >= tours[winner])
            if (tours[i] > tours[winner])
                winner = i;
            else if (winner > i)
                winner = i;
    return winner + 1;
}
int tourWinner(vector<int> &course)
{
    int winner = 0;
    for (int i = 1; i < course.size(); i++)
        if (course[i] >= course[winner])
            if (course[i] > course[winner])
                winner = i;
            else if (winner > i)
                winner = i;
    return winner;
}
