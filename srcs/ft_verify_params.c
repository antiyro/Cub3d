/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:51:17 by nbouhada          #+#    #+#             */
/*   Updated: 2021/03/13 15:20:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_verify_params(t_params *params)
{
	if (!ft_verify_r(params))
		return (0);
	if (!ft_verify_c(params))
		return (0);
	else if (!ft_verify_f(params))
		return (0);
	if (!ft_verify_s(params))
		return (0);
	if (!ft_verify_no(params))
		return (0);
	if (!ft_verify_so(params))
		return (0);
	if (!ft_verify_we(params))
		return (0);
	if (!ft_verify_ea(params))
		return (0);
	return (1);
}

int			ft_verify_r(t_params *params)
{
	char	**tab;

	tab = ft_split(params->r, ' ');
	if (ft_tablen(tab) != 3)
	{
		ft_error_r(1);
		return (0);
	}
	if (ft_atoi(tab[1]) && ft_atoi(tab[2]))
	{
		if (ft_atoi(tab[1]) > 2147483647 || ft_atoi(tab[2]) > 2147483647)
		{
			ft_error_r(3);
			return (0);
		}
		params->x = (int)ft_atoi(tab[1]);
		params->y = (int)ft_atoi(tab[2]);
	}
	else
	{
		ft_error_r(2);
		return (0);
	}
	params->menu += 1;
	return (1);
}

int			ft_verify_c(t_params *params)
{
	char	*str;
	char	**tab;
	char	*c_r;
	char	*c_g;
	char	*c_b;

	str = ft_strtrim(params->c, "C ");
	tab = ft_split(str, ',');
	if (ft_tablen(tab) != 3)
	{
		ft_error_c(1);
		return (0);
	}
	c_r = ft_strtrim(tab[0], ", ");
	c_g = ft_strtrim(tab[1], ", ");
	c_b = ft_strtrim(tab[2], ", ");
	if (ft_atoi(c_r) && ft_atoi(c_g) && ft_atoi(c_b))
	{
		params->c_r = (int)ft_atoi(c_r);
		params->c_g = (int)ft_atoi(c_g);
		params->c_b = (int)ft_atoi(c_b);
		if (!ft_rgb(params->c_g) || !ft_rgb(params->c_r) ||
			!ft_rgb(params->c_b))
		{
			ft_error_c(2);
			return (0);
		}
	}
	else
	{
		ft_error_c(2);
		return (0);
	}
	params->menu += 1;
	return (1);
}

int			ft_verify_f(t_params *params)
{
	char	*str;
	char	**tab;
	char	*f_r;
	char	*f_g;
	char	*f_b;

	str = ft_strtrim(params->f, "F ");
	tab = ft_split(str, ',');
	if (ft_tablen(tab) != 3)
	{
		ft_error_f(1);
		return (0);
	}
	f_r = ft_strtrim(tab[0], ", ");
	f_g = ft_strtrim(tab[1], ", ");
	f_b = ft_strtrim(tab[2], ", ");
	if (ft_atoi(f_r) && ft_atoi(f_g) && ft_atoi(f_b))
	{
		params->f_r = (int)ft_atoi(f_r);
		params->f_g = (int)ft_atoi(f_g);
		params->f_b = (int)ft_atoi(f_b);
		if (!ft_rgb(params->f_g) || !ft_rgb(params->f_r) ||
			!ft_rgb(params->f_b))
		{
			ft_error_f(2);
			return (0);
		}
	}
	else
	{
		ft_error_f(2);
		return (0);
	}
	params->menu += 1;
	return (1);
}

int			ft_verify_all(t_params *params, int *count)
{
	if (*count != 8)
	{
		printf("Error\n");
		if (!params->r)
			ft_error_all(1, "R");
		if (!params->no)
			ft_error_all(1, "NO");
		if (!params->so)
			ft_error_all(1, "SO");
		if (!params->we)
			ft_error_all(1, "WE");
		if (!params->ea)
			ft_error_all(1, "EA");
		if (!params->c)
			ft_error_all(1, "C");
		if (!params->f)
			ft_error_all(1, "F");
		if (!params->s)
			ft_error_all(1, "S");
		return (0);
	}
	return (1);
}
