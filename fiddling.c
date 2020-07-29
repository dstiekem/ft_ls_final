#include "ft_ls.h"

int     fiddle(char *entry, char **set);

int	traverselstdir(char **entry, t_node **head, char **set)
{
    
    t_stuff check;
	t_node *tmp;
	tmp = *head;
    char *news;
    if (tmp == NULL)
        return 1;
	while (tmp)
	{  
        /* ft_putendl(tmp->data); */
        if (tmp == NULL)
            return 1;
        if((check.here = opendir(tmp->data)) != NULL)
        {
            closedir(check.here);
            news = ft_strjoin(*entry, ft_strjoin("/", (tmp->data)));
            ft_putstr("\n");
            ft_putstr("./");
            ft_putstr(tmp->data);
            ft_putstr(":\n");
            if(fiddle(news, set) < 1)
            {
                ft_putendl("turn");
                return 1;
            }
        }
		free(tmp->data);
		tmp = tmp->next;
		free(*head);
		*head = tmp;
	}
    /* free(*tmp)*/
    return 1;
}

int opensort(char **entry, t_node **filen, char **set, int count)
{
    if(sort(filen, count))
    {
        if (ft_strchr(*set, 't') != NULL)
        {
            timebubble(filen, count);
            if (ft_strchr(*set, 'r') != NULL)
            {
                backtimebubble(filen, count);
            }
        }
        else if(ft_strchr(*set, 't') == NULL && ft_strchr(*set, 'r') != NULL)
        {
            backbubble(filen, count);
        }
        printspecial(filen);
        if(traverselstdir(entry, filen, set))
            return 1;
    }
    return 1;
}

int     fiddle(char *entry, char **set)
{
   
	t_stuff	this;
	t_node	*filen = NULL;
	int count;
    char *fetched;
    
    count = 0;
	if(entry == NULL)
    {
        ft_putendl("op");
        return (1);
    }  
    if (!(this.here = opendir(entry)))
    {
        ft_putendl("op");
        return (3);
    }    
	 
	while ((this.herent = readdir(this.here)) != NULL)
	{	
		if ((this.herent)->d_name[0] == '.' && ft_strchr(*set, 'a') == NULL)
			continue ;
        
        if (ft_strcmp((this.herent)->d_name, ".") != 0 &&\
            ft_strcmp((this.herent)->d_name, "..") != 0)	
        {
            addnode(&filen, makenode((this.herent)->d_name));
        }
        count++;
	}
    if(opensort(&entry, &filen, set, count))
        ft_putendl("turn");
	    /* closedir(this.here); */
	return (4);
}

int main()
{
   
    char *new = ft_strdup("Ra");
 
    if(fiddle(".", &new))
    return (0);
}