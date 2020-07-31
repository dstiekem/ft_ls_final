#ifndef FT_LS
# define FT_LS
#include "libft/libft.h"
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

typedef struct			s_node
{
	char				*data;
	struct s_node		*next;

}						t_node;

typedef	struct			s_stuff
{
	DIR					*here;
	struct dirent 		*herent;
	char				*tmp;
	char				*buff;
	struct stat 		*mystat;

}						t_stuff;

int      scream(int which, char *args);
int     ft_ls(t_node **head, char **set);
void	addnode(t_node **head, t_node *newnode);
t_node	*makenode(const char *data);
int		openandread(char *entry, char **set);
t_node  *savelong(t_node *head, char **entry);
int	    printspecial(t_node **head, char *set, char **entry);
int 	sort(t_node **dirhead, int count);
int 	timebubble(t_node **dirhead, int count);
int 	backtimebubble(t_node **dirhead, int count);
int 	backbubble(t_node **dirhead, int count);

#endif
