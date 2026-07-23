#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	len;
	int	step;
	int	*arr;
	int	i;

	step = 1;
	if (start > end)
		step = -1;
	len = (end - start) * step + 1;
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (0);
	i = 0;
	while (i < len)
	{
		arr[i] = start;
		start += step;
		i++;
	}
	return (arr);
}
