/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:46:55 by user42            #+#    #+#             */
/*   Updated: 2021/04/26 15:08:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_rays(t_params *params)
{
	int		i;

	i = 0;
	ft_set_ray(params);
	while (i < params->x)
	{
		ft_rays_throw(params, &i);
		ft_rays_hit(params);
		ft_rays_text(params);
		ft_rays_draw(params, &i);
		i++;
	}
	return (1);
}

void		ft_rays_throw(t_params *params, int *i)
{
	params->ray.camerax = 2 * *i / (double)params->x - 1;
	params->ray.raydirx = params->ray.dirx + params->ray.planx *
		params->ray.camerax;
	params->ray.raydiry = params->ray.diry + params->ray.plany *
		params->ray.camerax;
	params->ray.mapx = (int)params->ray.posx;
	params->ray.mapy = (int)params->ray.posy;
	params->ray.deltaDistX = fabs(1 / params->ray.raydirx);
	params->ray.deltaDistY = fabs(1 / params->ray.raydiry);
	params->ray.hit = 0;
	ft_rays_throw2(params);
}

void		ft_rays_throw2(t_params *params)
{
	if (params->ray.raydirx < 0)
	{
		params->ray.stepx = -1;
		params->ray.sideDistX = (params->ray.posx - params->ray.mapx) *
			params->ray.deltaDistX;
	}
	else
	{
		params->ray.stepx = 1;
		params->ray.sideDistX = (params->ray.mapx + 1.0 - params->ray.posx) *
			params->ray.deltaDistX;
	}
	if (params->ray.raydiry < 0)
	{
		params->ray.stepy = -1;
		params->ray.sideDistY = (params->ray.posy - params->ray.mapy) *
			params->ray.deltaDistY;
	}
	else
	{
		params->ray.stepy = 1;
		params->ray.sideDistY = (params->ray.mapy + 1.0 - params->ray.posy) *
			params->ray.deltaDistY;
	}
}

void		ft_rays_hit(t_params *params)
{
	while (params->ray.hit == 0)
	{
		ft_rays_hit2(params);
	}
	if (params->ray.sideHit == 0)
		params->ray.wallDist = (params->ray.mapx - params->ray.posx +
			(1 - params->ray.stepx) / 2) / params->ray.raydirx;
	else
		params->ray.wallDist = (params->ray.mapy - params->ray.posy +
			(1 - params->ray.stepy) / 2) / params->ray.raydiry;
	params->ray.lineheight = (int)(params->y / params->ray.wallDist);
	params->ray.drawstart = -params->ray.lineheight / 2 + params->y / 2;
	if (params->ray.drawstart < 0)
		params->ray.drawstart = 0;
}

void		ft_rays_hit2(t_params *params)
{
	if (params->ray.sideDistX < params->ray.sideDistY)
	{
		params->ray.sideDistX = params->ray.sideDistX +
			params->ray.deltaDistX;
		params->ray.mapx = params->ray.mapx + params->ray.stepx;
		params->ray.sideHit = 0;
	}
	else
	{
		params->ray.sideDistY = params->ray.sideDistY +
			params->ray.deltaDistY;
		params->ray.mapy = params->ray.mapy + params->ray.stepy;
		params->ray.sideHit = 1;
	}
	if (params->map[params->ray.mapx][params->ray.mapy] == '1')
		params->ray.hit = 1;
}
