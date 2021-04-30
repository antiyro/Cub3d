/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:27:54 by user42            #+#    #+#             */
/*   Updated: 2021/04/27 13:57:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_sprites(t_params *params)
{
	int		i;

	i = 0;
	while (i < params->numSprite)
	{
		params->spriteOrder[i] = i;
		params->spriteDistance[i] = ((params->ray.posx - params->sprite[i].x) *
		(params->ray.posx - params->sprite[i].x) + (params->ray.posy -
params->sprite[i].y) * (params->ray.posy - params->sprite[i].y));
		i++;
	}
	ft_sort_sprites(params);
	i = 0;
	while (i < params->numSprite)
	{
		ft_sprites1(params, &i);
		ft_sprites2(params);
		i++;
	}
	return (1);
}

void		ft_spritehw(t_params *params, int *vmovescreen)
{
	params->spritet.spriteheight =
		abs((int)(params->y / (params->spritet.transformy))) / vDiv;
	params->spritet.drawstarty =
		-params->spritet.spriteheight / 2 + params->y / 2 + *vmovescreen;
	if (params->spritet.drawstarty < 0)
		params->spritet.drawstarty = 0;
	params->spritet.drawendy =
		params->spritet.spriteheight / 2 + params->y / 2 + *vmovescreen;
	if (params->spritet.drawendy >= params->y)
		params->spritet.drawendy = params->y - 1;
	params->spritet.spritewidth =
		abs((int)(params->y / (params->spritet.transformy))) / uDiv;
	params->spritet.drawstartx =
	-params->spritet.spritewidth / 2 + params->spritet.spritescreenx;
	if (params->spritet.drawstartx < 0)
		params->spritet.drawstartx = 0;
	params->spritet.drawendx =
		params->spritet.spritewidth / 2 + params->spritet.spritescreenx;
	if (params->spritet.drawendx >= params->x)
		params->spritet.drawendx = params->x - 1;
	params->spritet.stripe = params->spritet.drawstartx;
}

void		ft_sprites1(t_params *params, int *i)
{
	params->spritet.spritex = params->sprite[params->spriteOrder[*i]].x -
	params->ray.posx;
	params->spritet.spritey = params->sprite[params->spriteOrder[*i]].y -
	params->ray.posy;
	params->spritet.invdet = 1.0 / (params->ray.planx * params->ray.diry -
	params->ray.dirx * params->ray.plany);
	params->spritet.transformx = params->spritet.invdet * (params->ray.diry
	* params->spritet.spritex - params->ray.dirx * params->spritet.spritey);
	params->spritet.transformy = params->spritet.invdet *
	(-params->ray.plany * params->spritet.spritex + params->ray.planx
	* params->spritet.spritey);
	params->spritet.spritescreenx = (int)((params->x / 2) *
	(1 + params->spritet.transformx / params->spritet.transformy));
}

void		ft_sprites2(t_params *params)
{
	int		vmove;
	int		vmovescreen;

	vmove = params->texture[4].height;
	vmovescreen = (int)(vmove / params->spritet.transformy);
	ft_spritehw(params, &vmovescreen);
	while (params->spritet.stripe < params->spritet.drawendx)
	{
		params->text.texX = (int)(256 * (params->spritet.stripe -
		(-params->spritet.spritewidth / 2 + params->spritet.spritescreenx))
		* params->texture[4].width / params->spritet.spritewidth) / 256;
		ft_sprites3(params, &vmovescreen);
		params->spritet.stripe++;
	}
}

void		ft_sprites3(t_params *params, int *vmovescreen)
{
	int		d;
	int		y;

	if ((params->spritet.transformy > 0) && (params->spritet.stripe > 0)
	&& (params->spritet.stripe < params->x) && (params->spritet.transformy
	< params->ZBuffer[params->spritet.stripe]))
	{
		y = params->spritet.drawstarty;
		while (y < params->spritet.drawendy)
		{
			d = (y - *vmovescreen) * 256 - params->y * 128 +
			params->spritet.spriteheight * 128;
			params->text.texY = ((d * params->texture[4].height) /
			params->spritet.spriteheight) / 256;
			params->text.color = params->texture[4].adr[params->text.texY
			* params->texture[4].size_line / 4 + params->text.texX];
			if ((params->text.color & 0x00FFFFFF) != 0)
				params->window.mlx_img_data[y * params->window.size_line
				/ 4 + params->spritet.stripe] = params->text.color;
			y++;
		}
	}
}
