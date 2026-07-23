#include <unistd.h>

static int	str_len(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 3)
	{
		i = 0;
		j = 0;
		while (argv[1][i] && argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
				i++;
			j++;
		}
		if (i == str_len(argv[1]))
			write(1, argv[1], i);
	}
	write(1, "\n", 1);
	return (0);
}
