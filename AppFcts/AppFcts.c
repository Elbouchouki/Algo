#include "AppFcts.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <conio.h>

double f(double x)
{
    double x2 = x * x;
    return (2 * x2 * x + 3) * (x2 - 1) / sqrt(3 * x2 + 1);
}
double fprime(double x, double h)
{
    assert(h < 0.5); //h voisine de 0
    return (f(x + h) + f(x - h) / (2 * h));
}
double fsecond(double x, double h)
{
    assert(h < 0.25); //h voisine de 0
    return (fprime(x + h, h) + fprime(x - h, h) / (2 * h));
}
void menu()
{
    int choix;
    double x, y, h = .1;
    do
    {
        system("cls");
        printf("1 - calcul de f\n");
        printf("2 - calcul de fprime\n");
        printf("3 - calcul de fseconde\n");
        printf("4 - Quitter\n");
        scanf("%d", &choix);
        system("cls");
        switch (choix)
        {
        case 1:
            printf("Donnez la valeur de x\n");
            scanf("%lf", &x);
            y = f(x);
            printf("f(%ld)=%lf\n", x, y);
            system("pause");
            break;
        case 2:
            printf("Donnez la valeur de x\n");
            scanf("%lf", &x);
            y = fprime(x, h);
            printf("fprime(%ld)=%lf\n", x, y);
            system("pause");
            break;
        case 3:
            printf("Donnez la valeur de x\n");
            scanf("%lf", &x);
            y = fsecond(x, h);
            printf("fsecond(%ld)=%lf\n", x, y);
            system("pause");
            break;
        case 4:
            printf("Exiting...");
            getch();
            exit(1);
        }
    } while (1);
}