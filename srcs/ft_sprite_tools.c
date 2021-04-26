/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:31:34 by nbouhada          #+#    #+#             */
/*   Updated: 2021/04/26 11:50:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_sprite_pos(t_params *params)
{
	int		i;
	int		j;
	int 	k;

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
				params->sprite[k].x = i;
				params->sprite[k].y = j;
				k++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

void		ft_sortSprites(t_params *params)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < params->numSprite)
	{
		params->sprite[i].first = params->spriteDistance[i];
		params->sprite[i].second = params->spriteOrder[i];
		i++;
	}
	i = 0;
	while (i < params->numSprite - 1)
	{
		j = 0;
		while (j < params->numSprite - 1)
		{
			if (params->sprite[j].first > params->sprite[j + 1].first)
			{
				tmp = params->sprite[j].second;
				params->sprite[j].second = params->sprite[j + 1].second;
				params->sprite[j + 1].second = tmp;
			}
			if (params->sprite[j].first > params->sprite[j + 1].first)
			{
				tmp = params->sprite[j].first;
				params->sprite[j].first = params->sprite[j + 1].first;
				params->sprite[j + 1].first = tmp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < params->numSprite)
	{
		params->spriteDistance[i] = params->sprite[params->numSprite - i - 1].first;
		params->spriteOrder[i] = params->sprite[params->numSprite - i - 1].second;
		i++;
	}
}