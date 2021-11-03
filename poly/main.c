
/* ----------------------------------- -- ----------------------------------- */
/* ------------------------------- Elbouchouki ------------------------------ */
/* ------------------------------ Algo Polynome ----------------------------- */
/* --------------------------------- ------ --------------------------------- */
/* ---------------------------- * Main Program * ---------------------------- */
/* --------------------------------- ------ --------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "polynome.c"
#include "polynome_t.h"

/* ------------------------ test methods declaration ----------------------- */

void test();
void test_evaluation(poly_t polynome, int x);
void test_affichage(poly_t polynome1, poly_t polynome2);
void test_somme(poly_t polynome1, poly_t polynome2);

/* ---------------------------------- main ---------------------------------- */

int main()
{
    test();
    return 0;
}

/* ----------------------- test methods implementation ---------------------- */

void test()
{
    poly_t polynome1, polynome2;
    //Saisie test
    printf("<!> SAISI <!>\n");
    printf("[Info] <!> Polynome 1: \n");
    polynome1 = saisir();
    printf("[Info] <!> Polynome 2: \n");
    polynome2 = saisir();
    //Evaluation test
    printf("<!> EVALUATION <!>\n");
    printf("[Info] <!> EVAL - Polynome 1: \n");
    test_evaluation(polynome1, -1);
    test_evaluation(polynome1, 1);
    test_evaluation(polynome1, 2);
    test_evaluation(polynome1, 5);
    printf("[Info] <!> EVAL - Polynome 2: \n");
    test_evaluation(polynome2, -1);
    test_evaluation(polynome2, 1);
    test_evaluation(polynome2, 2);
    test_evaluation(polynome2, 5);
    //Affichage test
    test_affichage(polynome1, polynome2);
    //Somme test
    test_somme(polynome1, polynome2);
}

void test_affichage(poly_t polynome1, poly_t polynome2)
{
    printf("<!> SOMME <!>\n");
    printf("[Info] <!> Affichage - Polynome 1: \n");
    afficher(polynome1);
    printf("[Info] <!> Affichage - Polynome 2: \n");
    afficher(polynome2);
}

void test_somme(poly_t polynome1, poly_t polynome2)
{
    printf("[OUT] -> Somme :\n");
    afficher(somme(polynome1, polynome2));
}

void test_evaluation(poly_t polynome1, int x)
{

    printf("[OUT] -> Evaluation(%d): %.2lf\n", x, eval(polynome1, x));
}