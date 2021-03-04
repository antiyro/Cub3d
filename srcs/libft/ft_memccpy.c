/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:47:43 by nbouhada          #+#    #+#             */
/*   Updated: 2020/11/20 20:33:52 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*my_dest;
	unsigned char	*my_src;

	my_dest = (unsigned char *)dest;
	my_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		my_dest[i] = my_src[i];
		if (my_src[i] == (unsigned char)c)
			return ((void *)dest + i + 1);
		i++;
	}
	return (NULL);
}
