#include <unistd.h>

//what pointers mean in functions?
//how to add to an array or a string?
//we must declare the array size or string size before use or no? if it's unknown what do we do?
char    *ft_rev_print (char *str)
{
    int     i;
    i = 0;
    while(str[i] && str[i] != '\0')
    {
        i++;
    }

    while(i > 0)
    {
        write(1,&str[i],1);
        i--;
    }
    
}

//how to get char from command line
int     main(int i, char *s){
    
}