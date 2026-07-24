#include <unistd.h>

/*
** rev_print - prints argv[1] in reverse order, followed by '\n'.
**
** Algorithm:
**   1. Walk len forward to find string length (len ends up pointing
**      one past the last character, i.e. at '\0').
**   2. Decrement len before each write: --len in the write call.
**      This moves backward through the string from last char to first.
**      Loop stops when len reaches 0.
**
** Key trick: --len (pre-decrement) inside write()
**   - write(1, &argv[1][--len], 1) decrements len THEN uses the new
**     value as the index. So on the first iteration, len goes from
**     strlen to strlen-1, accessing the last real character.
**   - When len becomes 0 (pointing to index 0, the first char), the
**     condition len > 0 is false BEFORE the write fires -> first char
**     is also printed. Wait — actually len > 0 is checked, then --len
**     runs inside write. So when len==1, condition is true, --len=0,
**     we print index 0 (first char). When len==0, loop exits. Correct.
**
** Requirement cases:
**   - argc != 2 -> skip if block, print only '\n'.
**   - Empty string -> len stays 0, inner while immediately false -> '\n'.
*/
int	main(int argc, char **argv)
{
	int	len;

	if (argc == 2)
	{
		len = 0;
		while (argv[1][len])   /* find string length */
			len++;
		/* Print chars from index len-1 down to 0 */
		while (len > 0)
			write(1, &argv[1][--len], 1); /* pre-decrement then index */
	}
	write(1, "\n", 1);
	return (0);
}
