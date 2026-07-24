#include <unistd.h>

/*
** aff_z - always prints 'z' followed by '\n'.
**
** Subject rule: whether the string contains 'z' or not, and even
** when argc != 1, the output is ALWAYS "z\n".
** This is the inverse design from aff_a: aff_z never returns just '\n'.
**
** Because all cases produce the same output, no argc check or
** string scan is needed: a single write covers every scenario.
*/
int	main(void)
{
	write(1, "z\n", 2); /* unconditional: always print 'z' + newline */
	return (0);
}
