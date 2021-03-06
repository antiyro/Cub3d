/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:41:59 by nbouhada          #+#    #+#             */
/*   Updated: 2021/03/06 15:19:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(int argc, char **argv)
{
	t_params params;

	(void)argc;
	(void)argv;
	/*if (argc < 1 && argc > 2)
	{
		printf("Error\nWrong number of parameters\nPlease give a map and you");
		printf(" may also want to add the \"--save\" parameter");
	}
	else
	{
		params.mapfile = ft_strdup(argv[1]);*/
		ft_init_struct(&params);
		ft_parsing_params(&params);
	//}
}
