#include <stdio.h>
#include <stdlib.h>
#include "dynamique_array.h"

dynamique_array_t create_array()
{
    dynamique_array_t array;
    array.N = 0;
    // printf("N: \n");
    // scanf("%d", &array.N);
    array.T = (int *)calloc(array.N, sizeof(int));
    printf("array created.\n");
    return array;
}
void delete_array(dynamique_array_t *array)
{
    free(array->T);
    printf("array deleted.\n");
}

void display_array(dynamique_array_t *array)
{
    for (int i = 0; i < array->N; i++)
    {
        if (i != 0)
            printf("-");
        printf("%d", *(array->T + i));
    }
    printf("\n");
}

void insert_to_array(dynamique_array_t *array)
{
    for (int i = 0; i < array->N; i++)
    {
        printf("Entre element %d :\n", i);
        scanf("%d", array->T + i);
    }
}

void add_element(dynamique_array_t *array, int index, int value)
{
    array->N = array->N + 1;
    array->T = (int *)realloc(array->T, sizeof(int) * array->N);
    for (int i = array->N; i > index; i--)
    {
        *(array->T + i) = *(array->T + i - 1);
    }
    *(array->T + index) = value;
}

void delete_element(dynamique_array_t *array, int index)
{
    for (int i = index; i < array->N; i++)
    {
        *(array->T + i) = *(array->T + i + 1);
    }
    array->N = array->N - 1;
    array->T = (int *)realloc(array->T, sizeof(int) * array->N);
}

void push_element(dynamique_array_t *array, int value)
{
    array->N = array->N + 1;
    array->T = (int *)realloc(array->T, sizeof(int) * array->N);
    *(array->T + array->N - 1) = value;
}

void pop_element(dynamique_array_t *array)
{
    array->N = array->N - 1;
    array->T = (int *)realloc(array->T, sizeof(int) * array->N);
}