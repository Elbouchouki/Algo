#include <stdlib.h>
#include <stdio.h>
int memo[100];

int fibo_bruteForce(int i);
int fibo(int i, int memo[]);

int test()
{
    printf("fibo( %d )= %d \n", 3, fibo_bruteForce(3));
    printf("fibo_bruteForce( %d )= %d \n", 4, fibo_bruteForce(4));
    printf("fibo_bruteForce( %d )= %d \n", 5, fibo_bruteForce(5));
    printf("fibo_bruteForce( %d )= %d \n", 6, fibo_bruteForce(6));
    printf("fibo_bruteForce( %d )= %d \n", 7, fibo_bruteForce(7));
    printf("fibo_bruteForce( %d )= %d \n", 8, fibo_bruteForce(8));
    printf("fibo_bruteForce( %d )= %d \n", 46, fibo_bruteForce(46));
    printf("%d\n", fibo(46, memo));
    // printf("fibo( %d )= %d \n", 50, fibo(50));
}

int main()
{
    memo[0] = 0;
    memo[1] = 1;
    for (int i = 2; i < 100; i++)
    {
        memo[i] = -1;
    }
    test();
}

int fibo_bruteForce(int i)
{
    if (i < 1)
        return 0;
    if (i == 1)
        return 1;
    return fibo_bruteForce(i - 1) + fibo_bruteForce(i - 2);
}

int fibo(int i, int memo[])
{
    if (memo[i] != -1)
        return memo[i];
    if (i < 1)
        return 0;
    if (i == 1)
        return 1;
    memo[i] = fibo(i - 1, memo) + fibo(i - 2, memo);
    return memo[i];
}
