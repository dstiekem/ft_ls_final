#include "libft.h"

char	ft_strtochr(char *str)
{
	char a;

	if(ft_strlen(str) == 1)
	{
		a = *str;
		return (a);
	}
	else 
		return ('\0');
}
