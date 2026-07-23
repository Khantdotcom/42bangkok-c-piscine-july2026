/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khant.h <khant.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 10:38:08 by khant.h           #+#    #+#             */
/*   Updated: 2026/07/23 21:47:09 by khant.h          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		if (to_find[j] == '\0')
			return (&str[i]);
		if (str[i] == to_find[0])
		{
			while (to_find[j] != '\0')
			{
				if (str[i + j] != to_find[j])
					break ;
				j++;
				if (to_find[j] == '\0')
					return (&str[i]);
			}
		}
		i++;
	}
	if (to_find[0] == '\0')
		return (str);
	return (0);
}
