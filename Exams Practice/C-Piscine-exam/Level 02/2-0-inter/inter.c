#include <unistd.h>

int	main(int argc, char **argv)
{
	int	seen[256];
	int	in_s2[256];
	int	i;

	i = 0;
	while (i < 256)
	{
		seen[i] = 0;
		in_s2[i] = 0;
		i++;
	}
	if (argc == 3)
	{
		i = 0;
		while (argv[2][i])
			in_s2[(unsigned char)argv[2][i++]] = 1;
		i = 0;
		while (argv[1][i])
		{
			if (!seen[(unsigned char)argv[1][i]] && in_s2[(unsigned char)argv[1][i]])
			{
				write(1, &argv[1][i], 1);
				seen[(unsigned char)argv[1][i]] = 1;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
