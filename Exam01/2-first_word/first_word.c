#include <unistd.h>

int main(int j, char *argv[])
{
    int     i;

    i = 0;
    char *s = argv[1];


    while(s[i] && s[i] != '\0' && j == 2)
    {
        if (s[i] != ' ')
        {
            write(1,&s[i],1);
            if(s[i+1] == ' ')
            {
                break;
            }
        }
        i++;
    }
}
    // while (&s[i] && &s[i] != '\0')
    // {
    //     i++;
    // }

    // while(i > 0)
    // {
    //     if (*c[i] != '\0')
    //     {
    //         write(1,&c[i],1);
    //     }
    // }