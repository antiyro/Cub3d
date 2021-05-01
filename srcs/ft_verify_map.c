/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antiyro <antiyro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:54:38 by nbouhada          #+#    #+#             */
/*   Updated: 2021/05/01 11:07:52 by antiyro          ###   ########.fr       */
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

	i = 0;
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
	if (!params->spawn.wind)
	{
		ft_error_map(8);
		return (0);
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
