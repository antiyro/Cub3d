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
    {
        ft_error_map(2);
        return (0);
    }
    if (!ft_verify_flood(params))
    {
        ft_error_map(2);
        return (0);
    }
    if (!ft_verify_spaces(params))
    {
        ft_error_map(3);
        return (0);
    }
    if (!ft_verify_spawn(params))
    {
        ft_error_map(6);
        return (0);
    }
    if (!params->spawn)
    {
        ft_error_map(8);
        return (0);
    }
    if (!ft_verify_garbage(params))
    {
        ft_error_map(7);
        return (0);
    }
    return (1);
}

int    ft_verify_walls(t_params *params)
{
    int i;
    int start;
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
        else
        {
            start++;
            while(ft_isspace(params->map[i][start]) || params->map[i][start] == '0' || params->map[i][start] == '1')
                start++;
        }
        i++;
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
        while(j < (int)ft_strlen(mapcpy[i]) - 1 && mapcpy[i][j])
        {
            params->wallup = 0;
            params->wallright = 0;
            params->wallleft = 0;
            params->walldown = 0;
            while ((ft_isspace(mapcpy[i][j]) || mapcpy[i][j] == '1') && (j < (int)ft_strlen(mapcpy[i])))
                j++;
            if (!mapcpy[i][j])
                break ;
            x = i;
            y = j;
            while (x >= 0 && mapcpy[x])
            {
                if (y < (int)ft_strlen(mapcpy[x]))
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
                if (y < (int)ft_strlen(mapcpy[x]))
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
                if (y < (int)ft_strlen(mapcpy[x]))
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
                if (y < (int)ft_strlen(mapcpy[x]))
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

int     ft_verify_spaces(t_params *params)
{
    int i;
    int j;

    i = 0;
    while (params->map[i])
    {
        j = 0;
        while (params->map[i][j])
        {
            if (params->map[i][j] == '0')
            {
                if (params->map[i][j + 1] == ' ')
                    return (0);
                if (params->map[i][j - 1] == ' ')
                    return (0);
                if (params->map[i + 1][j] == ' ')
                    return (0);
                if (params->map[i - 1][j] == ' ')
                    return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

int     ft_verify_spawn(t_params *params)
{
    int i;
    int j;
    int error;

    i = 0;
    error = 0;
    while (params->map[i])
    {
        j = 0;
        while(params->map[i][j])
        {
            if ((params->map[i][j] == 'S' || params->map[i][j] == 'E' || params->map[i][j] == 'W' || params->map[i][j] == 'N') && (!error))
            {
                params->spawn = params->map[i][j];
                error = 1;
            }
            else if ((params->map[i][j] == 'S' || params->map[i][j] == 'E' || params->map[i][j] == 'W' || params->map[i][j] == 'N') && (error))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int     ft_verify_garbage(t_params *params)
{
    int i;
    int j;

    i = 0;
    while (params->map[i])
    {
        j = 0;
        while(params->map[i][j])
        {
            if ((params->map[i][j] != 'S' && params->map[i][j] != 'E' && params->map[i][j] != 'W' && params->map[i][j] != 'N' &&
                params->map[i][j] != '1' && params->map[i][j] != '0' && params->map[i][j] != '2' && params->map[i][j] != ' '))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}