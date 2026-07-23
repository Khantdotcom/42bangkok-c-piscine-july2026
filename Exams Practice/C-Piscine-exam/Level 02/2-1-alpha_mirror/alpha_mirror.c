#include <unistd.h>

static char	mirror_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return ('z' - (c - 'a'));
	if (c >= 'A' && c <= 'Z')
		return ('Z' - (c - 'A'));
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
			c = mirror_char(argv[1][i]);
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
