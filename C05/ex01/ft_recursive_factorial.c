#include <unistd.h>
#include <stdio.h>

int	ft_recursive_factorial(int	nb)
{
	if (nb <= 0)
	{
		return (0);
	}
	if (nb == 1)
	{
		return (1);
	}
	return (nb * ft_iterative_factorial(nb-1));
}

// int	main(void){
// 	int i;

// 	i = ft_iterative_factorial(4);
// 	printf("%d",i);
// }