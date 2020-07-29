#include <stdio.h>
int first(int *one);

int third(int *three)
{
   /* if(*three > 9)
        return 1; */
    printf("%d\n", *three);
    *three += 1;
    first(three);
    return 1;
}

int second(int *second)
{
   if(*second > 9)
        return 1;
    printf("%d\n", *second);
    *second += 1;
    third(second);
    return 1;
}

int first(int *one)
{
    /* if(*one > 9)
        return 1; */
    printf("%d\n", *one);
    *one += 1;
    second(one);
    return 1;
}

int main()
{
    int i = 0;
    if(first(&i))
        return (0);
}