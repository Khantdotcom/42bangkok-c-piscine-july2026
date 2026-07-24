#include <unistd.h>

/*
** last_word - prints the last word in argv[1] followed by '\n'.
**
** A word is any non-space/non-tab sequence. Key requirement: trailing
** spaces must be ignored, so we cannot just scan forward.
**
** Algorithm: scan from the RIGHT using two reverse passes.
**
**   Step 1 - Walk i to end of string (after last char), then back one.
**   Step 2 - Skip trailing whitespace: move i left past ' '/'\t'.
**            If the entire string is spaces, i goes to -1 and the
**            print loop below never fires -> correct empty output.
**   Step 3 - Save 'end' = index of last non-space char.
**   Step 4 - Move i left past the word chars to find the start.
**            Loop ends when i hits a space/tab or goes below 0.
**   Step 5 - ++i in the loop condition moves past the delimiter
**            (or corrects the -1 overshoot), then print end-start chars.
**
** Requirement cases:
**   - argc != 2       -> skip if block, print only '\n'.
**   - All spaces/tabs -> end = -1, print loop is never entered.
**   - Single word     -> step 4 exits with i == -1, ++i gives 0.
*/
int	main(int argc, char **argv)
{
	int	i;
	int	end;

	if (argc == 2)
	{
		/* Step 1: reach the end of string */
		i = 0;
		while (argv[1][i])
			i++;
		i--; /* step back onto last char (or -1 for empty string) */
		/* Step 2: skip trailing spaces/tabs */
		while (i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
			i--;
		/* Step 3: mark end of last word */
		end = i;
		/* Step 4: walk left through the last word to find its start */
		while (i >= 0 && argv[1][i] != ' ' && argv[1][i] != '\t')
			i--;
		/* Step 5: ++i positions us on first char of word, print to end */
		while (++i <= end)
			write(1, &argv[1][i], 1);
	}
	write(1, "\n", 1);
	return (0);
}
