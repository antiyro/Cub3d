/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:02:06 by nbouhada          #+#    #+#             */
/*   Updated: 2021/01/14 14:04:52 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int             ft_convlen(unsigned int num)
{
    int i;

    i = 0;
    while(num > 15)
    {
        num /= 16;
        i++;
    }
    return (i);
}

char			*ft_convert(unsigned int num)
{
    static char hexadecimal_base[] = "0123456789abcdef";
    char        *str;
	int			i;

	i = ft_convlen(num);
	if (!(str = malloc(sizeof(char) * (ft_convlen(num) + 1))))
		return (NULL);
	str[i] = '\0';
	if (num == 0)
	{
		str[--i] = '0';
		return (str);
	}
	while (num != 0)
	{
		str[--i] = hexadecimal_base[num % 16];
		num /= 16;
	}
	return (str);
}