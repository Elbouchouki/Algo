#ifndef _MATRICE
#define _MATRICE
typedef struct
{
	int n;
	double **vals;
} matrice_t;

matrice_t creerMatrice(int);
void scanMatrice(matrice_t);
void printMatrice(const matrice_t);
matrice_t somme(matrice_t, matrice_t);
#endif