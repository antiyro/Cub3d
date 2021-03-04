/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:18:13 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/25 09:47:43 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_char(char c, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1);
	while (ft_check_char(s1[start], (char*)set) >= 0)
		start++;
	if ((end - start) <= 0)
		return (ft_substr(s1, 0, 0));
	while (ft_check_char(s1[end - 1], (char *)set) >= 0)
		end--;
	return (ft_substr(s1, start, end - start));
}
