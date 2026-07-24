#include <unistd.h>

/*
** first_word - prints the first word in argv[1], followed by '\n'.
**
** A "word" = any sequence of non-space, non-tab characters.
**
** Two-phase algorithm (forward scan only):
**   Phase 1: skip leading spaces/tabs (there may be none).
**   Phase 2: print characters until the next space/tab or end of string.
**
** Why two separate loops?
**   If we combined them, a leading space would immediately stop output.
**   Separating skip and print makes the intent clear and robust.
**
** Requirement cases:
**   - argc != 2          -> skip if block, print only '\n'.
**   - Only spaces/tabs   -> phase 1 walks to '\0'; phase 2 condition
**                          argv[1][i] is false -> prints nothing, then '\n'.
**   - "  lorem,ipsum  " -> phase 1 skips leading spaces, phase 2
**                          prints "lorem,ipsum", stops at space. Correct.
*/
int	main(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		/* Phase 1: skip any leading whitespace */
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		/* Phase 2: print the first word until whitespace or end */
		while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
