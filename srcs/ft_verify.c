/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:51:17 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/18 13:51:19 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int     ft_verify_params(char *str, t_params *params)
{
    if (!ft_verify_r(params))
        return (0);
    if (!ft_verify_c(params))
        return (0);
    else if (!ft_verify_f(params))
        return (0);
    if (!ft_verify_s(params))
        return (0);
    if (!ft_verify_no(params))
        return (0);
    if (!ft_verify_so(params))
        return (0);
    if (!ft_verify_we(params))
        return (0);
    if (!ft_verify_ea(params))
        return (0);
    return (1);
}

int     ft_verify_r(t_params *params)
{
    char **tab;

    tab = ft_split(params->r, ' ');
    if (ft_tablen(tab) != 3)
    {
        ft_error_r(1);
        return (0);
    }
    if (ft_atoi(tab[1]) && ft_atoi(tab[2]))
    {
        params->x = ft_atoi(tab[1]);
        params->y = ft_atoi(tab[2]);
    }
    else
    {
        ft_error_r(2);
        return (0);
    }
    params->menu += 1;
    return (1);
}

int     ft_verify_c(t_params *params)
{
    char    **tab;
    char    **tab2;

    tab = ft_split(params->c, ' ');
    if (ft_tablen(tab) != 2)
    {
        ft_error_c(1);
        return (0);
    }
    tab2 = ft_split(tab[1], ',');
    if (ft_tablen(tab2) != 3)
    {
        ft_error_c(1);
        return (0);
    }
    if (ft_atoi(tab2[0]) && ft_atoi(tab2[1]) && ft_atoi(tab2[2]))
    {
        params->c_r = ft_atoi(tab2[0]);
        params->c_g = ft_atoi(tab2[1]);
        params->c_b = ft_atoi(tab2[2]);
        if (!ft_rgb(params->c_g) || !ft_rgb(params->c_r) || !ft_rgb(params->c_b))
        {
            ft_error_c(2);
            return (0);
        }
    }
    else
    {
        ft_error_c(2);
        return (0);
    }
    params->menu += 1;
    return (1);
}

int     ft_verify_f(t_params *params)
{
    char    **tab;
    char    **tab2;

    tab = ft_split(params->f, ' ');
    if (ft_tablen(tab) != 2)
    {
        ft_error_f(1);
        return (0);
    }
    tab2 = ft_split(tab[1], ',');
    if (ft_tablen(tab2) != 3)
    {
        ft_error_f(1);
        return (0);
    }
    if (ft_atoi(tab2[0]) && ft_atoi(tab2[1]) && ft_atoi(tab2[2]))
    {
        params->f_r = ft_atoi(tab2[0]);
        params->f_g = ft_atoi(tab2[1]);
        params->f_b = ft_atoi(tab2[2]);
        if (!ft_rgb(params->f_g) || !ft_rgb(params->f_r) || !ft_rgb(params->f_b))
        {
            ft_error_f(2);
            return (0);
        }
    }
    else
    {
        ft_error_f(2);
        return (0);
    }
    params->menu += 1;
    return (1);
}

int     ft_verify_s(t_params *params)
{
    char    **tab;

    if (!params->s)
        return (0);
    tab = ft_split(params->s, ' ');
    if (ft_tablen(tab) != 2)
    {
        ft_error_s(1);
        return (0);
    }
    if (!ft_s(tab[1]))
    {
        ft_error_s(2);
        return (0);
    }
    params->menu += 1;
    return (1);
}

int     ft_verify_we(t_params *params)
{
    char    **tab;

    if (!params->we)
        return (0);
    tab = ft_split(params->we, ' ');
    if (ft_strcmp(tab[0], "WE"))
    {
        ft_error_wind(3, tab[0]);
        return (0);
    }
    if (ft_tablen(tab) != 2)
    {
        ft_error_wind(1, tab[0]);
        return (0);
    }
    if (!ft_wind(tab[1]))
    {
        ft_error_wind(2, tab[0]);
        return (0);
    }
    params->menu += 1;
    return (1);
}

int     ft_verify_ea(t_params *params)
{
    char    **tab;

    if (!params->ea)
        return (0);
    tab = ft_split(params->ea, ' ');
    if (ft_strcmp(tab[0], "EA"))
    {
        ft_error_wind(3, tab[0]);
        return (0);
    }
    if (ft_tablen(tab) != 2)
    {
        ft_error_wind(1, tab[0]);
        return (0);
    }
    if (!ft_wind(tab[1]))
    {
        ft_error_wind(2, tab[0]);
        return (0);
    }
    params->menu += 1;
    return (1);
}

int     ft_verify_no(t_params *params)
{
    char    **tab;

    if (!params->no)
        return (0);
    tab = ft_split(params->no, ' ');
    if (ft_strcmp(tab[0], "NO"))
    {
        ft_error_wind(3, tab[0]);
        return (0);
    }
    if (ft_tablen(tab) != 2)
    {
        ft_error_wind(1, tab[0]);
        return (0);
    }
    if (!ft_wind(tab[1]))
    {
        ft_error_wind(2, tab[0]);
        return (0);
    }
    params->menu += 1;
    return (1);
}

int     ft_verify_so(t_params *params)
{
    char    **tab;

    if (!params->so)
        return (0);
    tab = ft_split(params->so, ' ');
    if (ft_strcmp(tab[0], "SO"))
    {
        ft_error_wind(3, tab[0]);
        return (0);
    }
    if (ft_tablen(tab) != 2)
    {
        ft_error_wind(1, tab[0]);
        return (0);
    }
    if (!ft_wind(tab[1]))
    {
        ft_error_wind(2, tab[0]);
        return (0);
    }
    params->menu += 1;
    return (1);
}

int     ft_verify_all(t_params *params)
{
    if (params->menu != 8)
    {
        if (!params->r)
            ft_error_all(1, "R");
        else if (!params->no)
            ft_error_all(1, "NO");
        else if (!params->so)
            ft_error_all(1, "SO");
        else if (!params->we)
            ft_error_all(1, "WE");
        else if (!params->ea)
            ft_error_all(1, "EA");
        else if (!params->c)
            ft_error_all(1, "C");
        else if (!params->f)
            ft_error_all(1, "F");
        else if (!params->s)
            ft_error_all(1, "S");
        return (0);
    }
    return (1);
}