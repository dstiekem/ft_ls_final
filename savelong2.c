#include "ft_ls.h"


char    *date(struct stat status)
{
        char *date;

        date = ft_strsub(ctime(&status.st_mtime), 4, 3);
        date = ft_strjoin(date, ft_strsub(ctime(&status.st_mtime), 7, 2));
        if (ft_strcmp(ft_itoa((int)time(NULL)), ft_itoa((int)&status.st_mtime)) >= 15724800)
                date = ft_strjoin(date, ft_strsub(ctime(&status.st_mtime), 17, 4));
        else
                date = ft_strjoin(date, ft_strsub(ctime(&status.st_mtime), 9, 7));
        date = ft_strjoin(date, " ");
        date = ft_strjoin(" ", date);
        return (date);
}
char    *names(uid_t u, gid_t g)
{
        struct passwd  *pwd;
        struct group   *grp;
        char *names;

        names = ft_strdup(" ");
        if ((pwd = getpwuid(u)) != NULL)
        {
                names = ft_strjoin(names, pwd->pw_name);
                names = ft_strjoin(names, " ");
        }
        else
                names = ft_strjoin(names, ft_itoa(u));
        if ((grp = getgrgid(g)) != NULL)
                names = ft_strjoin(names, grp->gr_name);
        else
                names = ft_strjoin(names, ft_itoa(g));
        names = ft_strjoin(names, " ");
        return (names);
}

char    *apb(mode_t filemode)
{
        char *strfm;
        char *apb;

        strfm = ft_strnew(0);
      /*   (filemode & S_IFIFO) ? ft_strcat(strfm, "p") : ft_strcat(strfm, "-");
        (filemode & S_IFCHR) ? ft_strcat(strfm, "c") : ft_strcat(strfm, "-");
        
        (filemode & S_IFBLK) ? ft_strcat(strfm, "b") : ft_strcat(strfm, "-");
        (filemode & S_IFLNK) ? ft_strcat(strfm, "l") : ft_strcat(strfm, "-");
        (filemode & S_IFSOCK) ? ft_strcat(strfm, "s") : ft_strcat(strfm, "-"); */
        
        if(filemode & S_IFREG || filemode & S_IFDIR)
        {
                (filemode & S_IFDIR) ? (strfm = ft_strdup("d")) : (strfm = ft_strdup("-"));
                (filemode & S_IRUSR) ? (strfm = ft_strjoin(strfm, "r")) : (strfm = ft_strjoin(strfm, "-"));
                (filemode & S_IWUSR) ? (strfm = ft_strjoin(strfm, "w")) : (strfm = ft_strjoin(strfm, "-"));
                (filemode & S_IXUSR) ? (strfm = ft_strjoin(strfm, "x")) : (strfm = ft_strjoin(strfm, "-"));
                (filemode & S_IRGRP) ? (strfm = ft_strjoin(strfm, "r")) : (strfm = ft_strjoin(strfm, "-"));
                (filemode & S_IWGRP) ? (strfm = ft_strjoin(strfm, "w")) : (strfm = ft_strjoin(strfm, "-"));
                (filemode & S_IXGRP) ? (strfm = ft_strjoin(strfm, "x")) : (strfm = ft_strjoin(strfm, "-"));
                (filemode & S_IROTH) ? (strfm = ft_strjoin(strfm, "r")) : (strfm = ft_strjoin(strfm, "-"));
                (filemode & S_IWOTH) ? (strfm = ft_strjoin(strfm, "w")) : (strfm = ft_strjoin(strfm, "-"));
                (filemode & S_IXOTH) ? (strfm = ft_strjoin(strfm, "x")) : (strfm = ft_strjoin(strfm, "-"));   
        }
        
        /* apb = ft_strdup(strfm); */
        
        apb = ft_strjoin(strfm, " ");
        /* ft_putendl(apb); */
        return(apb);
}

int     savelong(t_node **head)
{
    //print total of 512 bytes
        t_node *tmp;
        struct stat status;
        char *buff;
  /*   char *otherbuff; */
        int blockcount;
        t_node *total;

        blockcount = 0;
        tmp = *head;
        while(tmp != NULL)
        {
                blockcount += (int)status.st_blocks;
                /* ft_putstr("\n");
                ft_putnbr(blockcount); */
                if (stat(tmp->data, &status) == 0)
                {
                        buff = ft_strdup(apb(status.st_mode));
                        buff = ft_strjoin(buff, ft_itoa(status.st_nlink));
                        buff = ft_strjoin(buff, names(status.st_uid, status.st_gid));
                        buff = ft_strjoin(buff, ft_itoa(status.st_size));
                        buff = ft_strjoin(buff, date(status));
                        buff = ft_strjoin(buff, tmp->data);
                        
                        /* ft_strdel(&(*filen)->data); */
                        /* ft_putendl("EEEK"); */
                        /* ft_strclr(tmp->data); */
                        tmp->data = ft_strdup(buff);
                        /* ft_putendl(tmp->data); */
                }
                else
                {
                        continue ;
                }
                
                tmp = tmp->next;
        }
    /* addlinenode(&filen,  */
    /* (*filen) = (*filen)->next; */
        total = makenode(ft_strjoin("total ", ft_itoa(blockcount)));
        total->next = *head;
        head = &total;
        ft_putendl(total->data);
        /* *head = tmp; */

        return(1);
}