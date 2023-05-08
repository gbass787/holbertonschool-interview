#include <stdio.h>
#include <stdlib.h>

typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

int check_cycle(listint_t *list)
{
    listint_t *slow_ptr = list;
    listint_t *fast_ptr = list;

    while (slow_ptr && fast_ptr && fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        if (slow_ptr == fast_ptr)
        {
            return 1;
        }
    }

    return 0;
}

/* The code below is just for testing purposes and should not be considered part of the solution */
int main()
{
    listint_t *node1 = (listint_t *)malloc(sizeof(listint_t));
    listint_t *node2 = (listint_t *)malloc(sizeof(listint_t));
    listint_t *node3 = (listint_t *)malloc(sizeof(listint_t));
    listint_t *node4 = (listint_t *)malloc(sizeof(listint_t));

    node1->n = 1;
    node2->n = 2;
    node3->n = 3;
    node4->n = 4;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL; // Set to NULL for no cycle; set to node1 (or any other node) to create a cycle

    if (check_cycle(node1))
    {
        printf("The linked list has a cycle.\n");
    }
    else
    {
        printf("The linked list does not have a cycle.\n");
    }

    free(node1);
    free(node2);
    free(node3);
    free(node4);

    return 0;
}
