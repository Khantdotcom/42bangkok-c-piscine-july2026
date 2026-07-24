#include <unistd.h>

/*
** aff_a - prints the first 'a' found in argv[1], followed by '\n'.
**
** Requirement cases (subject-specified):
**   - argc != 2  -> print "a\n" (not newline alone; subject says 'a' + newline).
**   - 'a' found  -> print "a\n" then return immediately (stop at first hit).
**   - No 'a'     -> print only "\n".
**
** Why return (0) inside the loop?
**   We exit main as soon as we find the first 'a'. This avoids an
**   extra flag variable and keeps the logic flat.
*/
int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)          /* wrong arg count: always print 'a' per spec */
	{
		write(1, "a\n", 2);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == 'a') /* first 'a' found: print and stop */
		{
			write(1, "a\n", 2);
			return (0);
		}
		i++;
	}
	write(1, "\n", 1); /* no 'a' in string: just a newline */
	return (0);
}
