/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:54:38 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/25 10:54:39 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int    ft_verify_map(t_params *params)
{
    if (!ft_verify_walls(params))
        return (0);
    if (!ft_verify_flood(params))
        return (0);
    return (1);
}

int    ft_verify_walls(t_params *params)
{
    int i;
    int start;
    int end;
    int map;

    i = 0;
    map = 0;
    while (params->map[i])
    {
        start = 0;
        while (ft_isspace(params->map[i][start]))
                start++;
        if (params->map[i][start] != '1')
        {
            ft_error_map(2);
            return (0);
        }
        if (params->map[i][ft_strlen(params->map[i]) - 1] != '1')
        {
            ft_error_map(2);
            return (0);
        }
        if (ft_one(params->map[i]))
            map++;
        i++;
    }
    if (map != 2)
    {
        ft_error_map(2);
        return (0);
    }
    return (1);
}

int ft_verify_flood(t_params *params)
{
    char **mapcpy;
    int i;
    int j;
    int x;
    int y;

    i = 0
    j = 0;
    mapcpy = ft_tabcpy(params->map);
    while(mapcpy[i])
    {
        j = 0;
        while(mapcpy[j])
        {
            x = i;
            y = j;
            while () // REALISER L'ALGORITHM FLUID FLOOD
        }
        i++;
    }
    return (1);
}