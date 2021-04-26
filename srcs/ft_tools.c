/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:31:34 by nbouhada          #+#    #+#             */
/*   Updated: 2021/04/26 14:14:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_loading(void)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	c = '.';
	while (i < 3)
	{
		j = 0;
		while (j < 15000000)
			j++;
		write(1, &c, 1);
		i++;
	}
	printf("\n");
}

void		ft_free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void		ft_rgbtohex(t_params *params)
{
	params->hexac = 256 * 256 * params->c_r + 256 * params->c_g + params->c_b;
	params->hexaf = 256 * 256 * params->f_r + 256 * params->f_g + params->f_b;
}

int			ft_verify_arg(t_params *params)
{
	if (!params->mapfile)
		return (0);
	params->tabs.tab8 = ft_split(params->mapfile, '.');
	if (ft_tablen(params->tabs.tab8) != 2)
	{
		ft_error_system(1);
		return (0);
	}
	if (ft_strcmp(params->tabs.tab8[1], "cub"))
	{
		ft_error_system(1);
		return (0);
	}
	return (1);
}

int			ft_verify_save(t_params *params)
{
	if (ft_strcmp(params->savearg, "--save"))
	{
		ft_error_system(2);
		return (0);
	}
	params->save = 1;
	return (1);
}
