/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_exist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:57:05 by nbouhada          #+#    #+#             */
/*   Updated: 2020/12/16 16:04:04 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_file_exist(char *name)
{
	FILE *file;

	if ((file = fopen(name, "r")))
	{
		fclose(file);
		return (1);
	}
	return (0);
}
