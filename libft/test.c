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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t		ft_strlen(const char *str)
{
	int a;

	a = 0;
	if (!str)
		return (0);
	while (str[a])
		a++;
	return (a);
}

int main()
{
	char c[] = "h";
	ft_putchar(ft_strtochr(c));
}
