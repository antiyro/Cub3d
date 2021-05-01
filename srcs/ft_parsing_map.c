/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:35:08 by nbouhada          #+#    #+#             */
/*   Updated: 2021/04/27 15:56:35 by user42           ###   ########.fr       */
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

int			ft_parsing_map(t_params *params, int fd, int *i)
{
	char	*str;
	int		error;

	error = 0;
	str = 0;
	if (!ft_parsing_map2(fd, str))
		return (0);
	while (get_next_line(fd, &str) > 0)
	{
		if (!ft_parsing_map3(str, i, &error))
			return (0);
	}
	if (ft_checkismap(str))
		*i += 1;
	if (!ft_parsing_map4(params, i, str))
		return (0);
	free(str);
	return (1);
}

int			ft_parsing_map2(int fd, char *str)
{
	ft_putstr_fd("Parsing map matrix", 0);
	ft_loading();
	while (get_next_line(fd, &str) > 0)
	{
		if (ft_checkismap(str))
		{
			free(str);
			break ;
		}
		else if (ft_checkisspace(str))
		{
			free(str);
			continue ;
		}
		else
		{
			ft_error_messages(1);
			free(str);
			return (0);
		}
		free(str);
	}
	return (1);
}

int			ft_parsing_map3(char *str, int *i, int *error)
{
	if (ft_checkismap(str))
	{
		if (*error)
		{
			ft_error_map(1);
			free(str);
			return (0);
		}
		*i += 1;
	}
	else if ((!ft_checkismap(str)))
	{
		if (ft_checkisspace(str))
			*i += 0;
		if (ft_checkisspace(str))
			*error = 1;
		else if (!ft_checkisspace(str))
		{
			ft_error_map(1);
			free(str);
			return (0);
		}
	}
	free(str);
	return (1);
}

int			ft_parsing_map4(t_params *params, int *i, char *str)
{
	if (*i > 0)
	{
		params->map = malloc(sizeof(char *) * (*i + 2));
		params->map[*i + 1] = 0;
	}
	else
	{
		ft_error_map(5);
		free(str);
		return (0);
	}
	ft_putstr_fd("Checking for errors", 0);
	ft_loading();
	if (ft_fill_map(params) && ft_verify_map(params))
		printf("Map parsing done with success !\n");
	else
	{
		free(str);
		ft_destroy_struct(params);
		ft_destroy_tabs(params);
		return (0);
	}
	return (1);
}
