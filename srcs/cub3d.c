/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:41:59 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/18 10:42:01 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(void)
{
	t_params params;

	ft_init_struct(&params);
	ft_parsing_params(&params);

    int k = 0;
	if (params.map)
	{
		while(params.map[k])
		{
			printf("%s\n", params.map[k]);
			k++;
		}
	}
}
