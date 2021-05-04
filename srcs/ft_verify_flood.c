/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_flood.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antiyro <antiyro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 10:58:55 by antiyro           #+#    #+#             */
/*   Updated: 2021/05/04 19:03:27 by antiyro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_verify_flood(t_params *params)
{
	while (params->flood.i < ft_tablen(params->tabs.mapcpy)
		&& params->tabs.mapcpy[params->flood.i])
	{
		params->flood.j = 0;
		while (params->flood.j <
			(int)ft_strlen(params->tabs.mapcpy[params->flood.i])
			- 1 && params->tabs.mapcpy[params->flood.i][params->flood.j])
		{
			ft_reswall(params);
			if (!ft_verify_flood2(params))
				return (0);
			else if (ft_verify_flood2(params) == 42)
				break ;
			params->flood.x = params->flood.i;
			if (!ft_verify_flood3(params))
				return (0);
			if (!ft_verify_flood4(params))
				return (0);
			if (!ft_verify_flood5(params))
				return (0);
		}
		params->flood.i++;
	}
	ft_free_tab(params->tabs.mapcpy);
	return (1);
}

int		ft_verify_flood2(t_params *params)
{
	while ((ft_isspace(params->tabs.mapcpy[params->flood.i][params->flood.j])
		|| params->tabs.mapcpy[params->flood.i][params->flood.j] == '1') &&
	(params->flood.j < (int)ft_strlen(params->tabs.mapcpy[params->flood.i])))
		params->flood.j++;
	if (!params->tabs.mapcpy[params->flood.i][params->flood.j])
		return (42);
	params->flood.x = params->flood.i;
	params->flood.y = params->flood.j;
	while (params->flood.x >= 0 && params->tabs.mapcpy[params->flood.x])
	{
		if (params->flood.y <
			(int)ft_strlen(params->tabs.mapcpy[params->flood.x]))
		{
			if (params->tabs.mapcpy[params->flood.x][params->flood.y] == '1'
			|| params->tabs.mapcpy[params->flood.x][params->flood.y] == 'X')
				params->wallup = 1;
		}
		else if (!params->wallup)
		{
			ft_free_tab(params->tabs.mapcpy);
			return (0);
		}
		params->flood.x--;
	}
	return (1);
}

int		ft_verify_flood3(t_params *params)
{
	while (params->tabs.mapcpy[params->flood.x])
	{
		if (params->flood.y <
			(int)ft_strlen(params->tabs.mapcpy[params->flood.x]))
		{
			if (params->tabs.mapcpy[params->flood.x][params->flood.y] == '1'
				|| params->tabs.mapcpy[params->flood.x][params->flood.y] == 'X')
				params->walldown = 1;
		}
		else if (!params->walldown)
		{
			ft_free_tab(params->tabs.mapcpy);
			return (0);
		}
		params->flood.x++;
	}
	params->flood.x = params->flood.i;
	while (params->tabs.mapcpy[params->flood.x][params->flood.y])
	{
		if (params->tabs.mapcpy[params->flood.x][params->flood.y] == '1'
			|| params->tabs.mapcpy[params->flood.x][params->flood.y] == 'X')
			params->wallright = 1;
		params->flood.y++;
	}
	return (1);
}

int		ft_verify_flood4(t_params *params)
{
	if (!params->wallright)
	{
		ft_free_tab(params->tabs.mapcpy);
		return (0);
	}
	params->flood.x = params->flood.i;
	params->flood.y = params->flood.j;
	while (params->flood.y >= 0 &&
		params->tabs.mapcpy[params->flood.x][params->flood.y])
	{
		if (params->flood.y <
			(int)ft_strlen(params->tabs.mapcpy[params->flood.x]))
		{
			if (params->tabs.mapcpy[params->flood.x][params->flood.y] == '1'
				|| params->tabs.mapcpy[params->flood.x][params->flood.y] == 'X')
				params->wallleft = 1;
		}
		else if (!params->wallleft)
		{
			ft_free_tab(params->tabs.mapcpy);
			return (0);
		}
		params->flood.y--;
	}
	return (1);
}

int		ft_verify_flood5(t_params *params)
{
	if (params->walldown && params->walldown && params->walldown
		&& params->walldown)
		params->tabs.mapcpy[params->flood.i][params->flood.j] = 'X';
	else
	{
		ft_free_tab(params->tabs.mapcpy);
		return (0);
	}
	if (params->tabs.mapcpy[params->flood.i][params->flood.j])
		params->flood.j++;
	return (1);
}
