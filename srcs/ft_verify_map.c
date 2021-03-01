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
    {
        printf("Error\n");
        ft_error_map(2);
        return (0);
    }
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

    i = 1;
    j = 1;
    mapcpy = ft_tabcpy(params->map);
    while(i < ft_tablen(mapcpy) - 1 && mapcpy[i])
    {
        j = 1;
        while(j < ft_strlen(mapcpy[i]) - 1 && mapcpy[i][j])
        {
            x = i;
            y = j;
            params->wallup = 0;
            params->wallright = 0;
            params->wallleft = 0;
            params->walldown = 0;
            if (ft_isspace(mapcpy[x][y]))
                j++;
            while (x >= 0 && mapcpy[x])
            {
                if (y < ft_strlen(mapcpy[x]))
                {
                    if (mapcpy[x][y] == '1' || mapcpy[x][y] == 'X')
                        params->wallup = 1;
                }
                else if (!params->wallup)
                    return (0);
                x--;
            }
            x = i;
            while (mapcpy[x])
            {
                if (y < ft_strlen(mapcpy[x]))
                {
                    if (mapcpy[x][y] == '1' || mapcpy[x][y] == 'X')
                        params->walldown = 1;
                }
                else if (!params->walldown)
                    return (0);
                x++;
            }
            x = i;
            while (mapcpy[x][y])
            {
                if (y < ft_strlen(mapcpy[x]))
                {
                    if (mapcpy[x][y] == '1' || mapcpy[x][y] == 'X')
                        params->wallright = 1;
                }
                else if (!params->wallright)
                    return(0);
                y++;
            }
            x = i;
            y = j;
            while (y >= 0 && mapcpy[x][y])
            {
                if (y < ft_strlen(mapcpy[x]))
                {
                    if (mapcpy[x][y] == '1' || mapcpy[x][y] == 'X')
                        params->wallleft = 1;
                }
                else if (!params->wallleft)
                    return (0);
                y--;
            }
            if (params->walldown && params->walldown && params->walldown && params->walldown)
                mapcpy[i][j] = 'X';
            else
                return (0);
            if (mapcpy[i][j])
                j++;
        }
        i++;
    }
    return (1);
}