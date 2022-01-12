#include <stdio.h>
#include <stdlib.h>
#include "dynamique_array.h"
#include "linkedlist.h"

void test_dynamique_array()
{
    dynamique_array_t array = create_array();
    insert_to_array(&array);
    display_array(&array);
    add_element(&array, 5, 20);
    display_array(&array);
    delete_element(&array, 0);
    display_array(&array);
    push_element(&array, 88);
    display_array(&array);
    pop_element(&array);
    display_array(&array);
}

void test_linkedlist()
{
    node_t *head = NULL;
    push_node(&head, 10);
    push_node(&head, 20);
    push_node(&head, 30);
    push_node(&head, 40);
    push_node(&head, 50);
    push_node(&head, 60);
    display_linkedlist(&head);
    add_node(&head, 0, 111);
    add_node(&head, 80, 222);
    add_node(&head, 2, 333);
    display_linkedlist(&head);
    delete_node(&head, 0);
    display_linkedlist(&head);
    delete_node(&head, 4);
    display_linkedlist(&head);
}
void linkedlist_to_array(dynamique_array_t *array, node_t **head)
{
    node_t *temp = *head;
    while (temp != NULL)
    {
        push_element(array, temp->value);
        temp = temp->next;
    }
}
void array_to_linkedlist(dynamique_array_t *array, node_t **head)
{
    node_t *temp = *head;
    for (int i = 0; i < array->N; i++)
    {
        push_node(head, *(array->T + i));
    }
}

int main()
{
    dynamique_array_t array = create_array();
    for (int i = 0; i < 10; i++)
        push_element(&array, i);
    node_t *head = NULL;
    push_node(&head, 10);
    push_node(&head, 20);
    push_node(&head, 30);
    push_node(&head, 40);
    push_node(&head, 50);
    push_node(&head, 60);
    display_array(&array);
    display_linkedlist(&head);
    node_t *head2 = NULL;
    dynamique_array_t array2 = create_array();
    linkedlist_to_array(&array2, &head);
    display_array(&array2);
    array_to_linkedlist(&array, &head2);
    display_linkedlist(&head2);
}