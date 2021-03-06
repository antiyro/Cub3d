/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:31:34 by nbouhada          #+#    #+#             */
/*   Updated: 2021/03/06 11:51:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_one(char *str)
{
	int		i;
	int		one;

	i = 0;
	one = 0;
	while (str[i])
	{
		if (str[i] == '1')
			one = 1;
		i++;
	}
	i = 0;
	if (one)
	{
		while (str[i])
		{
			if (str[i] != '1' && !ft_isspace(str[i]))
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (1);
}

int			ft_checkismap(char *str)
{
	int		i;
	int		one;

	i = 0;
	one = 0;
	if (str[0] == '\0')
		return (0);
	if (ft_one(str))
		return (1);
	while (str[i])
	{
		if ((str[i] != '1') && (str[i] != 'N') && (str[i] != 'S') &&
			(str[i] != 'E') && (str[i] != 'W') && (str[i] != '0') &&
				(str[i] != '2') && (str[i] != ' '))
			return (0);
		if (str[i] == '1')
			one += 1;
		i++;
	}
	if (!one)
		return (0);
	return (1);
}

int			ft_checkisspace(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int			ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\r' ||
		c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

char		**ft_tabcpy(char **tab)
{
	int		i;
	char	**tab2;

	i = 0;
	if (!(tab2 = malloc(sizeof(char *) * (ft_tablen(tab) + 1))))
		return (NULL);
	while (tab[i])
	{
		tab2[i] = ft_strdup(tab[i]);
		i++;
	}
	tab2[i] = 0;
	return (tab2);
}
