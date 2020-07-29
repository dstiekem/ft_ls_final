#include "ft_ls.h"

void	addnode(t_node **head, t_node *newnode)
{
	t_node *tmp;
	 
	tmp = *head;
	if (*head == NULL)
	{
		*head = newnode;
		return ;
	}
	else if ((*head)->next == NULL)
	{
		tmp->next = newnode;
		return ;
	}
	else
	{
		/* ft_putendl(tmp->data); */
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newnode;
		newnode->next = NULL; 
		return ;
	}
}