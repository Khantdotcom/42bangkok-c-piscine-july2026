/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khahtay <khahtay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:39:42 by wcorrea-          #+#    #+#             */
/*   Updated: 2026/07/28 16:31:47 by khahtay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-'
			|| base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	box[32];
	long	n;
	int		size;
	int		i;

	if (!ft_check_base(base))
		return ;
	size = ft_strlen(base);
	n = nbr;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	i = 0;
	while (n > 0)
	{
		box[i] = base[n % size];
		n = n / size;
		i++;
	}
	while (--i >= 0)
		ft_putchar(box[i]);
}
/* 
int	main(void)
{
	int	n = 42;
	char	*hex = "0123456789abcdef";
	char	*oct = "012345678";
	char	*dec = "0123456789";
	char	*bin = "01";

	write(1, "decimal to decimal: ", 20);
	ft_putnbr_base(n, dec);
	write(1, "\ndecimal to binary: ", 20);
	ft_putnbr_base(n, bin);
	write(1, "\ndecimal to octal: ", 20);
	ft_putnbr_base(n, oct);
	write(1, "\ndecimal to hexadecimal: ", 26);
	ft_putnbr_base(n, hex);
	write(1, "\n", 1);

} */