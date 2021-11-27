
#include <bits/stdc++.h>
using namespace std;

void deplacer(char D, char A)
{
    cout << "Tirez " << D << " vers " << A << endl;
}

void solve(int n, char D, char A, char I, long long int *cpt)
{
    *cpt += 1;
    if (n == 1)
        ;
    // deplacer(D, A);

    // deplacer(D,A)
    else
    {
        // D à A
        solve(n - 1, D, I, A, cpt);
        // deplacer(D, A);
        //I à A
        solve(n - 1, I, A, D, cpt);
    }
}

void solve2(int n, int src, int dest, long long int *cpt)
{
    if (n > 0)
    {
        *cpt += 1;

        // D à A
        solve2(n - 1, src, 6 - src - dest, cpt);
        // deplacer1(src, dest);
        //I à A
        solve2(n - 1, 6 - src - dest, dest, cpt);
    }
}
double T(long long int cpt)
{
    return (double)cpt * 60 / 1.e9;
}
double T_byDisc(int disque)
{
    return (pow(2, disque) - 1) * 60 / 1.e9;
}
int main()
{
    int nDisques = 3;
    long long int cpt = 0;
    solve(nDisques, 'D', 'B', 'I', &cpt);
    cout << "steps : " << cpt << endl;
    cout << "temps : " << T(cpt) << " sec" << endl;

    long long int cpt2 = 0;
    solve2(nDisques, 1, 2, &cpt2);
    cout << "steps : " << cpt2 << endl;
    cout << "temps : " << T(cpt2) << " sec" << endl;

    cout << "-->" << T_byDisc(nDisques) << endl;
}