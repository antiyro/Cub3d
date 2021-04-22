/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:51:17 by nbouhada          #+#    #+#             */
/*   Updated: 2021/04/22 13:46:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_verify_params(t_params *params)
{
	int error;

	error = 0;
	if (!ft_verify_r(params))
		error += 1;
	if (!ft_verify_c(params))
		error += 1;
	else if (!ft_verify_f(params))
		error += 1;
	if (!ft_verify_s(params))
		error += 1;
	if (!ft_verify_no(params))
		error += 1;
	if (!ft_verify_so(params))
		error += 1;
	if (!ft_verify_we(params))
		error += 1;
	if (!ft_verify_ea(params))
		error += 1;
	if (error)
	{
		ft_destroy_tabs(params);
		return (0);
	}
	//ft_destroy_tabs(params);
	return (1);
}

int			ft_verify_r(t_params *params)
{
	int		xmax;
	int		ymax;

	xmax = 0;
	ymax = 0;
	mlx_get_screen_size(params->window.mlx, &xmax, &ymax);
	params->tabs.tab7 = ft_split(params->r, ' ');
	if (ft_tablen(params->tabs.tab7) != 3)
	{
		ft_error_r(1);
		return (0);
	}
	if (ft_atoi(params->tabs.tab7[1]) && ft_atoi(params->tabs.tab7[2]))
	{
		if (ft_atoi(params->tabs.tab7[1]) > 2147483647 || ft_atoi(params->tabs.tab7[2]) > 2147483647)
		{
			ft_error_r(3);
			return (0);
		}
		params->x = (int)ft_atoi(params->tabs.tab7[1]);
		params->y = (int)ft_atoi(params->tabs.tab7[2]);
		if (params->x > xmax)
			params->x = xmax;
		if (params->y > ymax)
			params->y = ymax;
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
	char	*c_r;
	char	*c_g;
	char	*c_b;

	if (!ft_count_comas(params->c))
	{
		ft_error_c(4);
		return (0);
	}
	str = ft_strtrim(params->c, "C ");
	params->tabs.tab = ft_split(str, ',');
	if (ft_tablen(params->tabs.tab) != 3)
	{
		ft_error_c(1);
		return (0);
	}
	c_r = ft_strtrim(params->tabs.tab[0], ", ");
	c_g = ft_strtrim(params->tabs.tab[1], ", ");
	c_b = ft_strtrim(params->tabs.tab[2], ", ");
	if (ft_atoi(c_r) && ft_atoi(c_g) && ft_atoi(c_b))
	{
		if (ft_atoi(c_r) > 2147483647 || ft_atoi(c_g) > 2147483647 || ft_atoi(c_b) > 2147483647)
		{
			ft_error_c(3);
			return (0);
		}
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
	free(str);
	free(c_r);
	free(c_g);
	free(c_b);
	params->menu += 1;
	return (1);
}

int			ft_verify_f(t_params *params)
{
	char	*str;
	char	*f_r;
	char	*f_g;
	char	*f_b;

	if (!ft_count_comas(params->f))
	{
		ft_error_f(4);
		return (0);
	}
	str = ft_strtrim(params->f, "F ");
	params->tabs.tab1 = ft_split(str, ',');
	if (ft_tablen(params->tabs.tab1) != 3)
	{
		ft_error_f(1);
		return (0);
	}
	f_r = ft_strtrim(params->tabs.tab1[0], ", ");
	f_g = ft_strtrim(params->tabs.tab1[1], ", ");
	f_b = ft_strtrim(params->tabs.tab1[2], ", ");
	if (ft_atoi(f_r) && ft_atoi(f_g) && ft_atoi(f_b))
	{
		if (ft_atoi(f_r) > 2147483647 || ft_atoi(f_g) > 2147483647 || ft_atoi(f_b) > 2147483647)
		{
			ft_error_f(3);
			return (0);
		}
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
	free(str);
	free(f_r);
	free(f_g);
	free(f_b);

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
