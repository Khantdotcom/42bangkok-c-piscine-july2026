/*
** ft_strcmp - lexicographic comparison of two null-terminated strings.
**
** Returns:
**   0       if strings are identical
**   >0      if s1 comes after s2 lexicographically
**   <0      if s1 comes before s2 lexicographically
**
** Algorithm:
**   Advance both pointers together as long as characters match AND
**   neither string has ended (*s1 != '\0').
**   The loop stops at the FIRST differing character, or when s1 ends.
**
** Why both conditions in the while?
**   *s1 alone: if s1 ends first ("abc" vs "abcd"),
**              *s1 is '\0', *s2 is 'd'. Without the '&& *s1 == *s2'
**              we'd skip to the subtract below: '\0' - 'd' = negative. OK.
**   *s1 == *s2: prevents advancing past a mismatch.
**   Together: loop advances only while chars truly match and s1 has more.
**
** Why unsigned char cast in the subtraction?
**   Plain char is signed on most platforms (-128..127).
**   Characters like 'é' (0xE9 = 233) would be negative if signed,
**   producing wrong comparison results. Casting to unsigned char (0..255)
**   gives correct lexicographic byte comparison as per the C standard.
**
** Edge cases:
**   - Both empty "" == ""   -> loop never runs, '\0' - '\0' = 0. Correct.
**   - "abc" vs "abc"        -> loop runs 3 times, '\0' - '\0' = 0. Correct.
**   - "abc" vs "abd"        -> loop stops at 'c'/'d', 'c'-'d' = -1. Correct.
*/
int	ft_strcmp(char *s1, char *s2)
{
	/* Advance while chars match AND s1 has not ended */
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	/* Subtract as unsigned bytes to get correct signed result */
	return ((unsigned char)*s1 - (unsigned char)*s2);
}