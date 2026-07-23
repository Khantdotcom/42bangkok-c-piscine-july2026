#include <unistd.h>

int	ft_recursive_power(int nb, int power)
{
	if (power == 0){
		return (1);
	}
	return nb * ft_recursive_power(nb, power-1);
}

int	main(void)
{
	if(ft_recursive_power(0,0) == 1)
	{
		write(1,"Lee",3);
	}
}
