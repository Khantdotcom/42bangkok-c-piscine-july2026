#include <unistd.h>

void	ft_putchar(char c)
{
	write(1,&c,1);
}

void	ft_putnbr(int	nb)
{
	if(nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if((nb >= 0 ) && (nb <=9))
	{
		char	c;
		c = nb + '0';
		ft_putchar(c);
	}else{
		ft_putnbr(nb/10);
		ft_putnbr(nb%10);
	}
}

int	ft_atoi(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(str[i])
	{
		if(str[i] == ' ')
		{
			continue;
		}
		if((str[i] == '-') || (str[i] == '+'))
		{
			count++;
		}else{
			break;
		}
		i++;
	}
	if(count << 1 == 0){
		write(1,"-",1);
	}
	while(str[i])
	{

	}
}
