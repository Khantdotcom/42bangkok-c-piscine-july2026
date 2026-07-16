#include <unistd.h>

void    ft_inter(char *s1, char *s2)
{
    char seen[256] = {0};

    int     i = 0;
    while(s2[i])
    {
        if (seen[(unsigned char)s2[i]] == 0)
        {
            seen[(unsigned char)s2[i]] = 1;
        }
        i++;
    }

    i = 0;
    while(s1[i])
    {
        if (seen[(unsigned char)s1[i]] == 1)
        {
            write(1,&s1[i],1);
            seen[(unsigned char)s1[i]] = 0;
        }
        i++;
    }
}

int     main(int argc, char **args)
{
    if (argc != 3)
    {
        write(1,"\n",1);
    }else{
        ft_inter(args[1],args[2]);
    }
}