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

void		ft_rays_text(t_params *params)
{
	params->ray.drawend = params->ray.lineheight / 2 + params->y / 2;
	ft_rays_text2(params);
	params->text.wallx -= floor((params->text.wallx));
	params->text.texX = (int)(params->text.wallx *
		(double)(params->texture[params->text.texNum].width));
	if (params->ray.sideHit == 0 && params->ray.raydirx > 0)
		params->text.texX = params->texture[params->text.texNum].width -
			params->text.texX - 1;
	if (params->ray.sideHit == 1 && params->ray.raydiry < 0)
		params->text.texX = params->texture[params->text.texNum].width -
			params->text.texX - 1;
	params->text.step = 1.0 * params->texture[params->text.texNum].height /
		params->ray.lineheight;
	params->text.texPos = (params->ray.drawstart - params->y / 2 +
		params->ray.lineheight / 2) * params->text.step;
}

void		ft_rays_text2(t_params *params)
{
	if (params->ray.drawend >= params->y)
		params->ray.drawend = params->y - 1;
	if ((params->ray.sideHit == 0) && (params->ray.raydirx < 0))
		params->text.texNum = 0;
	else if ((params->ray.sideHit == 0) && (params->ray.raydirx > 0))
		params->text.texNum = 1;
	else if ((params->ray.sideHit == 1) && (params->ray.raydiry < 0))
		params->text.texNum = 2;
	else if ((params->ray.sideHit == 1) && (params->ray.raydiry > 0))
		params->text.texNum = 3;
	if (params->ray.sideHit == 0)
		params->text.wallx = params->ray.posy + params->ray.wallDist *
			params->ray.raydiry;
	else
		params->text.wallx = params->ray.posx + params->ray.wallDist *
			params->ray.raydirx;
}

void		ft_rays_draw(t_params *params, int *i)
{
	int		g;
	int		j;

	g = params->ray.drawstart;
	j = 0;
	while (g < params->ray.drawend)
	{
		params->text.texY = (int)params->text.texPos &
			(params->texture[params->text.texNum].height - 1);
		params->text.texPos += params->text.step;
		params->text.color =
			params->texture[params->text.texNum].adr[params->text.texY
				* params->texture[params->text.texNum].size_line
					/ 4 + params->text.texX];
		if (params->ray.sideHit == 1)
			params->text.color = (params->text.color >> 1) & 8355711;
		g++;
		params->ray.colortab[j][*i] = params->text.color;
		j++;
	}
	params->ray.drawendtab[*i] = params->ray.drawend;
	params->ray.drawstarttab[*i] = params->ray.drawstart;
	params->ray.sidetab[*i] = params->ray.sideHit;
	params->ZBuffer[*i] = params->ray.wallDist;
}
