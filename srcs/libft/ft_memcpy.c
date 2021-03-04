/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:38:59 by nbouhada          #+#    #+#             */
/*   Updated: 2020/11/20 13:05:40 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*my_dest;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	my_dest = (char *)dest;
	i = 0;
	while (i < n)
	{
		*(char *)my_dest = *(char *)src;
		my_dest++;
		src++;
		i++;
	}
	return (dest);
}
