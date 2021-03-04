/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 13:27:21 by nbouhada          #+#    #+#             */
/*   Updated: 2021/01/05 17:57:28 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

char				*ft_convert_maj(unsigned int num, int base)
{
	static char		hexadecimal_base[] = "0123456789ABCDEF";
	static char		buffer[50];
	char			*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	while (num != 0)
	{
		*--ptr = hexadecimal_base[num % base];
		num /= base;
	}
	return (ptr);
}

char				*ft_convert_min(unsigned int num, int base)
{
	static char		hexadecimal_base_min[] = "0123456789abcdef";
	static char		my_buffer[50];
	char			*ptr;

	ptr = &my_buffer[49];
	*ptr = '\0';
	while (num != 0)
	{
		*--ptr = hexadecimal_base_min[num % base];
		num /= base;
	}
	return (ptr);
}
