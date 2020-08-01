#include "ft_ls.h"

int	is_opt(char *args)
{
	if(args[0] != '-')
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

char *is_flag(char *args, int *which)
{
	size_t i;

	i = 1;
	if(is_opt(args))
	{
		while(ft_strchr("Rartl", args[i]) != NULL)
		{
			i++;
		}
		if (i - 1 == ft_strlen(args))
			return NULL;
		else if (i - 1 < ft_strlen(args))
		{
			*which = 2;
			return (&args[i]);
		}
	}
	return (&args[i]);
}

char 	*saveflag(char *args, char *set_value)
{
	char *Rartl;
	char *set;
	static char *temp = NULL;
	size_t i;

	i = 0;
	set = ft_strnew(0);
	Rartl = ft_strdup("Rartl");
	while(i < ft_strlen(Rartl))
	{
		if(ft_strchr(args, Rartl[i]) != NULL)
		{
			temp = ft_strjoin(set_value, ft_strsub(Rartl, i, 1));
			set = ft_strsub(Rartl, i, 1);
			/* ft_putendl(set); */
		}
		i++;
	}
	ft_putendl("_______________");
	ft_putendl(temp);
	ft_putendl("---------------");
	ft_strdel(&Rartl);
	return (set);
}

int		is_ent(char **args, t_node **head, int *which, char **set)
{
	struct stat st;
	int	temp;
	if((temp = stat(*args, &st) == 0)) //if the dir exsist
	{
		if(st.st_mode & S_IFREG || st.st_mode & S_IFDIR)
		{
			addnode(head, makenode(*args));
			*which = 0;
			return(1);
		}
	}
	if (!temp)
	{
		(void)set;
		// if(*set == NULL) //set if there is no flag
			*which = 1;
		return(0);
	}
	return(0);
}

int	main(int ac, char **av)
{
	char *set;
	int	 i;
	int which;
	t_node *head;
	int	optclosed;
	char *temp;

	optclosed = 0;
	i = 1;
	head = NULL;
	set = NULL;
	which = 0;
	temp = NULL;
	
	if(ac < 262144)
	{
		while(av[i])
		{	
			if(ft_strlen(av[i]) >= 256)
				which = 6;
			while(av[i] && is_opt(av[i]) && optclosed == 0)
			{
				if(is_flag(av[i], &which) == NULL && optclosed == 0)
				{
					// temp = ft_strjoin(temp, saveflag(av[i]));
					set = saveflag(av[i], set);
					ft_putendl(set);
					i++;
				}
				else if(is_flag(av[i], &which) != NULL)
				{
					set = is_flag(av[i], &which);
					optclosed = 1;
					break ;//or ISNT FLAG ha!
				}
			}
			if(which != 0)
			{
				if(which == 2)
				{
					av[i] = set;
				}
				// if(!scream(which, av[i]))
				// {
				// 	/* ft_strdel(&set); */
				// 	/* system("leaks ft_ls"); */
				// 	return(0);
				// }
				if(scream(which, av[i]))
					i++;
			}
			if(is_ent(&av[i], &head, &which, &set))
			{
				i++;
				if (optclosed == 0)
					optclosed = 1;
			}	
		}
		if(head == NULL && (which != 1 || set != NULL))
		{
			addnode(&head, makenode("."));
		}
		ft_putnbr(which);
		ft_putendl(set);
		which = ft_ls(&head, &set);//return 0 if all is fine, return 3 if open fails, return 5 if memalloc fails anywhere.
		scream(which, NULL);
		/* system("leaks ft_ls"); */
		return (0);
	}
	else
		scream(4, NULL);
	ft_strdel(&set);
	/* system("leaks ft_ls"); */
	return (0);
}
