#include <stdio.h>
#include <stdlib.h>
#define LMAX 100
int main()
{
    int k = 0, M = 5, N = 10;
    int T[LMAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int S[LMAX] = {1, 2, 3, 7, 8};
    int R[LMAX];

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = M - 1; j >= 0; j--)
        {
            if (T[i] == S[j])
                R[k++] = S[j];
        }
    }

    for (int i = 0; i < k; i++)
    {
        if (i != 0)
            printf(",");
        printf("%d", R[i]);
    }
    return 0;
}