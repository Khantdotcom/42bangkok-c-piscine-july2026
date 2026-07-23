#include <unistd.h>

int	ft_is_prime(int nb)
{
	if (nb <= 0)
	{
		return (0);
	}
	int i;

	i = 2;
	while(i <= nb/2)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
