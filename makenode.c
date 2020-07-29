#include "ft_ls.h"

t_node	*makenode(const char *data)
{
	
	t_node *new;

	if(!(new = (t_node *)ft_memalloc(sizeof(t_node))))
		return (NULL);
	if (data == NULL)
	{
		new->data = NULL;
	}
	else
	{
		new->data = ft_strdup(data);
		new->next = NULL;
	}
	return(new);
}