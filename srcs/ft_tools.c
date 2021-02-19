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