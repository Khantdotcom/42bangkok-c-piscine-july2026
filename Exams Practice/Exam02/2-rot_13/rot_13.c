#include <unistd.h>

/*
** rot13_char - applies the ROT13 Caesar cipher to one character.
**
** ROT13 shifts a letter 13 positions forward in the alphabet,
** wrapping around. Because the alphabet has 26 letters, applying
** ROT13 twice returns the original letter (it is its own inverse).
**
** Formula: (c - 'a' + 13) % 26 + 'a'
**   c - 'a'       -> position in alphabet: 'a'=0, 'b'=1, ..., 'z'=25
**   + 13           -> shift forward 13 positions
**   % 26           -> wrap around if position exceeds 25
**   + 'a'          -> convert back to ASCII letter
**
** Same formula for uppercase with 'A' as the base.
** Non-alphabetic chars (digits, punctuation, spaces) pass through unchanged.
**
** Requirement cases:
**   - argc != 2    -> print only '\n'.
**   - Empty string -> loop doesn't fire, just '\n'.
*/
static char	rot13_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return ((c - 'a' + 13) % 26 + 'a'); /* shift within lowercase, wrap */
	if (c >= 'A' && c <= 'Z')
		return ((c - 'A' + 13) % 26 + 'A'); /* shift within uppercase, wrap */
	return (c); /* non-letter: no change */
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
			c = rot13_char(argv[1][i]);
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
