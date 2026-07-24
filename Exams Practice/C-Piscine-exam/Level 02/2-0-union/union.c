#include <unistd.h>

/*
** union - prints every character that appears in argv[1] OR argv[2]
**         exactly once, in the order they first appear left-to-right.
**
** Differs from 'inter': union INCLUDES a char if it appears in either
** string, not necessarily both. The key requirement is NO DUPLICATES.
**
** Trick: single 256-cell seen[] table.
**   We simply walk argv[1] then argv[2] in sequence. Before printing
**   any character, check seen[c]. If already printed (seen[c]==1),
**   skip it. Otherwise print and mark seen[c]=1.
**
**   Because we walk argv[1] first and argv[2] second, chars that
**   appear in both are printed when first encountered in argv[1],
**   and skipped when seen again in argv[2]. Order matches subject.
**
** unsigned char cast: guarantees array index stays in [0..255],
**   avoiding undefined behavior on platforms with signed char.
**
** Requirement cases:
**   - argc != 3 -> skip the if block, print only '\n'.
**   - Empty string -> its loop simply doesn't fire.
*/
int	main(int argc, char **argv)
{
	int	seen[256]; /* 1 = character has already been printed */
	int	i;

	/* Zero-initialize: all chars unseen */
	i = 0;
	while (i < 256)
		seen[i++] = 0;
	if (argc == 3)
	{
		/* Walk argv[1]: print each char the first time it appears */
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
