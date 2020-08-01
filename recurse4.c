#include "ft_ls.h"

int     recurse(char *entry, char **set);

int	traverselstdir(char **entry, t_node **head, char **set)
{
    
    /* t_stuff check; */
	t_node *tmp;
	tmp = *head;
    char *news;
    struct stat buff;
    if (tmp == NULL)
        return 1;
	while (tmp)
	{
        if (ft_strcmp(tmp->data, ".") != 0 &&\
            ft_strcmp(tmp->data, "..") != 0)
        {
        /* ft_putendl(tmp->data); */
            if (tmp == NULL)
                return 1;
            news = ft_strjoin(*entry, ft_strjoin("/", (tmp->data)));
            if(stat(news, &buff) == 0)
            {
                if((&buff)->st_mode & S_IFDIR)
                {
                    if (ft_strchr(*set, 'R') != NULL)
                    {
                        ft_putstr("\n");
                        ft_putstr(news);//print dir name before going into it
                        ft_putstr(":\n");
                        if(!(openandread(news, set)))
                        {
                            /* ft_putendl("turn"); */
                            
                            return (0);
                        }
                    }
                }
            }
        }
       /*  else if (stat(tmp->data, &buff) == -1)
        {
            ft_putstr("***");
            ft_putstr(tmp->data);
            ft_putstr("***\n");
        } */
        
		free(tmp->data);
		tmp = tmp->next;
		free(*head);
		*head = tmp;
	}
    /* free(*tmp)*/
    return (1);
}

int opensort(char **entry, t_node **filen, char **set, int count)
{   
    if(sort(filen, count))
    {
        if (ft_strchr(*set, 't') != NULL)
        {
            timebubble(filen, count, entry);
            if (ft_strchr(*set, 'r') != NULL)
            {
                backtimebubble(filen, count, entry);
            }
        }
        else if(ft_strchr(*set, 't') == NULL && ft_strchr(*set, 'r') != NULL)
        {
            backbubble(filen, count);
        }
        if(printspecial(filen, *set, entry))
        {
            if(!traverselstdir(entry, filen, set))
            {
                return (0);
            }
        }
    }
    else
    {
        if(printspecial(filen, *set, entry))
            return (1);
    }
    return (1);
}

int     openandread(char *entry, char **set)
{
   
	t_stuff	this;
	t_node	*filen = NULL;
	int count;
    char *fetched;
    struct stat st;
    
    count = 0;
	if(entry == NULL)
    {
        return (1);
    }  
    
    if (!(this.here = opendir(entry)))
    {
         /* &&  == -1 */
        return (3);
    }
    stat(entry, &st);
    if (st.st_mode & S_IFREG)
    {
        ft_putendl("`P`");
    }
	while ((this.herent = readdir(this.here)) != NULL)
	{
		if ((this.herent)->d_name[0] == '.' && ft_strchr(*set, 'a') == NULL)
		{
            continue ;
        }
        if ((this.herent)->d_type == DT_REG || (this.herent)->d_type == DT_DIR || st.st_mode & S_IFREG)
        {	
            {
                this.tmp = ft_strdup(ft_strjoin(entry, (this.herent)->d_name));
                addnode(&filen, makenode((this.herent)->d_name));
            }
            count++;
        }
	}
    
    if(!(opensort(&entry, &filen, set, count)))
    {
	    closedir(this.here);
        return (0);
    }
	return (1);
}
