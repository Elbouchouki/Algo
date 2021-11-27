#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test_case, n;
    vector<int> results;
    cin >> test_case;
    while (test_case--)
    {
        cin >> n;
        int matrice[n][n], cpt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> matrice[i][j];

        for (int x1 = 0; x1 < n; ++x1)
            for (int y1 = 0; y1 < n; ++y1)
                for (int x2 = x1; x2 < n; ++x2)
                    for (int y2 = y1; y2 < n; ++y2)
                        if (matrice[x1][y1] > matrice[x2][y2])
                            cpt++;

        results.push_back(cpt);
    }
    for (int x : results)
        cout << x << endl;
    return 0;
}
