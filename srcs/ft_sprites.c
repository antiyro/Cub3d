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

int     ft_sprites(t_params *params)
{
	int i;
	int y;
	int d;

	i = 0;
	while (i < params->numSprite)
	{
		params->spriteOrder[i] = i;
		params->spriteDistance[i] = ((params->ray.posx - params->sprite[i].x) * (params->ray.posx - params->sprite[i].x) + (params->ray.posy - params->sprite[i].y) * (params->ray.posy - params->sprite[i].y));
		i++;
	}
	ft_sort_sprites(params);
	i = 0;
	while (i < params->numSprite)
	{
		params->spritetools.spritex = params->sprite[params->spriteOrder[i]].x - params->ray.posx;
		params->spritetools.spritey = params->sprite[params->spriteOrder[i]].y - params->ray.posy;
		params->spritetools.invdet = 1.0 / (params->ray.planx * params->ray.diry - params->ray.dirx * params->ray.plany);
		params->spritetools.transformx = params->spritetools.invdet * (params->ray.diry * params->spritetools.spritex - params->ray.dirx * params->spritetools.spritey);
		params->spritetools.transformy = params->spritetools.invdet * (-params->ray.plany * params->spritetools.spritex + params->ray.planx * params->spritetools.spritey);
		params->spritetools.spritescreenx = (int)((params->x / 2) * (1 + params->spritetools.transformx / params->spritetools.transformy));

		#define vMove params->texture[4].height
		int vMoveScreen = (int)(vMove / params->spritetools.transformy);

		//height
		params->spritetools.spriteheight = abs((int)(params->y / (params->spritetools.transformy))) / vDiv;
		params->spritetools.drawstarty = -params->spritetools.spriteheight / 2 + params->y / 2 + vMoveScreen;
		if (params->spritetools.drawstarty < 0)
			params->spritetools.drawstarty = 0;
		params->spritetools.drawendy = params->spritetools.spriteheight / 2 + params->y / 2 + vMoveScreen;
		if (params->spritetools.drawendy >= params->y)
			params->spritetools.drawendy = params->y - 1;
		//width
		params->spritetools.spritewidth = abs((int)(params->y / (params->spritetools.transformy))) / uDiv;
		params->spritetools.drawstartx = -params->spritetools.spritewidth / 2 + params->spritetools.spritescreenx;
		if (params->spritetools.drawstartx < 0)
			params->spritetools.drawstartx = 0;
		params->spritetools.drawendx = params->spritetools.spritewidth / 2 + params->spritetools.spritescreenx;
		if (params->spritetools.drawendx >= params->x)
			params->spritetools.drawendx = params->x - 1;
		params->spritetools.stripe = params->spritetools.drawstartx;
		while (params->spritetools.stripe < params->spritetools.drawendx)
		{
			params->text.texX = (int)(256 * (params->spritetools.stripe - (-params->spritetools.spritewidth / 2 + params->spritetools.spritescreenx)) * params->texture[4].width / params->spritetools.spritewidth) / 256;
			if ((params->spritetools.transformy > 0) && (params->spritetools.stripe > 0) && (params->spritetools.stripe < params->x) && (params->spritetools.transformy < params->ZBuffer[params->spritetools.stripe]))
			{
				y = params->spritetools.drawstarty;
				while (y < params->spritetools.drawendy)
				{
					d = (y - vMoveScreen) * 256 - params->y * 128 + params->spritetools.spriteheight * 128;
					params->text.texY = ((d * params->texture[4].height) / params->spritetools.spriteheight) / 256;
					params->text.color = params->texture[4].adr[params->text.texY * params->texture[4].size_line / 4 + params->text.texX];
					if ((params->text.color & 0x00FFFFFF) != 0)
						params->window.mlx_img_data[y * params->window.size_line / 4 + params->spritetools.stripe] = params->text.color;
					y++;
				}
			}
			params->spritetools.stripe++;
		}
		i++;
	}
	return (1);
}