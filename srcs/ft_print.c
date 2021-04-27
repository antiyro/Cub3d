/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:58:40 by nbouhada          #+#    #+#             */
/*   Updated: 2021/04/27 09:55:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_print_map(t_params *params)
{
	int color;
	params->window.x = 0;
	params->window.y = 0;
	params->window.mlx_img = mlx_new_image(params->window.mlx, params->x, params->y);
	params->window.mlx_img_data = (int *)mlx_get_data_addr(params->window.mlx_img, &params->window.bpp, &params->window.size_line, &params->window.endian);
	int j;
	int i;
	int k;

	i = 0;
	while (i < params->x)
	{
		params->window.y = 0;
		j = 0;
		while (j < params->ray.drawstarttab[i])
		{
			params->window.mlx_img_data[params->window.y * params->window.size_line / 4 + params->window.x] = params->hexac;
			params->window.y++;
			j++;
		}
		k = 0;
		while (j < params->ray.drawendtab[i] && j < params->y)
		{
			color = params->ray.colortab[k][i];
			params->window.mlx_img_data[params->window.y * params->window.size_line / 4 + params->window.x] = color;
			params->window.y++;
			k++;
			j++;
		}
		while (j < params->y)
		{
			params->window.mlx_img_data[params->window.y * params->window.size_line / 4 + params->window.x] = params->hexaf;
			params->window.y++;
			j++;
		}
		j = 0;
		params->window.x++;
		i++;
	}
	ft_sprites(params);
	mlx_put_image_to_window(params->window.mlx, params->window.mlx_win, params->window.mlx_img, 0, 0);
	mlx_destroy_image(params->window.mlx, params->window.mlx_img);
	return (1);
}

void		ft_print_save(t_params *params)
{
	int fd;

	fd = open("save.bpm", O_WRONLY);
	ft_rays(params);
	ft_print_map(params);
}
