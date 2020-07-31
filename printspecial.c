#include "ft_ls.h"
int    printspecial(t_node **head, char *set, char **entry)
{
    t_node *tmp;
	t_stuff check;

	if (ft_strchrchr(set, 'l') == 'l')
	{
		/* savelong(head, set); */
		tmp = savelong(*head, entry);
		while (tmp)
		{
			if (tmp == NULL)
				return (0);
			ft_putendl(tmp->data);
			/* free(tmp->data); */
			tmp = tmp->next;
			/* free(*head); */
			/* (*head) = tmp; */
			
		}
	}
	else
	{
		tmp = (*head);
		while (tmp)
		{
			if (tmp == NULL)
				return (0);
			ft_putendl(tmp->data);
			/* free(tmp->data); */
			tmp = tmp->next;
			/* free(*head); */
			/* (*head) = tmp; */
			
		}
	}
	/* ft_putendl(tmp->data); */
/* 	free(tmp->data);
	free(*head);*/
	return (1);
} 