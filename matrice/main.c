#include "matrice.h"
#include <stdio.h>

int main()
{
    matrice_t m1, m2;
    m1 = creerMatrice(3);
    m2 = creerMatrice(3);
    scanMatrice(m1);
    scanMatrice(m2);
    puts("Matrice 1 :");
    printMatrice(m1);
    puts("Matrice 2 :");
    printMatrice(m2);
    puts("somme :");

    printMatrice(somme(m1, m2));
    return 0;
}