/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khant.h <khant.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 10:38:08 by khant.h           #+#    #+#             */
/*   Updated: 2026/07/22 20:52:01 by khant.h          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len(char *s)
{
	int i;

	i = 0;
	while(s[i])
	{
		i++;
	}
	return (i);
}
char	*strstr(char *str, char *to_find)
{
	int	 i;
	int	len;

	len = ft_len(to_find);
	i = 0;
	while(str[i])
	{
		int	j;

		j = 0;
		while(to_find[j]) 
			if(to_find[j] == str[i])
			{
				continue;
			}
	}
}
