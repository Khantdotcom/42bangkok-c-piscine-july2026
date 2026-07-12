/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khant.h <khant.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 11:35:51 by khant.h           #+#    #+#             */
/*   Updated: 2026/07/12 11:45:04 by khant.h          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int     ft_strlen(char *str){
    int count = 0;
    while (*str != '\0'){
        count += 1;
        str++;
    }
    return (count);
}

int     main(void){
    char c[] = "I love Pann";
    int count = ft_strlen(c);
    char cc = count + '0';
    write(1,&cc,1);
}