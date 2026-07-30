#include <unistd.h>
#include <stdio.h>

void ft_print_sep(void)
{
	write(1,", ", 2);
}

int	is_alpha(char c)
{
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
	{
		return (1);
	}
	return (0);
}

char	ft_tolower(char c)
{
	if ((c >= 'A') && (c <= 'Z'))
	{
		return (c + 32);
	}
	return (c);
}

void	ft_putnbr(int n)
{
	char c;
	if (n > 9)
	{
		ft_putnbr(n /10);
	}
	c = (n % 10) + '0';
	write(1, &c, 1);
}


int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	stack[1024];
		int		i;
		int		j;
		unsigned	ch;

		i = 0;
		j = 0;
		while(j < 1024)
			{
				stack[j] = -1;
				j++;
			}
		while(argv[1][i])
		{
			ch = argv[1][i];
			if (is_alpha(ch) == 1)
			{
				ch = ft_tolower(ch);
				{
					if (stack[ch] == -1)
					{
						stack[ch] = 1;
					}
					else
					{
						stack[ch] += 1;
					}
				}
			}
			i++;
		}
		j = 0;
		while(j < 1024)
		{
			if (stack[j] != -1)
			{
				char key = (char)j;
				write(1, &key,1);
				write(1,": ",2);
				ft_putnbr(stack[j]);
				write(1, "\n",1);

			}
			j++;
		}
	}
	write(1, "\n",1);
}
