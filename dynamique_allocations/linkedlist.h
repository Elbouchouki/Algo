#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node_T
{
    int value;
    struct node_T *next;
} node_t;

node_t *create_node(int);

void insert_to_linkedlist(node_t **);
void display_linkedlist(node_t **);

void add_node(node_t **, int, int);
void delete_node(node_t **, int);

void push_node(node_t **, int);
void pop_node(node_t **);

#endif