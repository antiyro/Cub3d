/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:31:34 by nbouhada          #+#    #+#             */
/*   Updated: 2021/04/26 14:39:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_print_pixel(t_params *params, int color)
{
	int		i;
	int		j;
	int		tmpx;
	int		tmpy;

	i = 0;
	tmpx = params->window.x;
	tmpy = params->window.y;
	while (i < 10)
	{
		j = 0;
		params->window.x = tmpx;
		while (j < 10)
		{
			params->window.mlx_img_data[params->window.y *
				params->window.size_line / 4 + params->window.x] = color;
			params->window.x++;
			j++;
		}
		params->window.y++;
		i++;
	}
	params->window.y = tmpy;
	params->window.x = tmpx;
}

char		**ft_tabcpy(char **tab)
{
	int		i;
	char	**tab2;

	i = 0;
	if (!(tab2 = malloc(sizeof(char *) * (ft_tablen(tab) + 1))))
		return (NULL);
	while (tab[i])
	{
		tab2[i] = ft_strdup(tab[i]);
		i++;
	}
	tab2[i] = 0;
	return (tab2);
}

void		ft_destroy_winstruct(t_params *params)
{
	free(params->window.mlx);
	free(params->window.mlx_win);
	free(params->window.mlx_img);
	free(params->window.mlx_img_data);
	ft_free_tab(params->map);
}
