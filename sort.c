#include "ft_ls.h"

int sort(t_node **dirhead, int count)
{
    t_node  *tmp;
    char    *cont;
    
    while(count)
    {
        tmp = *dirhead;
        while (tmp->next != NULL)
        {
            if ((*dirhead == NULL) || ((*dirhead)->next == NULL))
            { 
                return(1); 
            } 
            if (ft_strcmp(tmp->data, tmp->next->data) > 0)
            {
                cont = tmp->data;
                tmp->data = tmp->next->data;
                tmp->next->data = cont;
            }
            else 
                tmp = tmp->next; 
        }
        count --;
    }
    return(1);
}

int timebubble(t_node **dirhead, int count)
{
    t_node      *tmp;
    char        *cont;
    struct stat state1;
    struct stat state2;
    while(count)
    {
        tmp = *dirhead;
        while (tmp->next != NULL)
        {
            stat(tmp->data, &state1);
            stat(tmp->next->data, &state2);
            if (tmp->data == NULL)
            {
                tmp = tmp->next;
                continue ;
            }
            if (state1.st_mtime < state2.st_mtime)
            {
                cont = tmp->data;
                tmp->data = tmp->next->data;
                tmp->next->data = cont;
            }
            else 
                tmp = tmp->next; 
        }
        count --;
    }
    return(1);
}

int backtimebubble(t_node **dirhead, int count)
{
    t_node      *tmp;
    char        *cont;
    struct stat state1;
    struct stat state2;
    while(count)
    {
        tmp = *dirhead;
        while (tmp->next != NULL)
        {
            stat(tmp->data, &state1);
            stat(tmp->next->data, &state2);
            if (tmp->data == NULL)
            {
                tmp = tmp->next;
                continue ;
            }
            if (state1.st_mtime > state2.st_mtime)
            {
                cont = tmp->data;
                tmp->data = tmp->next->data;
                tmp->next->data = cont;
            }
            else 
                tmp = tmp->next; 
        }
        count --;
    }
    return(1);
}

int backbubble(t_node **dirhead, int count)
{
    t_node  *tmp;
    char    *cont;
    while(count)
    {
        tmp = *dirhead;
        while (tmp->next != NULL)
        {
            if ((*dirhead == NULL) || ((*dirhead)->next == NULL))
            { 
                return(1); 
            } 
            if (ft_strcmp(tmp->data, tmp->next->data) < 0)
            {
                cont = tmp->data;
                tmp->data = tmp->next->data;
                tmp->next->data = cont;
            }
            else 
                tmp = tmp->next; 
        }
        count --;
    }
    return(1);
}