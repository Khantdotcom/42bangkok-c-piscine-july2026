#include <unistd.h>

int	main(int argc, char **argv)
{
	int	len;

	if (argc == 2)
	{
		len = 0;
		while (argv[1][len])
			len++;
		while (len > 0)
			write(1, &argv[1][--len], 1);
	}
	write(1, "\n", 1);
	return (0);
}
