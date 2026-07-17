#include <stdlib.h>

int *ft_range(int start, int end)
{
    int *res;
    int size;
    int i;
    int step;

    // Calculate the total number of elements required
    if (start <= end)
        size = end - start + 1;
    else
        size = start - end + 1;

    // Allocate memory
    res = (int *)malloc(sizeof(int) * size);
    if (!res)
        return (NULL);

    // Determine the direction of the progression
    if (start <= end)
        step = 1;
    else
        step = -1;

    // Fill the array
    i = 0;
    while (i < size)
    {
        res[i] = start;
        start = start + step;
        i++;
    }

    return (res);
}