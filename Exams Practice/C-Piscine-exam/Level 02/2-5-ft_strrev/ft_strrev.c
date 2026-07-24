/*
** ft_strrev - reverses a string in-place and returns it.
**
** In-place means we modify the original array, no extra allocation.
**
** Two-pointer technique:
**   l starts at index 0 (leftmost char).
**   r starts at index len-1 (rightmost char, found by scanning to '\0'
**   then stepping back one).
**
**   Each iteration: swap str[l] and str[r], then close both pointers
**   (l++ and r--). Stop when they meet or cross (l >= r).
**   This effectively mirrors the string around its center.
**
** Classic tmp-swap (no XOR trick) for clarity:
**   tmp = str[l]; str[l] = str[r]; str[r] = tmp;
**
** Edge cases:
**   - Empty string ""     -> r goes to -1 after r--, while(l < r) is
**                            false immediately (0 < -1 is false). Returns
**                            original pointer. Correct.
**   - Single char "a"     -> r == 0 after r--; l==r -> loop doesn't run.
**                            Returns original. Correct.
**   - Even/odd lengths   -> both handled: mid char of odd string
**                            is never swapped with itself because loop
**                            stops when l == r.
**
** Return value: the same pointer passed in, allowing call chaining.
*/
char	*ft_strrev(char *str)
{
	int		l; /* left pointer, starts at beginning */
	int		r; /* right pointer, starts at end */
	char	tmp;

	l = 0;
	r = 0;
	/* Advance r to the null terminator */
	while (str[r])
		r++;
	r--; /* step back to the last actual character */
	while (l < r) /* converge from both ends toward the middle */
	{
		tmp = str[l];  /* classic three-variable swap */
		str[l] = str[r];
		str[r] = tmp;
		l++;
		r--;
	}
	return (str); /* return same pointer for chaining */
}