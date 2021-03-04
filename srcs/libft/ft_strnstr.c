/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 09:25:34 by nbouhada          #+#    #+#             */
/*   Updated: 2020/11/18 10:56:02 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *subs, size_t len)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	if (subs[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == subs[j])
		{
			while (i + j < len && big[i + j] == subs[j])
			{
				j++;
				if (!subs[j])
					return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (0);
}
