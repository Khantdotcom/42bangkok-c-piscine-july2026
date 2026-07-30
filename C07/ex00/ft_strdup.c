/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khant.h <khant.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:50:02 by khahtay           #+#    #+#             */
/*   Updated: 2026/07/30 10:20:56 by khant.h          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*d;
	int		len;

	len = ft_len(src);
	d = (char *)malloc(sizeof(char) * (len + 1));
	if (!d)
	{
		return (NULL);
	}
	i = 0;
	while (src[i])
	{
		d[i] = src[i];
		i++;
	}
	d[i] = '\0';
	return (*(&d));
}

// void	ft_putchar(char *src)
// {
// 	int	i;
// 	i = 0;
// 	while (src[i])
// 	{
// 		write(1, &src[i], 1);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// }
// int	main(void)
// {
// 	char	*s;
// 	char	*d;
// 	s = "I am creative";
// 	d = ft_strdup(s);
// 	ft_putchar(s);
// 	ft_putchar(d);
// 	free(d);
// 	return (0);
// }