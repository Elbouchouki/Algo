#include <stdlib.h>
#include <stdio.h>
#include "matrice.h"
matrice_t creerMatrice(int n)
{
    matrice_t m;
    int i;
    m.n = n;
    m.vals = (double **)malloc(sizeof(double *) * n);
    for (i = 0; i < n; i++)
        m.vals[i] = (double *)calloc(sizeof(double), n);
    // calloc pour initialiser la mémoire dynamique créée à zero
    return m;
}
void scanMatrice(matrice_t mat)
{
    double *p, **q;
    for (q = mat.vals; q < mat.vals + mat.n; q++)
        for (p = *q; p < *q + mat.n; p++)
        {
            printf("[%d][%d]=", (int)(q - mat.vals), (int)(p - *q));
            scanf("%lf", p);
        }
}
void printMatrice(const matrice_t mat)
{
    double *p, **q;
    for (q = mat.vals; q < mat.vals + mat.n; q++)
    {
        for (p = *q; p < *q + mat.n; p++)
            printf("%10.2f", *p);
        puts("");
    }
}
matrice_t somme(const matrice_t mat_a, const matrice_t mat_b)
{
    double *p_a, **q_a, *p_b, **q_b, *p_c, **q_c;
    matrice_t mat_c = creerMatrice(mat_a.n);
    for (q_c = mat_c.vals, q_b = mat_b.vals, q_a = mat_a.vals; q_c < mat_c.vals + mat_c.n; q_b++, q_a++, q_c++)
    {
        for (p_c = *q_c, p_b = *q_b, p_a = *q_a; p_c < *q_c + mat_c.n; p_a++, p_b++, p_c++)
        {
            (*p_c) = (*p_a) + (*p_b);
        }
    }
    return mat_c;
}
