#include <bits/stdc++.h>
using namespace std;

void solve(int nbr)
{
    char c = 'a';
    int len = nbr * 2 - 1, step = 0;
    string chaine;
    for (int i = 0; i < len; i++)
        chaine.push_back(c);
    cout << chaine << endl;
    for (int i = 0; i < nbr - 1; i++)
    {
        step++;
        char current = c++;
        replace(chaine.begin() + step, chaine.end() - step, current, c);
        cout << chaine << endl;
    }
    for (int i = 0; i < nbr - 1; i++)
    {
        char current = c--;
        replace(chaine.begin(), chaine.end(), current, c);
        cout << chaine << endl;
    }
}

int main()
{
    int nbr_lettres;
    cin >> nbr_lettres;
    solve(nbr_lettres);
}