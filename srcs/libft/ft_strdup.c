/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:36:51 by nbouhada          #+#    #+#             */
/*   Updated: 2020/11/20 20:21:46 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	int		len_s;
	char	*mems;
	int		i;

	i = 0;
	len_s = ft_strlen(s);
	if (!(mems = (char *)malloc(sizeof(char) * len_s + 1)))
		return (NULL);
	while (s[i])
	{
		mems[i] = s[i];
		i++;
	}
	mems[i] = '\0';
	return (mems);
}
