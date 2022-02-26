/* ----------------------------------- -- ----------------------------------- */
/* ------------------------------- Elbouchouki ------------------------------ */
/* ------------------------------ Algo Polynome ----------------------------- */
/* --------------------------------- ------ --------------------------------- */
/* ----------------------- * Polynome implementation * ---------------------- */
/* --------------------------------- ------ --------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include "polynome.h"
#include "polynome_t.h"

poly_t somme(poly_t poly1, poly_t poly2)
{
    poly_t resp;
    int i, j, found;
    resp.taille = 0;
    // add first polynome to the result polynome
    for (i = 0; i < poly1.taille; ++i)
    {
        resp.p[resp.taille++] = poly1.p[i];
    }
    // add seconde polynome if degree doesn't exist , else sum coefs
    for (i = 0; i < poly2.taille; ++i)
    {
        found = 0;
        j = 0;
        while (j < resp.taille)
        {
            // degre match
            if (resp.p[j].d == poly2.p[i].d)
            {
                // sum coef
                resp.p[j].a += poly2.p[i].a;
                found = 1;
            }
            ++j;
        }
        //no degree match
        if (!found)
            resp.p[resp.taille++] = poly2.p[i];
    }
    return resp;
}

double eval(poly_t poly, double x)
{
    double evaluation = 0, xy = 1;
    int i, exp = 0;
    for (i = 0; i < poly.taille; ++i)
    {
        // calcul of x^degre
        do
        {
            xy *= x;
            exp++;
        } while (exp < poly.p[i].d);
        // adding i-th monome (x^d * a) to the sum
        evaluation += xy * poly.p[i].a;
    }
    return evaluation;
}
monome_t _lire_monome()
{
    monome_t m;
    printf("[IN] <- Entrez le degre du monome: ");
    scanf("%d", &m.d);
    printf("[IN] <- Entrez le coef du monome: ");
    scanf("%lf", &m.a);
    return m;
}

poly_t saisir()
{
    poly_t poly1;
    int etat;
    monome_t m;
    poly1.taille = 0;
    do
    {
        etat = 1;
        printf("[INFO] <!> Monome: %d\n", poly1.taille + 1);
        m = _lire_monome();
        // degre = -1 means stop
        if (m.d < 0)
            break;
        for (int i = 0; i < poly1.taille && etat; ++i)
        {
            //check if degree exists in the polynome & if the case sum the coefs
            if (poly1.p[i].d == m.d)
            {
                poly1.p[i].a += m.a;
                etat = 0;
            }
        }
        // etat = 1 degree doesn't exist in the polynome
        if (etat == 1)
        {
            poly1.p[poly1.taille] = m;
            ++poly1.taille;
        }
    } while (1);
    return poly1;
}
void afficher(poly_t poly)
{
    printf("[OUT] -> P(x) = ");
    // to skip the first + or -
    printf("%.2lf.x^(%d) ", poly.p[0].a, poly.p[0].d);
    // iterate every monome in the polynome
    for (int i = 1; i < poly.taille; ++i)
    {
        // check if monome's coef = 0
        if (poly.p[i].a == 0)
            continue;
        // check sign
        poly.p[i].a > 0 ? printf("+") : printf("-");
        printf(" %.2lf.x^(%d)", poly.p[i].a, poly.p[i].d);
    }
    printf("\n");
}