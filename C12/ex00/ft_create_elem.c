/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khant.h <khant.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:56:17 by khant.h           #+#    #+#             */
/*   Updated: 2026/07/22 10:35:56 by khant.h          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct s_list
{
    void    *content;
    struct s_list *next;
}   t_list;

t_list  *ft_create_elem(void *data)
{

}