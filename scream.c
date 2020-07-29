#include "ft_ls.h"

int     scream(int which, char *args)
{
    if(which == 1)//MAIN
    {
        ft_putendl(args);
        ft_putendl("no such file or directory");
        exit(1);
        return (1);
    }
    else if (which == 2)//illegal option end program MAIN;
    {
        
        ft_putstr("ft_ls: -- ");
        ft_putstr(args);
        ft_putstr(" illegal option");
        return (0);
    }
    else if (which == 3)//handled in opendir FT_LS
    {
        ft_putstr("ft_ls: cannot open directory \'");
        ft_putstr(args);
        ft_putstr("\': Permission denied");
        return (0);
    }
    else if(which == 4)//MAIN before everything else
    {

        ft_putendl("ft_ls: arg list too long");
        return (0);
    }
    else if(which == 5)//handled in opendir FT_LS
    {
        ft_putendl("ft_ls: cannot allocate memory");
        return (0);
    }
    else if(which == 6)//MAIN befroe everything else
    {
        ft_putendl("ft_ls: filename too long");
        return (0);
    }
    else if(which == 0)
    {
        return (1);
    }
    return (1);
}