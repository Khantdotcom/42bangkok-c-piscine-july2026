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

int main(int j, char *argv[])
{
    int i;
    char result[100] = {0};
    if (j == 2)
    {
    char *s = argv[1];

    i = ft_strlen(s) -1;

    while(i >= 0)
    {
        if (s[i] != ' ')
        {
            result[i] = s[i];

            if (i - 1 >= 0){
                if(s[i-1] == ' ')
                {
                    break;
                }
            }
        }
        i--;
    }
    int g;

    g = i;
    if (g < 0)
    {
        g = 0;
    }
    while (result[g] != '\0')
    {
        write(1,&result[g],1);
        g++;
    }
    }
}