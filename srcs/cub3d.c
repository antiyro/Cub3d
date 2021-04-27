/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:41:59 by nbouhada          #+#    #+#             */
/*   Updated: 2021/04/27 15:58:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(int argc, char **argv)
{
	t_params params;

	(void)argc;
	(void)argv;
	if (argc < 1 && argc > 3)
	{
		printf("Error\nWrong number of parameters\nPlease give a map and you");
		printf(" may also want to add the \"--save\" parameter");
	}
	else
	{
		ft_init_struct(&params);
		if (!ft_arg_init(&params, argc, argv))
			return (0);
		params.window.mlx = mlx_init();
		if (!ft_parsing_params(&params))
		{
			ft_clean(&params);
			return (0);
		}
		ft_init_window(&params);
		mlx_loop(params.window.mlx);
		ft_clean(&params);
	}
	return (0);
}

int		ft_arg_init(t_params *params, int argc, char **argv)
{
	params->mapfile = ft_strdup(argv[1]);
	if (!ft_verify_arg(params))
	{
		ft_free_tab(params->tabs.tab8);
		return (0);
	}
	if (argc == 3)
	{
		params->savearg = ft_strdup(argv[2]);
		if (!ft_verify_save(params))
		{
			free(params->savearg);
			return (0);
		}
	}
	return (1);
}

void	ft_clean(t_params *params)
{
	int i;

	i = 0;
	if (params->ray.colortab)
	{
		while (i < params->x)
		{
			free(params->ray.colortab[i]);
			i++;
		}
		free(params->ray.colortab);
	}
	ft_destroy_struct(params);
	ft_destroy_tabs(params);
	mlx_destroy_display(params->window.mlx);
}
