#include <unistd.h>

/*
** inter - prints chars present in BOTH argv[1] and argv[2],
**          in argv[1]'s order, with no duplicate output.
**
** Core trick: two 256-cell lookup tables (one per distinct need).
**   in_s2[c] = 1  -> character c is present somewhere in argv[2].
**   seen[c]  = 1  -> character c has already been printed.
**
** Two-pass algorithm:
**   Pass 1: scan argv[2] and mark each char in in_s2.
**   Pass 2: scan argv[1] character by character.
**           Print c only when BOTH conditions hold:
**           (a) in_s2[c] == 1  (intersection: c exists in argv[2])
**           (b) seen[c]  == 0  (dedup: c not yet printed)
**           Then set seen[c] = 1 to block future duplicates.
**
** unsigned char cast on array index:
**   char can be signed (-128..127) on some platforms. A negative value
**   used as an array index causes undefined behavior. Casting to
**   unsigned char (0..255) keeps indices valid for any byte value.
**
** Requirement cases:
**   - argc != 3  -> skip the if block entirely, print only '\n'.
**   - Either string empty -> its scan loop simply never fires.
*/
int	main(int argc, char **argv)
{
	int	seen[256];   /* dedup guard: 1 = already printed */
	int	in_s2[256];  /* membership: 1 = char exists in argv[2] */
	int	i;

	i = 0;
	while (i < 256)  /* zero-initialize both tables */
	{
		seen[i] = 0;
		in_s2[i] = 0;
		i++;
	}
	if (argc == 3)
	{
		/* Pass 1: build membership table from argv[2] */
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
				seen[(unsigned char)argv[1][i]] = 1; /* mark as printed */
			}
			i++;
		}
	}
	write(1, "\n", 1); /* mandatory trailing newline */
	return (0);
}
