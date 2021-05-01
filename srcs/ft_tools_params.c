/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:31:34 by nbouhada          #+#    #+#             */
/*   Updated: 2021/04/27 14:05:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_rgb(int nb)
{
	if (nb >= 0 && nb <= 255)
		return (1);
	return (0);
}

int			ft_wind(char *str, t_params *params)
{
	params->tabs.tab9 = ft_split(str, '.');
	if (ft_tablen(params->tabs.tab9) != 2)
	{
		ft_free_tab(params->tabs.tab9);
		return (0);
	}
	if (ft_strcmp(params->tabs.tab9[1], "xpm"))
	{
		ft_free_tab(params->tabs.tab9);
		return (0);
	}
	ft_free_tab(params->tabs.tab9);
	return (1);
}

int			ft_count_comas(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count += 1;
		i++;
	}
	if (count != 2)
		return (0);
	return (1);
}

void		ft_rgbtohex(t_params *params)
{
	params->hexac = 256 * 256 * params->c_r + 256 * params->c_g + params->c_b;
	params->hexaf = 256 * 256 * params->f_r + 256 * params->f_g + params->f_b;
}
