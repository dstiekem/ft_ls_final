#include "ft_ls.h"

int     readthings(char *entry, char **set)
{
    t_stuff this;
    if(openandread(entry, set) == 1)
    {
        return (0);
    }
    else if(openandread(entry, set) == 2)
    {
        return (5);//memory 
    }
    else if(openandread(entry, set) == 3)
    {
        return (3);//permissions
    }
    return (1);
}

int     ft_ls(t_node **head, char **set)
{
    if(*head == NULL)
    {
        return (0);
    }
    else if (*head != NULL)
    {
        /* || (*head)->next != NULL*/
        while(*head != NULL)
        {
            /* ft_putendl("ee");  */  
            if(readthings((*head)->data, set))
            {
                free((*head)->data);
            }
		    *head = (*head)->next;
        }
    }
    return (0);
}