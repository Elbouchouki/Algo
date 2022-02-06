#include <bits/stdc++.h>
using namespace std;
void printValues(vector<double> &mesures);
bool isMinimale(vector<double> &mesures, double diffMax);
void lissage(vector<double> &mesures);
void solve();
int main()
{
    solve();
}

void solve()
{
    int nbMesures;
    double diffMax;
    cin >> nbMesures;
    cin >> diffMax;
    vector<double> mesures(nbMesures);
    for (int i = 0; i < mesures.size(); i++)
        cin >> mesures[i];
    int cpt = 0;
    // cout << "\n"
    //      << "Avant";
    // printValues(mesures);
    while (!isMinimale(mesures, diffMax))
    {
        lissage(mesures);
        // cout << "Apres " << cpt + 1 << " passage(s): ";
        // printValues(mesures);
        cpt++;
    }
    cout << cpt << "\n";
}

void lissage(vector<double> &mesures)
{
    vector<double> newMesures(mesures.size());
    newMesures[0] = mesures[0];
    newMesures[mesures.size() - 1] = mesures[mesures.size() - 1];
    for (int i = 1; i < mesures.size() - 1; i++)
        newMesures[i] = (mesures[i - 1] + mesures[i + 1]) / 2;
    mesures = newMesures;
}

bool isMinimale(vector<double> &mesures, double diffMax)
{
    for (int i = 0; i < mesures.size() - 1; i++)
        if (abs(mesures[i] - mesures[i + 1]) > diffMax)
            return false;
    return true;
}

void printValues(vector<double> &mesures)
{
    for (int i = 0; i < mesures.size(); i++)
        cout << mesures[i] << " ";
    cout << "\n";
}