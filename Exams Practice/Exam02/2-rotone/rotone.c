#include <unistd.h>

static char	rotone_char(char c)
{
	if (c >= 'a' && c <= 'y')
		return (c + 1);
	if (c == 'z')
		return ('a');
	if (c >= 'A' && c <= 'Y')
		return (c + 1);
	if (c == 'Z')
		return ('A');
	return (c);
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
