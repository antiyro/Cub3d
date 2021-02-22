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
    else if (!ft_verify_c(params))
        return (0);/*
    else if (!ft_verify_f(params))
        return (0);
    else if (!ft_verify_s(params))
        return (0);*/
    else if (!ft_verify_no(params))
        return (0);
    else if (!ft_verify_so(params))
        return (0);
    else if (!ft_verify_we(params))
        return (0);
    else if (!ft_verify_ea(params))
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
{//FINIR VERIFY C
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
/*
int     ft_verify_f(t_params *params)
{

}

int     ft_verify_s(t_params *params)
{

}
*/
int     ft_verify_we(t_params *params)
{
    char    **tab;

    tab = ft_split(params->we, ' ');
    if (ft_strcmp(tab[0], "WE"))
        ft_error_wind(3, tab[0]);
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