#include <unistd.h>

int     *ft_range(int start, int end)
{
    int     temp;
    temp = start;

    int     array[] = {0};

    int i = 0;

    while (start <= end)
    {
        int a = malloc(start);
        array[i] = a;
        i++;
    }
}