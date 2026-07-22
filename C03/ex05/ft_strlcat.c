/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khant.h <khant.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 10:42:36 by khant.h           #+#    #+#             */
/*   Updated: 2026/07/22 10:42:39 by khant.h          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while(dest[i])
	{
		i++;
	}
	j = 0;
	while(src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

void	print_char(char	*s)
{
	int	i;
	
	i = 0;
	while(s[i])
	{
		write(1,&s[i],1);
		i++;
	}
}

// int	main(void)
// {
// 	char dest[50] = "Lee";
// 	char *src = " Pl";

// 	char *result = ft_strcat(dest,src);
// 	print_char(result);
// 	return (0);
// }