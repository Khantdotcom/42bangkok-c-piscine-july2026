#include <unistd.h>

/*
** str_len - counts chars in s without <string.h>.
**   Used to verify that all of argv[1] was matched.
*/
static int	str_len(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

/*
** wdmatch - checks whether argv[1] is a SUBSEQUENCE of argv[2].
**           Prints argv[1] if yes, or just '\n' if no.
**
** Subsequence vs Substring:
**   Substring: chars must be contiguous.  "fay" in "faya" YES.
**   Subsequence: chars must appear in order but not necessarily together.
**              "faya" in "fgvvfdxcacpolhyghbreda"  YES (f..a..y..a spread out).
**              "faya" in "fgvvfdxcacpolhyghbred"   NO  (no 'a' after the 'y').
**
** Two-pointer technique:
**   i scans argv[1] (the word to spell out).
**   j scans argv[2] (the source of available characters).
**
**   - j always advances (we move through the source one char at a time).
**   - i advances ONLY on a match (we consumed one needed character).
**
**   If we exhaust argv[1] (i == len1), all chars were found in order: success.
**   If we exhaust argv[2] before i reaches the end: failure.
**
** Why check i == str_len(argv[1]) after the loop?
**   The loop can exit two ways:
**   (a) argv[1][i] == '\0': i reached end -> success.
**   (b) argv[2][j] == '\0': source exhausted -> failure.
**   str_len comparison distinguishes the two cases cleanly.
**
** Requirement cases:
**   - argc != 3            -> skip if block, print only '\n'.
**   - argv[1] is ""        -> i==0==str_len; condition true; write 0 bytes
**                             then '\n'. Correct for empty needle.
*/
int	main(int argc, char **argv)
{
	int	i; /* position in argv[1]: the word we want to build */
	int	j; /* position in argv[2]: the source of characters */

	if (argc == 3)
	{
		i = 0;
		j = 0;
		while (argv[1][i] && argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
				i++; /* character matched: advance word pointer */
			j++;     /* always advance through the source */
		}
		if (i == str_len(argv[1])) /* all needed chars found in order */
			write(1, argv[1], i);
	}
	write(1, "\n", 1);
	return (0);
}
