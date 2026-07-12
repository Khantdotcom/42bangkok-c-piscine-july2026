/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khant.h <khant.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 11:21:18 by khant.h           #+#    #+#             */
/*   Updated: 2026/07/12 11:21:20 by khant.h          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_ultimate_div_mod(int *a, int *b){
    *a /= *b;
}

int     main(void){
    int a = 2;
    int b = 2;
    ft_ultimate_div_mod(&a,&b);
    char c = a + '0';
    write(1,&c,1);
}