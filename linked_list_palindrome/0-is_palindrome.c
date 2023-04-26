#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the head of the list
 *
 * Return: 1 if it is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow, *fast, *prev, *temp;

    if (!head || !(*head) || !((*head)->next))
        return (1);

    slow = fast = prev = *head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        temp = slow;
        slow = slow->next;
        temp->next = prev;
        prev = temp;
    }

    if (fast)
        slow = slow->next;

    while (slow)
    {
        if (slow->n != prev->n)
            return (0);
        slow = slow->next;
        prev = prev->next;
    }

    return (1);
}

