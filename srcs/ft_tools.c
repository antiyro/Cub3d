/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:31:34 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/18 13:31:36 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_init_struct(t_params *params)
{
	params->r = 0;
	params->f = 0;
	params->c = 0;
	params->s = 0;
	params->no = 0;
	params->so = 0;
	params->we = 0;
	params->ea = 0;
	params->wallup = 0;
	params->walldown = 0;
	params->wallleft = 0;
	params->wallright = 0;
}

int			ft_rgb(int nb)
{
	if (nb >= 0 && nb <= 255)
		return (1);
	return (0);
}

int			ft_wind(char *str)
{
	int		tmp;

	tmp = 0;
	if (!ft_strcmp(str, LINK1))
		tmp += 1;
	if (!ft_strcmp(str, LINK2))
		tmp += 1;
	if (!ft_strcmp(str, LINK3))
		tmp += 1;
	if (!ft_strcmp(str, LINK4))
		tmp += 1;
	if (tmp)
		return (1);
	return (0);
}

int			ft_s(char *str)
{
	int		tmp;

	tmp = 0;
	if (!ft_strcmp(str, OBJ1))
		tmp += 1;
	if (!ft_strcmp(str, OBJ2))
		tmp += 1;
	if (tmp)
		return (1);
	return (0);
}

void		ft_loading(void)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	c = '.';
	while (i < 3)
	{
		j = 0;
		while (j < 15000000)
			j++;
		write(1, &c, 1);
		i++;
	}
	printf("\n");
}

int		ft_one(char *str)
{
	int i;
	int one;

	i = 0;
	one = 0;
	while (str[i])
	{
		if (str[i] == '1')
		{
			one = 1;
			break ;
		}
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

int		ft_onezero(char *str)
{
	int i;

	i = 1;
	if (str[0] != '1' && str[ft_strlen(str) - 1] != '1')
	while (str[i] && (i < ft_strlen(str) - 2))
	{
		if (str[i] != '0')
			return (0);
			i++;
	}
	return (1);
}

int		ft_checkismap(char *str)
{
	int i;
	int one;
	int space;

	i = 0;
	one = 0;
	if (str[0] == '\0')
		return (0);
	if (ft_one(str))
		return (1);
	while (str[i])
	{
		if ((str[i] != '1') && (str[i] != 'N') && (str[i] != 'S') && (str[i] != 'E') &&
			(str[i] != 'W') && (str[i] != '0') && (str[i] != '2') && (str[i] != ' '))
			return (0);
		if (str[i] == '1')
			one += 1;
		if (str[i] == ' ' && !ft_ispair(one))
			return (0);
		i++;
	}
	if (!one)
		return (0);
	return (1);
}

int		ft_checkisempty(char *str)
{
	if (!str || str[0] == '\0')
		return (1);
	return (0);
}

int		ft_checkisspace(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int 	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\r' || c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0); 
}

char	**ft_tabcpy(char **tab)
{
	int 	i;
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

int		ft_ispair(int n)
{
	if (n % 2 != 0)
		return (0);
	return (1);
}