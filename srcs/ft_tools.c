/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:31:34 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/18 13:31:36 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    ft_init_struct(t_params *params)
{
    params->r = 0;
    params->f = 0;
    params->c = 0;
    params->s = 0;
    params->no = 0;
    params->so = 0;
    params->we = 0;
    params->ea = 0;
}

int     ft_rgb(int nb)
{
    if (nb >= 0 && nb <= 255)
        return (1);
    return (0);
}

int     ft_wind(char *str)
{
    int tmp;

    tmp = 0;
    if (!ft_strcmp(str, LINK1))
        tmp += 1;
    if (!ft_strcmp(str, LINK2))
        tmp += 1;
    if (!ft_strcmp(str, LINK3))
        tmp += 1;
    if (!ft_strcmp(str, LINK4))
        tmp += 1; 
    if (tmp)
        return (1);
    return (0);
}