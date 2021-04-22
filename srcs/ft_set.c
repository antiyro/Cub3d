/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:31:34 by nbouhada          #+#    #+#             */
/*   Updated: 2021/04/22 14:35:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	ft_set_dirplan2(params);
}

void	ft_set_dirplan2(t_params *params)
{
	if (params->spawn.wind == 'E')
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

int		ft_load_text(t_params *params, int error)
{
	if (!(params->texture[0].img = (mlx_xpm_file_to_image(params->window.mlx,
	params->linkno, &params->texture[0].width, &params->texture[0].height))))
		error += 1;
	params->texture[0].adr = (int *)(mlx_get_data_addr(params->texture[0].img,
	&params->texture[0].bpp, &params->texture[0].size_line,
	&params->texture[0].endian));
	if (!(params->texture[1].img = (mlx_xpm_file_to_image(params->window.mlx,
	params->linkso, &params->texture[1].width, &params->texture[1].height))))
		error += 1;
	params->texture[1].adr = (int *)(mlx_get_data_addr(params->texture[1].img,
	&params->texture[1].bpp, &params->texture[1].size_line,
	&params->texture[1].endian));
	if (!(params->texture[2].img = (mlx_xpm_file_to_image(params->window.mlx,
	params->linkwe, &params->texture[2].width, &params->texture[2].height))))
		error += 1;
	params->texture[2].adr = (int *)(mlx_get_data_addr(params->texture[2].img,
	&params->texture[2].bpp, &params->texture[2].size_line,
	&params->texture[2].endian));
	if (error)
		ft_error_texture(0);
	if (error)
		return (0);
	return (1);
}

int		ft_load_text2(t_params *params, int error)
{
	if (!(params->texture[3].img = (mlx_xpm_file_to_image(params->window.mlx,
	params->linkea, &params->texture[3].width,
	&params->texture[3].height))))
		error += 1;
	params->texture[3].adr = (int *)(mlx_get_data_addr(params->texture[3].img,
	&params->texture[3].bpp, &params->texture[3].size_line,
	&params->texture[3].endian));
	if (!(params->texture[4].img = (mlx_xpm_file_to_image(params->window.mlx,
	params->obj1, &params->texture[4].width,
	&params->texture[4].height))))
		error += 1;
	params->texture[4].adr = (int *)(mlx_get_data_addr(params->texture[4].img,
	&params->texture[4].bpp, &params->texture[4].size_line,
	&params->texture[4].endian));
	if (error)
		ft_error_texture(0);
	if (error)
		return (0);
	return (1);
}
