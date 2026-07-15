#include <unistd.h>

int     ft_strlen(char *str)
{
    int     i;

    i = 0;
    while(str[i] && str[i] != '\0')
    {
        i++;
    }
    return i;
}

int     main(void){
    char s[4] = "ses";
    //Can string be initailized?

    int count = ft_strlen(s);
    char c;

    c = count + '0';
    write(1,&c,1);
}