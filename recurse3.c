#include "ft_ls.h"

int		recurse(char *entry, char **set)
{
	t_stuff	this;
	/* t_node	**filen; */
	int count;
    char *fetched;
    
    count = 0;
	if(entry == NULL)
            return (1);
    if (!(this.here = opendir(entry)))
            return (3);
	
	while ((this.herent = readdir(this.here)) != NULL)
	{	
		if ((this.herent)->d_name[0] == '.' && ft_strchr(*set, 'a') == NULL)
			continue ;
		if ((this.herent)->d_type == DT_REG)
			ft_putendl((this.herent)->d_name);
		if ((this.herent)->d_type == DT_DIR)
		{	
			this.tmp = ft_strjoin("./", (this.herent)->d_name);
			if (ft_strcmp((this.herent)->d_name, ".") != 0 &&\
				ft_strcmp((this.herent)->d_name, "..") != 0)	
			{
				ft_putstr("\n");
				ft_putstr((this.herent)->d_name);
				ft_putstr(":\n");
				ft_putstr(this.tmp);
				recurse(this.tmp, set);
			}
		}
	}
	closedir(this.here);
	return (1);
}