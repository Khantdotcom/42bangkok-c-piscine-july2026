/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khahtay <khahtay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:58:41 by khahtay           #+#    #+#             */
/*   Updated: 2026/07/29 22:04:54 by khahtay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_get_total_len(int size, char **strs, int sep_len)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	return (len + (sep_len * (size - 1)) + 1);
}

char	*ft_strcpy_end(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest + i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	char	*ptr;
	int		i;

	if (size <= 0)
	{
		res = malloc(sizeof(char));
		if (res)
			res[0] = '\0';
		return (res);
	}
	res = malloc(sizeof(char) * ft_get_total_len(size, strs, ft_strlen(sep)));
	if (!res)
		return (NULL);
	ptr = res;
	i = 0;
	while (i < size)
	{
		ptr = ft_strcpy_end(ptr, strs[i]);
		if (i < size - 1)
			ptr = ft_strcpy_end(ptr, sep);
		i++;
	}
	return (res);
}
