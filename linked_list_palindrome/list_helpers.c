#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *new_node = malloc(sizeof(listint_t));
    listint_t *temp;

    if (!new_node)
        return (NULL);

    new_node->n = n;
    new_node->next = NULL;

    if (!(*head))
    {
        *head = new_node;
        return (new_node);
    }

    temp = *head;
    while (temp->next)
        temp = temp->next;

    temp->next = new_node;

    return (new_node);
}

void print_listint(const listint_t *h)
{
    while (h)
    {
        printf("%d\n", h->n);
        h = h->next;
    }
}

void free_listint(listint_t *head)
{
    listint_t *temp;

    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

