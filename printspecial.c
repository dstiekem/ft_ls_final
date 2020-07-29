#include "ft_ls.h"
void    printspecial(t_node **head, char set)
{
    t_node *tmp;
	t_stuff check;

	
	tmp = (*head);
	while (tmp)
	{
        if (tmp == NULL)
            return ;
		if (set == 'l')
		{
			/* savelong(head, set); */
			savelong(head);
		}
		ft_putendl(tmp->data);
		/* free(tmp->data); */
		tmp = tmp->next;
		/* free(*head); */
		/* (*head) = tmp; */
	}
	/* ft_putendl(tmp->data); */
/* 	free(tmp->data);
	free(*head);*/
} 