/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:31:34 by nbouhada          #+#    #+#             */
/*   Updated: 2021/04/22 13:52:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_rgb(int nb)
{
	if (nb >= 0 && nb <= 255)
		return (1);
	return (0);
}

int			ft_wind(char *str)
{
	int		tmp;

	tmp = 0;
	if (!ft_strcmp(str, LINK1))
		tmp += 1;
	if (!ft_strcmp(str, LINK2))
		tmp += 1;
	if (!ft_strcmp(str, LINK3))
		tmp += 1;
	if (!ft_strcmp(str, LINK4))
		tmp += 1;
	if (tmp)
		return (1);
	return (0);
}

int			ft_s(char *str)
{
	int		tmp;

	tmp = 0;
	if (!ft_strcmp(str, OBJ1))
		tmp += 1;
	if (tmp)
		return (1);
	return (0);
}

void		ft_loading(void)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	c = '.';
	while (i < 3)
	{
		j = 0;
		while (j < 15000000)
			j++;
		write(1, &c, 1);
		i++;
	}
	printf("\n");
}

void	ft_print_pixel(t_params *params, int color)
{
	int i;
	int j;
	int tmpx;
	int tmpy;

	i = 0;
	tmpx = params->window.x;
	tmpy = params->window.y;
	while (i < 10)
	{
		j = 0;
		params->window.x = tmpx;
		while (j < 10)
		{
			params->window.mlx_img_data[params->window.y *
				params->window.size_line / 4 + params->window.x] = color;
			params->window.x++;
			j++;
		}
		params->window.y++;
		i++;
	}
	params->window.y = tmpy;
	params->window.x = tmpx;
}

void	ft_print_spawn(t_params *params, int color)
{
	int i;
	int j;
	int tmpx;
	int tmpy;
	int spawnx;
	int spawny;

	i = 0;
	tmpx = params->window.x;
	tmpy = params->window.y;
	spawny = (params->ray.posx - (int)params->ray.posx) * 10;
	spawnx = (params->ray.posy - (int)params->ray.posy) * 10;
	while (i < 10)
	{
		j = 0;
		params->window.x = tmpx;
		while (j < 10)
		{
			params->window.mlx_img_data[params->window.y
				* params->window.size_line / 4 + params->window.x] = color;
			if (i == spawny && j == spawnx)
				params->window.mlx_img_data[params->window.y
					* params->window.size_line / 4 + params->window.x] = 0;
			params->window.x++;
			j++;
		}
		params->window.y++;
		i++;
	}
	params->window.y = tmpy;
	params->window.x = tmpx;
}

int		ft_spawn(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (1);
	return (0);
}

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void		ft_rgbtohex(t_params *params)
{
	params->hexac = 256 * 256 * params->c_r + 256 * params->c_g + params->c_b;
	params->hexaf = 256 * 256 * params->f_r + 256 * params->f_g + params->f_b;
}

int			ft_verify_arg(t_params *params)
{
	if (!params->mapfile)
		return (0);
	params->tabs.tab8 = ft_split(params->mapfile, '.');
	if (ft_tablen(params->tabs.tab8) != 2)
	{
		ft_error_system(1);
		return (0);
	}
	if (ft_strcmp(params->tabs.tab8[1], "cub"))
	{
		ft_error_system(1);
		return (0);
	}
	return (1);
}

int			ft_verify_save(t_params *params)
{
	if (ft_strcmp(params->savearg, "--save"))
	{
		ft_error_system(2);
		return (0);
	}
	params->save = 1;
	return (1);
}

int			ft_count_comas(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count += 1;
		i++;
	}
	if (count != 2)
		return (0);
	return (1);
}
