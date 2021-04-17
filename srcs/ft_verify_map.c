/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:54:38 by nbouhada          #+#    #+#             */
/*   Updated: 2021/04/17 09:17:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_verify_map(t_params *params)
{
	if (!ft_verify_walls(params))
		return (0);
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
	if (!params->spawn.wind)
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

int			ft_verify_walls(t_params *params)
{
	int		i;
	int		start;
	int		map;

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
			while (ft_isspace(params->map[i][start]) ||
				params->map[i][start] == '0' || params->map[i][start] == '1')
				start++;
		}
		i++;
	}
	return (1);
}

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
		while (j < (int)ft_strlen(params->tabs.mapcpy[i]) - 1 && params->tabs.mapcpy[i][j])
		{
			params->wallup = 0;
			params->wallright = 0;
			params->wallleft = 0;
			params->walldown = 0;
			while ((ft_isspace(params->tabs.mapcpy[i][j]) || params->tabs.mapcpy[i][j] == '1') &&
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
					if (params->tabs.mapcpy[x][y] == '1' || params->tabs.mapcpy[x][y] == 'X')
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
					if (params->tabs.mapcpy[x][y] == '1' || params->tabs.mapcpy[x][y] == 'X')
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
				if (params->tabs.mapcpy[x][y] == '1' || params->tabs.mapcpy[x][y] == 'X')
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
					if (params->tabs.mapcpy[x][y] == '1' || params->tabs.mapcpy[x][y] == 'X')
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

int			ft_verify_spaces(t_params *params)
{
	int		i;
	int		j;

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
			if (params->map[i][j] == '2')
				params->numSprite += 1;
			j++;
		}
		i++;
	}
	return (1);
}

int			ft_verify_spawn(t_params *params)
{
	int		i;
	int		j;
	int		error;

	i = 0;
	error = 0;
	while (params->map[i])
	{
		j = 0;
		while (params->map[i][j])
		{
			if ((params->map[i][j] == 'S' || params->map[i][j] == 'E' ||
				params->map[i][j] == 'W' || params->map[i][j] == 'N')
					&& (!error))
			{
				params->spawn.wind = params->map[i][j];
				params->spawn.x = j + 0.5;
				params->spawn.y = i + 0.5;
				params->map[i][j] = '0';
				error = 1;
			}
			else if ((params->map[i][j] == 'S' || params->map[i][j] == 'E' ||
				params->map[i][j] == 'W' || params->map[i][j] == 'N')
					&& (error))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			ft_verify_garbage(t_params *params)
{
	int		i;
	int		j;

	i = 0;
	while (params->map[i])
	{
		j = 0;
		while (params->map[i][j])
		{
			if ((params->map[i][j] != 'S' && params->map[i][j] != 'E' &&
				params->map[i][j] != 'W' && params->map[i][j] != 'N' &&
				params->map[i][j] != '1' && params->map[i][j] != '0' &&
					params->map[i][j] != '2' && params->map[i][j] != ' '))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
