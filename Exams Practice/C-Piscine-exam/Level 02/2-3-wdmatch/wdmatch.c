#include <unistd.h>

/*
** str_len - helper returning string length without <string.h>.
**   Used to check if the entire argv[1] was matched.
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
** wdmatch - checks if argv[1]'s characters can be found in argv[2]
**           IN ORDER (subsequence check), then prints argv[1] or '\n'.
**
** Key concept: subsequence, NOT substring.
**   "faya" IS a subsequence of "fgvvfdxcacpolhyghbreda"
**   because f..a..y..a appear in that relative order inside s2,
**   even though they are not contiguous.
**
** Two-pointer technique:
**   i tracks position in argv[1] (word to find).
**   j tracks position in argv[2] (source string).
**
**   At each step:
**   - Always advance j (scan forward in the source).
**   - Only advance i when the current chars match.
**
**   If i reaches the end of argv[1], all characters were found in
**   order -> print argv[1]. Otherwise print nothing.
**
** Why loop condition is argv[1][i] && argv[2][j]:
**   - If argv[2][j] runs out before all of argv[1] is matched -> fail.
**   - If argv[1][i] reaches end -> success, loop exits early.
**
** Requirement cases:
**   - argc != 3            -> skip if block, print only '\n'.
**   - argv[1] is empty     -> i==0==str_len(""), prints empty string
**                             then '\n'. Subject allows this.
**   - argv[1] longer than argv[2] -> j exhausted first, i < len -> no print.
*/
int	main(int argc, char **argv)
{
	int	i; /* index into argv[1] (the word we want to spell) */
	int	j; /* index into argv[2] (the source of characters) */

	if (argc == 3)
	{
		i = 0;
		j = 0;
		while (argv[1][i] && argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
				i++; /* match found: advance word pointer */
			j++;     /* always advance source pointer */
		}
		/* If i reached end of argv[1], all chars were found in order */
		if (i == str_len(argv[1]))
			write(1, argv[1], i);
	}
	write(1, "\n", 1);
	return (0);
}
