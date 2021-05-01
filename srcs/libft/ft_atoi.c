/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antiyro <antiyro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 09:53:22 by nbouhada          #+#    #+#             */
/*   Updated: 2021/05/01 16:56:32 by antiyro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_atoi(const char *nbr)
{
	unsigned int	result;
	int				i;

	result = 0;
	i = 0;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		result = result * 10 + (nbr[i] - 48);
		i++;
	}
	return (result);
}
