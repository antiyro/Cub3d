/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:54:30 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/25 10:54:32 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_verify_no(t_params *params)
{
	char	**tab;

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

int			ft_verify_we(t_params *params)
{
	char	**tab;

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

int			ft_verify_ea(t_params *params)
{
	char	**tab;

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

int			ft_verify_so(t_params *params)
{
	char	**tab;

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

int			ft_verify_s(t_params *params)
{
	char	**tab;

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
