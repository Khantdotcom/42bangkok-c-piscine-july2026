/*
** max - returns the largest integer in an array.
**
** Algorithm: linear scan, keeping a running maximum.
**   Start m = tab[0] (first element is the best candidate so far).
**   For each subsequent element, update m if a larger value is found.
**
** Why seed with tab[0] instead of INT_MIN:
**   Using tab[0] avoids importing <limits.h> and naturally handles
**   arrays whose all values are negative.
**
** Requirement cases:
**   - len == 0 -> return 0 immediately (empty array, subject spec).
**   - len == 1 -> loop starts at i=1, condition fails immediately,
**                 returns tab[0] directly. Correct.
**   - All equal values -> m stays at that value. Correct.
**   - All negative values -> linear scan finds the least-negative. Correct.
**
** unsigned int for len and i: matches the prototype signature and
**   prevents signed/unsigned comparison warnings.
*/
int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				m;

	if (len == 0)   /* empty array: no valid maximum, return 0 per spec */
		return (0);
	m = tab[0];     /* seed with first element; best value seen so far */
	i = 1;
	while (i < len)
	{
		if (tab[i] > m) /* found a new maximum */
			m = tab[i];
		i++;
	}
	return (m);
}
