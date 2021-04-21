/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:41:59 by nbouhada          #+#    #+#             */
/*   Updated: 2021/04/21 15:46:30 by user42           ###   ########.fr       */
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
		params.mapfile = ft_strdup(argv[1]);
		if (!ft_verify_arg(&params))
		{
			ft_free_tab(params.tabs.tab8);
			return (0);
		}
		if (argc == 3)
		{
			params.savearg = ft_strdup(argv[2]);
			if (!ft_verify_save(&params))
			{
				free(params.savearg);
				return (0);
			}
		}
		printf("%s\n", params.mapfile);
		params.window.mlx = mlx_init();
		if (!ft_parsing_params(&params))
		{
			mlx_destroy_display(params.window.mlx);
			return (0);
		}
		if (!ft_init_window(&params))
			return (0);
		mlx_loop(params.window.mlx);
		free(params.ray.sidetab);
    	free(params.ray.drawstarttab);
    	free(params.ray.drawendtab);
    	int n = 0;
    	while (n < params.x)
    	{
    	    free(params.ray.colortab[n]);
    	    n++;
   		}
    	free(params.ray.colortab);
		printf("%d\n", params.save);
		if (params.r)
			ft_destroy_struct(&params);
		mlx_destroy_display(params.window.mlx);
	}
}
