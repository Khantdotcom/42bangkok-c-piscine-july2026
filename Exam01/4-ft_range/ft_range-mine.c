#include <unistd.h>

int *ft_range(int start, int end)
{
    int *res;
    int size;
    int i;
    int step;

    if (start<=end)
        size = end - start +1;
    else
        size = start - end + 1;

    res = (int *)malloc(sizeof(int) * size);

    if (!res)
        return(NULL);

    if (start<=end)
        step = 1;
    else
        step = - 1;

    i = 0;
    while(i<size)
    {
        res[i] = start;
        start = start + step;
        i++;
    }
    return (res);
}