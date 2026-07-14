#include <unistd.h>

char    *ft_strcpy(char *dest, char *src)
{
    int     i;

    i = 0;
    while(src[i]){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

// int     main(void)
// {
//     char source[] = "Hello, World!";
//     char destination[20];
//     ft_strcpy(destination,source);
//     write(1,source, 13);
//     write(1,destination, 13);
// }