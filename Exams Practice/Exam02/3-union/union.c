#include <unistd.h>

/*
** union - prints chars that appear in argv[1] OR argv[2],
**          exactly once, in the order they first appear.
**
** Difference from inter:
**   - inter requires a char to be in BOTH strings.
**   - union requires a char to be in EITHER string.
**
** Trick: single 256-cell seen[] table.
**   Walk argv[1] entirely, then argv[2]. On every character:
**   - If seen[c] == 0: print it and set seen[c] = 1.
**   - If seen[c] == 1: skip (already output from either string).
**
**   Because we walk argv[1] first, a char appearing in both strings
**   gets printed at its argv[1] position (correct order per subject).
**
** No second table needed (unlike inter): we don't need to know
**   which string a character came from, only whether it was seen.
**
** Requirement cases:
**   - argc != 3  -> skip if block, print only '\n'.
**   - Empty string -> its loop doesn't fire; no output from that string.
*/
int	main(int argc, char **argv)
{
	int	seen[256]; /* 1 = character already printed */
	int	i;

	i = 0;
	while (i < 256)
		seen[i++] = 0; /* zero-initialize */
	if (argc == 3)
	{
		/* Walk argv[1]: print first occurrence of each char */
		i = 0;
		while (argv[1][i])
		{
			if (!seen[(unsigned char)argv[1][i]])
			{
				write(1, &argv[1][i], 1);
				seen[(unsigned char)argv[1][i]] = 1;
			}
			i++;
		}
		/* Walk argv[2]: only print chars not already seen in argv[1] */
		i = 0;
		while (argv[2][i])
		{
			if (!seen[(unsigned char)argv[2][i]])
			{
				write(1, &argv[2][i], 1);
				seen[(unsigned char)argv[2][i]] = 1;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
