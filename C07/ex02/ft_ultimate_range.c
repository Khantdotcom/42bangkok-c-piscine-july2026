/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khahtay <khahtay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:53:48 by khahtay           #+#    #+#             */
/*   Updated: 2026/07/29 13:58:13 by khahtay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	*range = malloc((sizeof(int)) * (size + 1));
	if (!*range)
	{
		return (-1);
	}
	i = 0;
	while (i < size && min < max)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return (size);
}
