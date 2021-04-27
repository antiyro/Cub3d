/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:58:40 by nbouhada          #+#    #+#             */
/*   Updated: 2021/04/27 12:25:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_init_var(t_params *params)
{
	int v;

	v = 0;
	ft_sprite_pos(params);
	params->ZBuffer = malloc(sizeof(double) * params->x);
	params->spriteOrder = malloc(sizeof(int) * params->numSprite);
	params->spriteDistance = malloc(sizeof(double) * params->numSprite);
	params->ray.drawendtab = malloc(sizeof(int) * params->x);
	params->ray.drawstarttab = malloc(sizeof(int) * params->x);
	params->ray.sidetab = malloc(sizeof(int) * params->x);
	params->ray.colortab = malloc(sizeof(int *) * params->x);
	while (v < params->x)
	{
		params->ray.colortab[v] = malloc(sizeof(int) * params->x);
		v++;
	}
	return (1);
}

int			ft_init_window(t_params *params)
{
	ft_putstr_fd("Opening window", 0);
	ft_loading();
	ft_init_var(params);
	if (!ft_load_text(params) || !ft_load_text2(params))
	{
		ft_error_texture(0);
		return (0);
	}
	params->window.mlx_win =
		mlx_new_window(params->window.mlx, params->x, params->y, "cub3d");
	params->ray.posy = params->spawn.x;
	params->ray.posx = params->spawn.y;
	ft_set_dirplan(params);
	ft_rgbtohex(params);
	if (params->save)
	{
		ft_print_save(params);
		return (1);
	}
	ft_rays(params);
	ft_print_map(params);
	mlx_hook(params->window.mlx_win, 2, 1l<<0, ft_controls, params);
	mlx_hook(params->window.mlx_win, 33, 1L<<17, ft_destroy_window, params);
	ft_putstr_fd("Window opened with success !", 0);
	return (1);
}

int			ft_controls(int key, t_params *params)
{
	if (key == LEFT)
	{
		if (params->map[(int)(params->ray.posx)][(int)(params->ray.posy + params->ray.dirx * SPEED)] == '0')
			params->ray.posy += params->ray.dirx * SPEED;
		
		if (params->map[(int)(params->ray.posx + params->ray.diry * SPEED)][(int)(params->ray.posy)] == '0')
			params->ray.posx -= params->ray.diry * SPEED;
		
	}
	else if (key == RIGHT)
	{
		if (params->map[(int)(params->ray.posx)][(int)(params->ray.posy - params->ray.dirx * SPEED)] == '0')
			params->ray.posy -= params->ray.dirx * SPEED;
		if (params->map[(int)(params->ray.posx - params->ray.diry * SPEED)][(int)(params->ray.posy)] == '0')
			params->ray.posx += params->ray.diry * SPEED;
	}
	else if (key == BACK)
	{
		if (params->map[(int)(params->ray.posx - params->ray.dirx * SPEED)][(int)(params->ray.posy)] == '0')
			params->ray.posx -= params->ray.dirx * SPEED;
		if (params->map[(int)(params->ray.posx)][(int)(params->ray.posy - params->ray.diry * SPEED)] == '0')
			params->ray.posy -= params->ray.diry * SPEED;
	}
	else if (key == FORWARD)
	{
		if (params->map[(int)(params->ray.posx + params->ray.dirx * SPEED)][(int)(params->ray.posy)] == '0')
			params->ray.posx += params->ray.dirx * SPEED;
		if (params->map[(int)(params->ray.posx)][(int)(params->ray.posy + params->ray.diry * SPEED)] == '0')
			params->ray.posy += params->ray.diry * SPEED;
	}
	else if (key == ROT_RIGHT)
	{
		params->ray.oldDirX = params->ray.dirx;
		params->ray.dirx = params->ray.dirx * cos(-ROTSPEED) - params->ray.diry * sin(-ROTSPEED);
		params->ray.diry = params->ray.oldDirX * sin(-ROTSPEED) + params->ray.diry * cos(-ROTSPEED);
		params->ray.oldPlanX = params->ray.planx;
		params->ray.planx = params->ray.planx * cos(-ROTSPEED) - params->ray.plany * sin(-ROTSPEED);
		params->ray.plany = params->ray.oldPlanX * sin(-ROTSPEED) + params->ray.plany * cos(-ROTSPEED);
	}
	else if (key == ROT_LEFT)
	{
		params->ray.oldDirX = params->ray.dirx;
		params->ray.dirx = params->ray.dirx * cos(ROTSPEED) - params->ray.diry * sin(ROTSPEED);
		params->ray.diry = params->ray.oldDirX * sin(ROTSPEED) + params->ray.diry * cos(ROTSPEED);
		params->ray.oldPlanX = params->ray.planx;
		params->ray.planx = params->ray.planx * cos(ROTSPEED) - params->ray.plany * sin(ROTSPEED);
		params->ray.plany = params->ray.oldPlanX * sin(ROTSPEED) + params->ray.plany * cos(ROTSPEED);
	}
	ft_rays(params);
	ft_print_map(params);
	if (key == ESCAPE)
		ft_destroy_window(key, params);
	return (1);
}

int			ft_destroy_window(int key, t_params *params)
{
	(void)key;
	mlx_destroy_window(params->window.mlx, params->window.mlx_win);
	ft_putstr_fd("\nCleaning session", 0);
	ft_loading();
	ft_putstr_fd("Session closed with success !\n", 0);
	exit(1);
	return (0);
}
