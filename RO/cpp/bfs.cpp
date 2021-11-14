// x1 = a = index 0
// x2 = b = index 1
// x3 = c = index 2
// x4 = d = index 3
// x5 = e = index 4
// x6 = f = index 5
// x7 = g = index 6
// x8 = h = index 7
// x9 = i = index 8
#include <bits/stdc++.h>
using namespace std;

char convert_index_to_sommet(int index);

// n sommets
#define N 9

#define a 0
#define b 1
#define c 2
#define d 3
#define e 4
#define f 5
#define g 6
#define h 7
#define i 8

#define BLANC 1
#define GRIS 0
#define NOIR -1

#define null -1

int main()
{
    vector<vector<int>> graphe;
    int pere[N];
    int couleur[N];
    int distance[N];
    vector<int> file;
    // choisir la racine
    int racine = c;
    // remplissage du graphe
    graphe.push_back({b, g});
    graphe.push_back({a, c, e, g});
    graphe.push_back({b, d, f});
    graphe.push_back({c});
    graphe.push_back({b, f, h});
    graphe.push_back({c, e, i});
    graphe.push_back({a, b, h});
    graphe.push_back({g, e, i});
    graphe.push_back({f, h});
    // initialisations
    for (int sommet = 0; sommet < graphe.size(); ++sommet)
    {
        pere[sommet] = null;
        distance[sommet] = N;
        couleur[sommet] = BLANC;
    }
    distance[racine] = 0;
    file.push_back(racine);
    while (file.size())
    {
        int sommet_courant = file[0];
        for (int sommet_voisin : graphe[sommet_courant])
        {
            if (couleur[sommet_voisin] == BLANC)
            {
                couleur[sommet_voisin] = GRIS;
                distance[sommet_voisin] = distance[sommet_courant] + 1;
                pere[sommet_voisin] = sommet_courant;
                file.push_back(sommet_voisin);
            }
        }
        couleur[sommet_courant] = NOIR;
        file.erase(file.begin());
    }

    // affichage
    for (int cpt = 0; cpt < N; ++cpt)
    {
        cout << convert_index_to_sommet(cpt) << " : " << convert_index_to_sommet(pere[cpt]) << " | " << distance[cpt] << endl;
    }
}

char convert_index_to_sommet(int index)
{
    switch (index)
    {
    case 0:
        return 'a';
    case 1:
        return 'b';
    case 2:
        return 'c';
    case 3:
        return 'd';
    case 4:
        return 'e';
    case 5:
        return 'f';
    case 6:
        return 'g';
    case 7:
        return 'h';
    case 8:
        return 'i';
    default:
        return 'N';
    }
}
