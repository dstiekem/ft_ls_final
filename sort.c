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

int timebubble(t_node **dirhead, int count, char **entry)
{
    t_node      *tmp;
    char        *news;
    char        *news2;
    char        *cont;
    struct stat state1;
    struct stat state2;

    news = ft_strnew(0);
    news2 = ft_strnew(0);
    while(count)
    {
        tmp = *dirhead;
        while (tmp->next != NULL)
        {
            
            news = ft_strjoin(*entry, ft_strjoin("/", (tmp->data)));
            news2 = ft_strjoin(*entry, ft_strjoin("/", (tmp->next->data)));
            stat(news, &state1);
            stat(news2, &state2);
/*             ft_putstr(ft_itoa(state1.st_mtime));
            ft_putstr("\t");
            ft_putendl(ft_itoa(state2.st_mtime)); */
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

int backtimebubble(t_node **dirhead, int count, char **entry)
{
    t_node      *tmp;
    char        *cont;
    struct stat state1;
    struct stat state2;
    char        *news;
    char        *news2;

    news = ft_strnew(0);
    news2 = ft_strnew(0);
    while(count)
    {
        tmp = *dirhead;
        while (tmp->next != NULL)
        {
            news = ft_strjoin(*entry, ft_strjoin("/", (tmp->data)));
            news2 = ft_strjoin(*entry, ft_strjoin("/", (tmp->next->data)));
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