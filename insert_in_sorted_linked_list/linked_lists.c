#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

size_t print_listint(const listint_t *h)
{
    const listint_t *current = h;
    size_t n = 0;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
        n++;
    }
    return (n);
}

listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *new = malloc(sizeof(listint_t));
    listint_t *current;

    if (!new)
        return (NULL);

    new->n = n;
    new->next = NULL;

    if (!*head)
    {
        *head = new;
        return (new);
    }

    current = *head;
    while (current->next)
        current = current->next;

    current->next = new;
    return (new);
}

void free_listint(listint_t *head)
{
    listint_t *tmp;

    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
