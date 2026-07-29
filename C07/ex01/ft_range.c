/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khahtay <khahtay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:21:20 by khahtay           #+#    #+#             */
/*   Updated: 2026/07/29 13:33:13 by khahtay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	range;
	int	i;

	if (min >= max)
	{
		return (NULL);
	}
	range = max - min;
	arr = malloc((sizeof(int)) * (range + 1));
	if (!arr)
	{
		return (NULL);
	}
	i = 0;
	while (i < range && min < max)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}
