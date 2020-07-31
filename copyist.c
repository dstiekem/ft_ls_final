#include "ft_ls.h"

t_node *copyist(t_node **head)
{
    t_node *copy;
    t_node *tmp; 
    copy = NULL;
    tmp = *head;

    if (tmp == NULL)
    {
        return (copy);
    }
    while(tmp != NULL)
    {
        if (tmp == NULL)
        {
            return (copy);
        }
        addnode(&copy, makenode(tmp->data));
        tmp = tmp->next;
    }
    return (copy);
}