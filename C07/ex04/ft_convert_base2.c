/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khahtay <khahtay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:43:22 by wcorrea-          #+#    #+#             */
/*   Updated: 2026/07/29 22:19:53 by khahtay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_digit_places(int nbr, char *base, int i)
{
	int			size;
	long int	n;

	size = ft_strlen(base);
	n = nbr;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= size)
	{
		n /= size;
		i++;
	}
	i++;
	return (i);
}

void	ft_putnbr_base(int nbr, char *base, char *converted)
{
	int		size;
	long	n;
	int		first;
	int		last;

	size = ft_strlen(base);
	last = ft_digit_places(nbr, base, 0);
	n = nbr;
	first = 0;
	if (n < 0)
	{
		converted[0] = '-';
		n *= -1;
		first++;
	}
	last--;
	while (n >= size)
	{
		converted[last] = base[n % size];
		n /= size;
		last--;
	}
	if (n < size)
		converted[first] = base[n];
}
/* 
int main(void)
{
    char c1[32];
    char c2[32];
    char c3[32];
    char c4[32];
	char	*hex = "0123456789abcdef";
	char	*oct = "012345678";
	char	*dec = "0123456789";
	char	*bin = "01";
	int	n = 42;
    
    ft_putnbr_base(n, bin, c1);
    printf("%d in binary: %s\n", n, c1);
	ft_putnbr_base(n, oct, c2);
    printf("%d in octal: %s\n", n, c2);
	ft_putnbr_base(n, dec, c3);
    printf("%d in decimal: %s\n", n, c3);
	ft_putnbr_base(n, hex, c4);
    printf("%d in hexadecimal: %s\n", n, c4);
} */
