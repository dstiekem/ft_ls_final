#include "ft_ls.h"

int     readthings(char *entry, char **set)
{
    t_stuff this;

    if(openandread(entry, set) == 1)
    {
        return (0);
    }
    else if(openandread(entry, set) == 2)
    {
        return (5);//memory 
    }
    else if(openandread(entry, set) == 3)
    {
        return (3);//permissions
    }

    if (ft_strchr(*set, 'R') != NULL)
    {
        //open rec
            //if a. open more
                //if t. arrange those "more" by time
                    //if (inside t) r. arrange "more" by reverse time.
                //else if r. arrange those "more" by reverse lex
        //if l. print with the stuff. symlinks stickybit
        if(openandread(entry, set) == 1)
        {
            return (0);
        }
        else if(openandread(entry, set) == 2)
        {
            return (5);//memory 
        }
        else if(openandread(entry, set) == 3)
        {
            return (3);//permissions
        }
    }
    else if (ft_strchr(*set, 'a') != NULL)
    {
        //open more
            //if t. arrange those "more" by time
                    //if (inside t) r. arrange "more" by reverse time.
                //else if r. arrange those "more" by reverse lex
        //if l. print with the stuff. symlinks stickybit
      /*   if(savelong(entry, set) == 1)
        {
            return (0);
        }
        else if(savelong(entry, set) == 2)
        {
            return (5);
        }
        else if(savelong(entry, set) == 3)
        {
            return (3);
        } */
    }
    else if (ft_strchr(*set, 't') != NULL)
    {
        //arrange those by time
            //if (inside t) r. arrange "more" by reverse time.
        //if l. print with the stuff. symlinks stickybit
    }
    else if (ft_strchr(*set, 'r') != NULL)
    {
        //reverse lex
        //if l. print with the stuff. symlinks stickybit
    }
    else if (ft_strchr(*set, 'l') != NULL)
    {
        //print(savedlist())
        ft_putendl("p");
    }
    if(ft_strcmp("\0", *set) == 0)
    {
        /* normal(); */
        return (1);
    }
    return (1);
}

int     ft_ls(t_node **head, char **set)
{
    if(*head == NULL)
    {
        return (0);
    }
    else if (*head != NULL)
    {
        /* || (*head)->next != NULL*/
        while(*head != NULL)
        {
            /* ft_putendl("ee");  */  
            if(readthings((*head)->data, set))
            {
                /* ft_putendl("TT");  */ 
                free((*head)->data);
            }
		    *head = (*head)->next;
        }
    } 
    return (0);
}