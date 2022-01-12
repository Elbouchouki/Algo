#include <bits/stdc++.h>

using namespace std;

// void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges)
// {
//     int size_apples = apples.size();
//     int size_oranges = oranges.size();
//     int nbr_apples = 0, nbr_oranges = 0;
//     for (int i = 0; i < size_apples; i++)
//     {
//         apples[i] += a;
//         if (apples[i] >= s && apples[i] <= t)
//             nbr_apples++;
//     }
//     for (int i = 0; i < size_oranges; i++)
//     {
//         oranges[i] += b;
//         if (oranges[i] >= s && oranges[i] <= t)
//             nbr_oranges++;
//     }
//     cout << nbr_apples << endl;
//     cout << nbr_oranges << endl;
// }
void affiche(int **a)
{
    cout << (**a) << " " << (*a) << " " << a << " " << &a;
}
int main()
{
    int f = 5;
    int *g = &f;
    int **a = &g;

    affiche(a);
    // vector<int> apples = {2, 3, -4};
    // vector<int> oranges = {3, -2, -4};
    // int s = 7, t = 10, a = 4, b = 12;
    // countApplesAndOranges(s, t, a, b, apples, oranges);
    // int i = 0, n = 0, t[] = {1, 5, 8, 4, 6, 7, 44, 10, 20, 2};
    // while (true)
    // {
    //     cout << "n=" << n << " i= " << i << " T[i]= " << t[i] << " T[i+1]= " << t[i + 1] << endl;
    //     if (n == 5)
    //         break;
    //     n = n + 1;
    //     if (i > 9)
    //     {
    //         i = i - 4;
    //         cout << "n=" << n << " i= " << i << " T[i]= " << t[i] << " T[i+1]= " << t[i + 1] << endl;
    //     }
    //     if (i < 0)
    //     {
    //         i = i + 3;
    //         cout << "n=" << n << " i= " << i << " T[i]= " << t[i] << " T[i+1]= " << t[i + 1] << endl;
    //     }

    //     if (t[i] < t[i + 1])
    //     {
    //         i = i + 3;
    //         cout << "n=" << n << " i= " << i << " T[i]= " << t[i] << " T[i+1]= " << t[i + 1] << endl;
    //     }

    //     else
    //         i = i - 4;
    // }
    // cout << (0 < 0) << endl;
}
