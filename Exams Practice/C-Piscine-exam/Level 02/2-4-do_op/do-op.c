#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	res;

	if (argc != 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	a = atoi(argv[1]);
	b = atoi(argv[3]);
	res = 0;
	if (argv[2][1] != '\0')
		printf("0");
	else if (argv[2][0] == '+')
		res = a + b;
	else if (argv[2][0] == '-')
		res = a - b;
	else if (argv[2][0] == '*')
		res = a * b;
	else if (argv[2][0] == '/')
		res = (b == 0) ? 0 : a / b;
	else if (argv[2][0] == '%')
		res = (b == 0) ? 0 : a % b;
	else
		printf("0");
	if (argv[2][1] == '\0' && (argv[2][0] == '+' || argv[2][0] == '-'
			|| argv[2][0] == '*' || argv[2][0] == '/' || argv[2][0] == '%'))
		printf("%d", res);
	write(1, "\n", 1);
	return (0);
}
