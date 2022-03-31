#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

node_t *create_node(int value)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->value = value;
    node->next = NULL;
    return node;
}
void display_linkedlist(node_t **head)
{
    node_t *temp = *head;
    while (temp != NULL)
    {
        printf(" %d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void reverse_linkedlist(node_t **head)
{
    node_t *current = head;
    node_t *prev = NULL, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void add_node(node_t **head, int index, int value)
{
    node_t *newNode = create_node(value);
    if (index == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    int cpt = 1;
    node_t *temp = *head;
    while (temp->next != NULL)
    {

        if (cpt == index)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
        cpt++;
    }
    temp->next = newNode;
}

void delete_node(node_t **head, int index)
{
    if (index == 0)
    {
        *head = (*head)->next;
        return;
    }
    node_t *temp = *head;
    int cpt = 1;
    while (temp->next != NULL)
    {
        if (cpt == index)
        {
            temp->next = temp->next->next;
            return;
        }
        temp = temp->next;
        cpt++;
    }
}

void push_node(node_t **head, int value)
{
    node_t *newNode = create_node(value);
    if ((*head) == NULL)
    {
        (*head) = newNode;
    }
    else
    {
        node_t *temp = (*head);
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void pop_node(node_t **head)
{
    node_t *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}