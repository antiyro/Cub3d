/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:31:34 by nbouhada          #+#    #+#             */
/*   Updated: 2021/04/26 14:16:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_sprite_pos(t_params *params)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	params->sprite = malloc(sizeof(t_sprite) * params->numSprite);
	while (params->map[i])
	{
		j = 0;
		while (params->map[i][j])
		{
			if (params->map[i][j] == '2')
			{
				params->sprite[k].x = i + 0.5;
				params->sprite[k].y = j + 0.5;
				k++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

void		ft_sort_sprites(t_params *params)
{
	int		i;
	int		j;

	i = 0;
	while (i < params->numSprite)
	{
		params->sprite[i].first = params->spriteDistance[i];
		params->sprite[i].second = params->spriteOrder[i];
		i++;
	}
	ft_sort_sprites2(params, &i, &j);
	while (i < params->numSprite)
	{
		params->spriteDistance[i] =
			params->sprite[params->numSprite - i - 1].first;
		params->spriteOrder[i] =
			params->sprite[params->numSprite - i - 1].second;
		i++;
	}
}

void		ft_sort_sprites2(t_params *params, int *i, int *j)
{
	int tmp;

	*i = 0;
	while (*i < params->numSprite - 1)
	{
		*j = 0;
		while (*j < params->numSprite - 1)
		{
			if (params->sprite[*j].first > params->sprite[*j + 1].first)
			{
				tmp = params->sprite[*j].second;
				params->sprite[*j].second = params->sprite[*j + 1].second;
				params->sprite[*j + 1].second = tmp;
			}
			if (params->sprite[*j].first > params->sprite[*j + 1].first)
			{
				tmp = params->sprite[*j].first;
				params->sprite[*j].first = params->sprite[*j + 1].first;
				params->sprite[*j + 1].first = tmp;
			}
			*j += 1;
		}
		*i += 1;
	}
	*i = 0;
}

void		ft_destroy_struct(t_params *params)
{
	if (params->r)
		free(params->r);
	if (params->f)
		free(params->f);
	if (params->c)
		free(params->c);
	if (params->s)
		free(params->s);
	if (params->no)
		free(params->no);
	if (params->so)
		free(params->so);
	if (params->we)
		free(params->we);
	if (params->ea)
		free(params->ea);
	if (params->mapfile)
		free(params->mapfile);
	if (params->ray.drawendtab)
		free(params->ray.drawendtab);
	ft_destroy_struct2(params);
	ft_destroy_struct3(params);
}

void		ft_destroy_struct2(t_params *params)
{
	if (params->ray.drawstarttab)
		free(params->ray.drawstarttab);
	if (params->ZBuffer)
		free(params->ZBuffer);
	if (params->ray.sidetab)
		free(params->ray.sidetab);
	if (params->spriteOrder)
		free(params->spriteOrder);
	if (params->spriteDistance)
		free(params->spriteDistance);
	if (params->sprite)
		free(params->sprite);
	if (params->map)
		ft_free_tab(params->map);
}
