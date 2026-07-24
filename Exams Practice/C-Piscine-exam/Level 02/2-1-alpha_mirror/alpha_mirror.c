#include <unistd.h>

/*
** mirror_char - maps each letter to its mirror on the alphabet axis.
**
** The trick: position from 'a' = c - 'a' (0..25).
**   The mirror is at position 25 - (c - 'a')  = 'z' - (c - 'a').
**   Same formula works for uppercase with 'Z' as the anchor.
**
** Concrete examples:
**   'a' (pos 0)  ->  'z' (pos 25)   0 mirrors 25
**   'd' (pos 3)  ->  'w' (pos 22)   3 mirrors 22
**   'M' (pos 12) ->  'N' (pos 13)   12 mirrors 13 (in uppercase range)
**
** Non-alphabetic characters are returned unchanged.
** Case is preserved because we use separate lowercase/uppercase ranges.
*/
static char	mirror_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return ('z' - (c - 'a')); /* mirror within lowercase: distance from 'z' */
	if (c >= 'A' && c <= 'Z')
		return ('Z' - (c - 'A')); /* mirror within uppercase: distance from 'Z' */
	return (c);                  /* digits, punctuation, spaces pass through */
}

/*
** Requirement cases:
**   - argc != 2 -> skip if block, print only '\n'.
**   - Empty string argv[1] -> while loop doesn't fire, prints '\n'.
*/
int	main(int argc, char **argv)
{
	int		i;
	char	c;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			c = mirror_char(argv[1][i]);
			write(1, &c, 1); /* write the transformed char byte-by-byte */
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
