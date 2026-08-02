#include <stdlib.h>
// #include <stdio.h>

// int ft_sqr(int i)
// {
// 	return (i * i);
// }
int	*ft_map(int *tab, int length, int(*f)(int))
{
	int *arr;
	int i;
	
	i = 0;
	arr = (int *)malloc(sizeof(int) * length);
	while (i < length)
	{
		arr[i] = (*f)(tab[i]);
		i++;
	}
	return (arr);
}

// int main(void)
// {
// 	int i;
// 	i = 0;
// 	int tab[5] = {1,2,3,4,5};
// 	int *arr = ft_map(tab, 5, *ft_sqr);
// 	while (i < 5)
// 	{
// 		printf("%d",arr[i]);
// 		i++;
// 	}
// }
