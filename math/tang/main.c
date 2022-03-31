#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

/* ------------------------------- taille max ------------------------------- */
#define NMAX 1000
#define PAS 0.5
#define PI atan(1) * 4
/* ------------------------------- definitions ------------------------------ */
double tan(double);
int calculeTable(double, double, double[], double[]);
void afficher(double[], double[], int);
/* ---------------------------------- main ---------------------------------- */
int main()
{
    double abs[NMAX], img[NMAX];
    double a = -PI / 2 + 0.1, b = PI / 2 - 0.1;
    int n = calculeTable(a, b, abs, img);
    afficher(abs, img, n);
    return 0;
}

double tan(double x)
{
    double x2 = x * x, x3 = x * x2, x5 = x3 * x2, x7 = x5 * x2;
    return x + (x3 / 3) + (2 * x5 / 15) + (17 * x7 / 315);
}
int calculeTable(double a, double b, double X[], double Y[])
{
    int i, n = (int)(fabs(b - a) / PAS + 1);
    assert(n <= NMAX); //pre-condition
    for (i = 0; i < n; ++i)
    {
        X[i] = a + i * PAS;
        Y[i] = tan(X[i]);
    }
    return n;
}
void afficher(double X[], double Y[], int n)
{
    int i;
    puts("X     Tan(X)");
    for (i = 0; i < n; i++)
    {
        printf("%10.3f   %10.3f\n", X[i], Y[i]);
    }
}