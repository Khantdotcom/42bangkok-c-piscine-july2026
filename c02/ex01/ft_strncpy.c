#include <unistd.h>

char    *ft_strcpy(char *dest, char *src, unsigned int n)
{
    while(src[n]){
        dest[n] = src[n];
        n++;
    }
    dest[n] = '\0';
    return dest;
}

int     main(void)
{
    char source[] = "Hello, World!";
    char destination[20];
    ft_strcpy(destination,source, 0);
    write(1,source, 13);
    write(1,destination, 13);
}