/*
** ft_strrev - reverses a string in-place; returns the same pointer.
**
** In-place: no extra allocation. We modify the original array directly.
**
** Two-pointer technique:
**   l = left index, starts at 0 (first char).
**   r = right index, starts at len-1 (last char).
**   Each iteration swaps str[l] and str[r], then closes the gap
**   (l++ and r--) until they meet or cross.
**
** Why r starts at 0 then walks to the end?
**   We don't call ft_strlen; we measure on-the-fly: walk r until
**   str[r] == '\0', then r-- to land on the last real character.
**
** Edge cases:
**   - ""  (empty)  -> r walks to 0, r-- gives -1; l(0) < r(-1) is false.
**                    Loop never runs, returns pointer as-is. Correct.
**   - "a" (single) -> r lands on 0 after r--; l==r -> loop skips. Correct.
**   - Even length  -> l and r swap until they cross (l > r). No center.
**   - Odd length   -> l and r eventually equal the middle index; l < r
**                    is false -> middle char left in place. Correct.
*/
char	*ft_strrev(char *str)
{
	int		l; /* left pointer, closing in from the start */
	int		r; /* right pointer, closing in from the end */
	char	tmp;

	l = 0;
	r = 0;
	while (str[r])   /* walk r to just past last char */
		r++;
	r--;             /* step back onto the last character */
	while (l < r)    /* swap until pointers meet in the middle */
	{
		tmp = str[l];
		str[l] = str[r];
		str[r] = tmp;
		l++;
		r--;
	}
	return (str); /* same pointer, for call chaining */
}
