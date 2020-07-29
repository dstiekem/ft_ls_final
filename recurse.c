#include "ft_ls.h"

int 		recurse(char *entry, char *set, t_node **n)
{
    t_stuff	this;
	t_node	**dirn;
	//t_node	*filen;
	int count;
    int dcount;

    count = 0;
    dcount = 0;
    dirn = n;
    /*filen = NULL; */
    if (!(this.here = opendir(entry)))
		return (0);
    this.tmp = ft_strnew(0);
    this.tmp = ft_strjoin(ft_strdup(entry), "/");
    this.buff = ft_strnew(1024);
    while ((this.herent = readdir(this.here)) != NULL)
    {	
        if (ft_strchr(set, 'a') == NULL && (this.herent)->d_name[0] == '.')
            continue ;
        /* t_putendl(ft_strjoin(entry, ":")); */
        if (ft_strcmp((this.herent)->d_name, ".") != 0 && ft_strcmp((this.herent)->d_name, "..") != 0 && (this.herent)->d_type == DT_DIR)
        {   
            this.buff = ft_strjoin(this.tmp, (this.herent)->d_name);   
            // ft_putendl(this.buff);
           ft_putendl((this.herent)->d_name);
            addlinenode(&dirn, makelinenode((this.herent)->d_name));
            addlinenode(&n, makelinenode((this.herent)->d_name));
            /* ft_strdel(&(this.tmp)); */
            dcount++;
        }
        else if ((this.herent)->d_type != DT_DIR)
            addlinenode(&n, makelinenode((this.herent)->d_name));
          /*   ft_putendl(ft_strjoin("     ", (this.herent)->d_name)); */
        count++;
    }
    if(sort(&n, count))
    {
        lastflags(set, n, count);
    }
    if(sort(&dirn, dcount))
    {
        ft_putendl("THUS");
        recurse(fetchfirstnode(&dirn), set, dirn);
    }
    if(!dirn && !n)
        closedir(this.here);
    return (1);
}