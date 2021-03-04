/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:08:02 by nbouhada          #+#    #+#             */
/*   Updated: 2020/11/18 14:58:22 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *my_s1;
	const unsigned char *my_s2;

	my_s1 = (const unsigned char *)s1;
	my_s2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n)
	{
		if (*my_s1 != *my_s2)
			return (*my_s1 - *my_s2);
		my_s1++;
		my_s2++;
		n--;
	}
	return (0);
}
