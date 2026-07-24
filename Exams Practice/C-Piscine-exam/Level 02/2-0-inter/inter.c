#include <unistd.h>

/*
** inter - prints chars that appear in BOTH argv[1] and argv[2],
**          preserving argv[1]'s order, no duplicates.
**
** Core trick: 256-cell lookup tables.
**   ASCII has at most 256 distinct byte values, so we can track
**   membership and 'already-printed' status in O(1) per character.
**
**   in_s2[c] = 1  means character c appears somewhere in argv[2].
**   seen[c]  = 1  means c was already printed (dedup guard).
**
** Algorithm:
**   Pass 1 - scan argv[2] and mark every char in in_s2.
**   Pass 2 - scan argv[1]; for each char, print it only if
**            (a) it is in in_s2  -> intersection condition
**            (b) it hasn't been seen yet -> no-duplicate condition
**            then mark seen[char] = 1.
**
** unsigned char cast on array index:
**   Plain char can be negative on some systems (signed char).
**   Using (unsigned char) ensures the index is 0..255, never negative.
**
** Requirement cases:
**   - argc != 3 -> print only '\n' (skips if block entirely).
**   - Either string empty -> inner loops don't fire, just prints '\n'.
*/
int	main(int argc, char **argv)
{
	int	seen[256];  /* tracks chars already printed */
	int	in_s2[256]; /* membership table for argv[2] */
	int	i;

	/* Zero-initialize both tables */
	i = 0;
	while (i < 256)
	{
		seen[i] = 0;
		in_s2[i] = 0;
		i++;
	}
	if (argc == 3)
	{
		/* Pass 1: mark every character present in argv[2] */
		i = 0;
		while (argv[2][i])
			in_s2[(unsigned char)argv[2][i++]] = 1;
		/* Pass 2: walk argv[1], print chars in both strings */
		i = 0;
		while (argv[1][i])
		{
			if (!seen[(unsigned char)argv[1][i]] && in_s2[(unsigned char)argv[1][i]])
			{
				write(1, &argv[1][i], 1);
				seen[(unsigned char)argv[1][i]] = 1; /* mark printed */
			}
			i++;
		}
	}
	write(1, "\n", 1); /* always end with newline, even on empty output */
	return (0);
}
