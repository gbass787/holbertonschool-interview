#include <stddef.h>
#include "lists.h"

/**
 * reverse_list - reverses a linked list
 * @head: pointer to the head of the list
 * Return: pointer to the head of the reversed list
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL, *current = head, *next = NULL;

    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the head of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow, *fast, *prev_slow, *second_half;
    listint_t *first_half, *second_half_copy;
    int is_palindrome;

    if (!head || !*head || !(*head)->next)
    {
        return 1;
    }

    slow = *head;
    fast = *head;
    prev_slow = NULL;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    second_half = prev_slow->next;
    prev_slow->next = NULL;

    second_half = reverse_list(second_half);

    first_half = *head;
    second_half_copy = second_half;
    is_palindrome = 1;

    while (first_half && second_half)
    {
        if (first_half->n != second_half->n)
        {
            is_palindrome = 0;
            break;
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }

    prev_slow->next = reverse_list(second_half_copy);

    return is_palindrome;
}

