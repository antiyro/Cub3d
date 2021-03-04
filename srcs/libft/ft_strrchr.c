/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:04:31 by nbouhada          #+#    #+#             */
/*   Updated: 2020/11/18 15:05:52 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (*s == '\0' && !c)
		return ((char *)s);
	while (*s)
	{
		s++;
		i++;
	}
	while (*s != (char)c && i != 0)
	{
		s--;
		i--;
	}
	if (i == 0 && s[0] != (char)c)
		return (0);
	else
		return ((char *)s);
}
