#include <stdlib.h>

/*
** ft_range - allocates and fills an int array from start to end INCLUSIVE.
**
** Unlike the C07 version (which only goes low->high), this version
** supports BOTH directions:
**   ft_range(1, 3)   -> [1, 2, 3]   (step = +1)
**   ft_range(0, -3)  -> [0, -1, -2, -3]  (step = -1)
**   ft_range(0, 0)   -> [0]         (single element, len=1)
**
** How direction and length are computed:
**   step = 1 if start <= end, else -1.
**   len  = |end - start| + 1.
**   Multiplying (end - start) by step makes the difference always positive,
**   so the +1 adds the inclusive endpoint without sign issues.
**
** Filling the array:
**   Start from 'start' and add 'step' each iteration.
**   After exactly 'len' steps we have covered start..end inclusive.
**
** Ownership: caller must free() the returned pointer.
**
** Requirement cases:
**   - start == end  -> len=1, arr holds one element. Correct.
**   - malloc fails  -> return NULL (0). Caller should check.
*/
int	*ft_range(int start, int end)
{
	int	len;
	int	step;
	int	*arr;
	int	i;

	step = 1;
	if (start > end)
		step = -1; /* counting down */
	/* Absolute distance + 1 for inclusive both endpoints */
	len = (end - start) * step + 1;
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (0);
	i = 0;
	while (i < len)
	{
		arr[i] = start;  /* store current value */
		start += step;   /* advance by +1 or -1 */
		i++;
	}
	return (arr);
}
