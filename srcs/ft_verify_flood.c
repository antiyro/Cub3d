/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_flood.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antiyro <antiyro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 10:58:55 by antiyro           #+#    #+#             */
/*   Updated: 2021/05/01 11:11:00 by antiyro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_verify_flood(t_params *params)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 1;
	params->tabs.mapcpy = ft_tabcpy(params->map);
	while (i < ft_tablen(params->tabs.mapcpy) && params->tabs.mapcpy[i])
	{
		j = 0;
		while (j < (int)ft_strlen(params->tabs.mapcpy[i])
			- 1 && params->tabs.mapcpy[i][j])
		{
			params->wallup = 0;
			params->wallright = 0;
			params->wallleft = 0;
			params->walldown = 0;
			while ((ft_isspace(params->tabs.mapcpy[i][j])
				|| params->tabs.mapcpy[i][j] == '1') &&
				(j < (int)ft_strlen(params->tabs.mapcpy[i])))
				j++;
			if (!params->tabs.mapcpy[i][j])
				break ;
			x = i;
			y = j;
			while (x >= 0 && params->tabs.mapcpy[x])
			{
				if (y < (int)ft_strlen(params->tabs.mapcpy[x]))
				{
					if (params->tabs.mapcpy[x][y] == '1'
						|| params->tabs.mapcpy[x][y] == 'X')
						params->wallup = 1;
				}
				else if (!params->wallup)
				{
					ft_free_tab(params->tabs.mapcpy);
					return (0);
				}
				x--;
			}
			x = i;
			while (params->tabs.mapcpy[x])
			{
				if (y < (int)ft_strlen(params->tabs.mapcpy[x]))
				{
					if (params->tabs.mapcpy[x][y] == '1'
						|| params->tabs.mapcpy[x][y] == 'X')
						params->walldown = 1;
				}
				else if (!params->walldown)
				{
					ft_free_tab(params->tabs.mapcpy);
					return (0);
				}
				x++;
			}
			x = i;
			while (params->tabs.mapcpy[x][y])
			{
				if (params->tabs.mapcpy[x][y] == '1'
					|| params->tabs.mapcpy[x][y] == 'X')
					params->wallright = 1;
				y++;
			}
			if (!params->wallright)
			{
				ft_free_tab(params->tabs.mapcpy);
				return (0);
			}
			x = i;
			y = j;
			while (y >= 0 && params->tabs.mapcpy[x][y])
			{
				if (y < (int)ft_strlen(params->tabs.mapcpy[x]))
				{
					if (params->tabs.mapcpy[x][y] == '1'
						|| params->tabs.mapcpy[x][y] == 'X')
						params->wallleft = 1;
				}
				else if (!params->wallleft)
				{
					ft_free_tab(params->tabs.mapcpy);
					return (0);
				}
				y--;
			}
			if (params->walldown && params->walldown && params->walldown
				&& params->walldown)
				params->tabs.mapcpy[i][j] = 'X';
			else
			{
				ft_free_tab(params->tabs.mapcpy);
				return (0);
			}
			if (params->tabs.mapcpy[i][j])
				j++;
		}
		i++;
	}
	ft_free_tab(params->tabs.mapcpy);
	return (1);
}
