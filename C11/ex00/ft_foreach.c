#include <unistd.h>

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// void	ft_putnbr(int nb)
// {
// 	char	c;

// 	if (nb == -2147483648)
// 	{
// 		ft_putchar('-');
// 		ft_putchar('2');
// 		ft_putnbr(147483648);
// 	}
// 	else if (nb < 0)
// 	{
// 		ft_putchar('-');
// 		ft_putnbr(-nb);
// 	}
// 	else if (nb <= 9)
// 	{
// 		c = nb + '0';
// 		ft_putchar(c);
// 	}
// 	else
// 	{
// 		ft_putnbr(nb / 10);
// 		ft_putnbr(nb % 10);
// 	}
// }

void ft_foreach(int *tab, int length, void(*f)(int))
{
	int i;

	i = 0;
	while(i < length)
	{
		(*f)(tab[i]);
		i++;
	}
}

// int main(void)
// {
// 	int tab[5];
// 	int i;
// 	int j;
	
// 	i = 33;
// 	j = 0;
// 	while (j < 4)
// 	{
// 		tab[j] = i;
// 		i++;
// 		j++;
// 	}
// 	ft_foreach(tab, 3, &ft_putnbr);
// }