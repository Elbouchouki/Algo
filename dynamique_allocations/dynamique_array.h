#ifndef DYNAMIQUE_ARRAY_H
#define DYNAMIQUE_ARRAY_H

typedef struct
{
    size_t N;
    int *T;
} dynamique_array_t;

dynamique_array_t create_array();
void delete_array(dynamique_array_t *);

void insert_to_array(dynamique_array_t *);
void display_array(dynamique_array_t *);

void add_element(dynamique_array_t *, int, int);
void delete_element(dynamique_array_t *, int);

void push_element(dynamique_array_t *, int);
void pop_element(dynamique_array_t *);

#endif