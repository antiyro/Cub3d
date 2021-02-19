/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:00:07 by nbouhada          #+#    #+#             */
/*   Updated: 2020/11/25 13:00:16 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char				*read_line(char *str, int fd, int *r)
{
	char			buf[BUFFER_SIZE + 1];
	char			*tmp;

	while ((*r = read(fd, &buf, BUFFER_SIZE)) > 0)
	{
		if (*r == -1)
			return (str);
		buf[*r] = 0;
		if (str)
		{
			tmp = ft_strjoin(str, buf);
			free(str);
			str = ft_strdup(tmp);
			free(tmp);
		}
		else
			str = ft_strdup(buf);
		if (ft_strchr(buf, '\n'))
			return (str);
	}
	return (str);
}

char				*get_line(char *str, char **line, int r)
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (i < ft_strlen(str))
	{
		*line = ft_substr(str, 0, i);
		tmp = ft_substr(str, i + 1, ft_strlen(str));
		free(str);
		str = ft_strdup(tmp);
		free(tmp);
	}
	else if (r == 0)
	{
		*line = str;
		str = NULL;
	}
	return (str);
}

int					get_next_line(int fd, char **line)
{
	static char		*str;
	int				r;

	if (fd < 0 || !line)
		return (-1);
	if (BUFFER_SIZE < 1)
		return (-1);
	str = read_line(str, fd, &r);
	if (r == -1)
		return (-1);
	if (r <= 0 && !str)
	{
		*line = ft_strdup("");
		return (r);
	}
	str = get_line(str, line, r);
	if (r <= 0 && !str)
		return (r);
	return (1);
}
