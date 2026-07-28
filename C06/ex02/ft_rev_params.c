/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khahtay <khahtay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 18:13:34 by khahtay           #+#    #+#             */
/*   Updated: 2026/07/28 20:21:47 by khahtay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_print_each(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_arg_len(char **argv)
{
	int	len;

	len = 0;
	while (argv[len])
	{
		len++;
	}
	return (len - 1);
}

int	main(int argc, char **argv)
{
	int	len;

	(void)argc;
	len = ft_arg_len(argv);
	while (argv[len] && len != 0)
	{
		ft_print_each(argv[len]);
		len--;
	}
}
