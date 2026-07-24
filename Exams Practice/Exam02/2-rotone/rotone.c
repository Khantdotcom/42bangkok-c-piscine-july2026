#include <unistd.h>

/*
** rotone_char - shifts a letter one position forward in the alphabet.
**
** 'z' wraps to 'a'; 'Z' wraps to 'A'. Case is preserved.
** Non-alphabetic characters are returned unchanged.
**
** Why not use modulo like rot_13?
**   A direct wrap check is simpler for a shift of 1:
**   - 'a'..'y' (not at the boundary) -> just add 1.
**   - 'z' (at the boundary) -> return 'a' explicitly.
**   Same logic for uppercase.
**
** Alternative (modulo form): ((c - 'a' + 1) % 26) + 'a'
**   Both are equivalent; explicit boundary check is more readable here.
**
** Requirement cases:
**   - argc != 2    -> print only '\n'.
**   - Empty string -> loop doesn't fire, just '\n'.
*/
static char	rotone_char(char c)
{
	if (c >= 'a' && c <= 'y')  /* lowercase, not at wrap boundary */
		return (c + 1);
	if (c == 'z')               /* lowercase wrap: z -> a */
		return ('a');
	if (c >= 'A' && c <= 'Y')  /* uppercase, not at wrap boundary */
		return (c + 1);
	if (c == 'Z')               /* uppercase wrap: Z -> A */
		return ('A');
	return (c);                 /* digit, punctuation, space: unchanged */
}

int	main(int argc, char **argv)
{
	int		i;
	char	c;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			c = rotone_char(argv[1][i]);
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
