/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:31:34 by nbouhada          #+#    #+#             */
/*   Updated: 2021/03/22 16:08:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_init_struct(t_params *params)
{
	params->r = 0;
	params->f = 0;
	params->c = 0;
	params->s = 0;
	params->no = 0;
	params->so = 0;
	params->we = 0;
	params->ea = 0;
	params->x = 0;
	params->y = 0;
	params->wallup = 0;
	params->walldown = 0;
	params->wallleft = 0;
	params->wallright = 0;
	params->spawn.wind = 0;
	params->spawn.x = 0;
	params->spawn.y = 0;
	params->mapfile = 0;
	params->window.mlx = 0;
	params->window.mlx_win = 0;
	params->window.mlx_img = 0;
	params->window.mlx_img_data = 0;
	params->window.bpp = 0;
	params->window.size_line = 0;
	params->window.endian = 0;
	params->window.x = 0;
	params->window.y = 0;
	ft_set_ray(params);
}

void		ft_destroy_struct(t_params *params)
{
	free(params->r);
	free(params->f);
	free(params->c);
	free(params->s);
	free(params->no);
	free(params->so);
	free(params->we);
	free(params->ea);
	ft_free_tab(params->map);
	free(params->mapfile);
	free(params->window.mlx);
	free(params->window.mlx_win);
	free(params->window.mlx_img);
	free(params->window.mlx_img_data);
}

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
	if (!ft_strcmp(str, OBJ2))
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
			params->window.mlx_img_data[params->window.x * 4 + 4 * params->x * params->window.y] = color;
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
			params->window.mlx_img_data[params->window.x * 4 + 4 * params->x * params->window.y] = color;
			if (i == spawny && j == spawnx)
			{
				params->window.mlx_img_data[params->window.x * 4 + 4 * params->x * params->window.y] = 0;
						
			}
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

void	ft_set_dirplan(t_params *params)
{
	if (params->spawn.wind == 'N')
	{
		params->ray.dirx = -1;
		params->ray.diry = 0;
		params->ray.planx = 0;
		params->ray.plany = 0.66;
	}
	else if (params->spawn.wind == 'S')
	{
		params->ray.dirx = 1;
		params->ray.diry = 0;
		params->ray.planx = 0;
		params->ray.plany = -0.66;
	}
	else if (params->spawn.wind == 'E')
	{
		params->ray.dirx = 0;
		params->ray.diry = 1;
		params->ray.planx = 0.66;
		params->ray.plany = 0;
	}
	else if (params->spawn.wind == 'W')
	{
		params->ray.dirx = 0;
		params->ray.diry = -1;
		params->ray.planx = -0.66;
		params->ray.plany = 0;
	}
}

void	ft_set_ray(t_params *params)
{
	params->ray.lineheight = 0;
	params->ray.mapx = 0;
	params->ray.mapy = 0;
	params->ray.planx = 0;
	params->ray.plany = 0;
	params->ray.posx = 0;
	params->ray.posy = 0;
	params->ray.raydirx = 0;
	params->ray.raydiry = 0;
	params->ray.sideDistX = 0;
	params->ray.sideDistY = 0;
	params->ray.sideHit = 0;
	params->ray.stepx = 0;
	params->ray.stepy = 0;
	params->ray.wallDist = 0;
	params->ray.oldDirX = 0;
	params->ray.oldPlanX = 0;
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
}