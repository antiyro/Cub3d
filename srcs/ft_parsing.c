/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:35:08 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/18 11:35:11 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_fill_params(char *str, t_params *params, int *count)
{
	int		i;

	i = 0;
	if (str[i] == '\0')
		*count -= 1;
	else if (str[i] == 'R' && !params->r)
		params->r = ft_strdup(str);
	else if (str[i] == 'F' && !params->f)
		params->f = ft_strdup(str);
	else if (str[i] == 'C' && !params->c)
		params->c = ft_strdup(str);
	else if (str[i] == 'N' && !params->no)
		params->no = ft_strdup(str);
	else if (str[i] == 'S' && str[i + 1] == 'O' && !params->so)
		params->so = ft_strdup(str);
	else if (str[i] == 'E' && !params->ea)
		params->ea = ft_strdup(str);
	else if (str[i] == 'W' && !params->we)
		params->we = ft_strdup(str);
	else if (str[i] == 'S' && str[i + 1] != 'O' && !params->s)
		params->s = ft_strdup(str);
	else if (str[i] == '1' && *count != 8)
		*count = 424242;
	*count += 1;
}

void	ft_fill_map(char *str, t_params *params)
{
	int i;
	int count;
	int fd;

	i = 0;
	fd = open("/Users/nbouhada/Documents/cub3d/map.cub", O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		if (ft_checkismap(str))
		{
			params->map[i] = ft_strdup(str);
			i++;
		}
	}
	if (ft_checkismap(str) && i > 0)
	{
		params->map[i] = ft_strdup(str);
		i++;
	}
	if (i != ft_tablen(params->map))
		ft_error_map(4);
}

void		ft_parsing_params(t_params *params)
{
	char	*str;
	int		count;
	int		fd;

	count = 0;
	ft_putstr_fd("Opening map.cup", 0);
	ft_loading();
	fd = open("/Users/nbouhada/Documents/cub3d/map.cub", O_RDONLY);
	ft_putstr_fd("Parsing map parameters", 0);
	ft_loading();
	while (get_next_line(fd, &str) > 0 && count != 8)
		ft_fill_params(str, params, &count);
	if (count > 1)
		ft_fill_params(str, params, &count);
	ft_putstr_fd("Checking for errors", 0);
	ft_loading();
	if (count > 424240)
	{
		ft_error_map(1);
		return ;
	}
	ft_verify_all(params, &count);
	if (count == 8)
	{
		if (ft_verify_params(str, params))
			printf("Paramaters parsing done with success !\n");
		else
		{
			printf("- Parameters parsing returned error\n");
			return ;
		}
	}
	else
	{
		printf("- Invalid parameter detected in map.cub\n");
		return ;
	}
	ft_parsing_map(params, fd);
}

void		ft_parsing_map(t_params *params, int fd)
{
	char *str;
	int i;
	int error;
	int map;

	error = 0;
	map = 1;
	i = 0;
	ft_putstr_fd("Parsing map matrix", 0);
	ft_loading();
	while (get_next_line(fd, &str) > 0)
	{
		if (ft_checkismap(str))
			break ;
	}
	while (get_next_line(fd, &str) > 0)
	{
		if (ft_checkismap(str))
		{
			if (ft_one(str))
				map -= 1;
			i++;
		}
		else if ((!ft_checkismap(str) && (!map)))
		{
			if (ft_checkisspace(str))
				i += 0;
			else
			{
				ft_error_map(1);
				error = 1;
				break ;
			}
		}
		else if ((!ft_checkismap(str) && (map)))
		{
			ft_error_map(1);
			error = 1;
			break ;
		}
	}
	if (ft_checkismap(str))
		i++;
	params->map = malloc(sizeof(char *) * (i + 2));
	params->map[i + 1] = 0;
	ft_fill_map(str, params);
	if (!error && ft_verify_map(params))
		printf("Map parsing done with success !\n");
}
