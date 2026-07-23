#include <unistd.h>
#include <stdio.h>

int	ft_iterative_factorial(int	nb)
{
	if	(nb <= 0)
	{
		return(0);
	}
	int	result;

	result = 1;

	while(nb > 1){
		result *= nb;
		nb--;
	}
	return result;
}

// int	main(void){
// 	int i;

// 	i = ft_iterative_factorial(4);
// 	printf("%d",i);
// }