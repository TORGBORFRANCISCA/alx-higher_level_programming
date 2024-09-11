#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert node in a sorted list
 * @head: pointer to list to be added
 * @number: number to add
 * Return: the list with the new number
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node;
    listint_t *tmp = *head;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);

    /* Assign data to the new node */
    new_node->n = number;
    new_node->next = NULL;

    /* Insert at the beginning of the list */
    if (*head == NULL || (*head)->n >= number)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    /* Traverse the list to find the insertion point */
    while (tmp->next != NULL && tmp->next->n < number)
    {
        tmp = tmp->next;
    }

    /* Insert the new node */
    new_node->next = tmp->next;
    tmp->next = new_node;

    return (new_node);
}
