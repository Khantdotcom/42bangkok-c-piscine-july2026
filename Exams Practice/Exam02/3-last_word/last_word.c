#include <unistd.h>

/*
** last_word - prints the last word in argv[1], followed by '\n'.
**
** A word = any non-space/non-tab sequence. Trailing spaces must be
** ignored, so a simple forward scan won't work. We scan from the RIGHT.
**
** Four-step right-to-left algorithm:
**   Step 1 - Walk i to the null terminator, then step back one.
**            Now i points at the last char (or -1 if empty string).
**   Step 2 - Skip trailing whitespace: move i left while space/tab.
**            If the whole string is spaces, i goes to -1 -> nothing printed.
**   Step 3 - Save end = index of the last non-whitespace char.
**   Step 4 - Walk i further left to find the start of the last word
**            (stop at a space/tab or when i goes below 0).
**   Print  - ++i in the loop condition corrects the one-past-the-start
**            overshoot (or the -1 underrun), then print while i <= end.
**
** Why ++i in the print loop header?
**   After step 4, i is one position BEFORE the word starts (it stopped
**   on the delimiting space, or -1). Pre-incrementing before the
**   comparison and the write puts us exactly on the first char.
**
** Requirement cases:
**   - argc != 2          -> skip if block, print only '\n'.
**   - All whitespace     -> after step 2, end == -1; print loop never fires.
**   - No leading spaces  -> step 4 exits with i == -1; ++i gives 0.
*/
int	main(int argc, char **argv)
{
	int	i;
	int	end;

	if (argc == 2)
	{
		/* Step 1: move i to end of string */
		i = 0;
		while (argv[1][i])
			i++;
		i--; /* land on last char (or -1 for empty) */
		/* Step 2: skip trailing whitespace */
		while (i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
			i--;
		/* Step 3: mark end of last word */
		end = i;
		/* Step 4: walk left through the last word */
		while (i >= 0 && argv[1][i] != ' ' && argv[1][i] != '\t')
			i--;
		/* ++i corrects the overshoot; print until end */
		while (++i <= end)
			write(1, &argv[1][i], 1);
	}
	write(1, "\n", 1);
	return (0);
}
