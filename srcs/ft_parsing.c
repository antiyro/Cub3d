/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:35:08 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/18 11:35:11 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    ft_fill_params(char *str, t_params *params)
{
    int i;

    i = 0;
    if (str[i] == 'R')
        params->r = ft_strdup(str);
    else if (str[i] == 'F')
        params->f = ft_strdup(str);
    else if (str[i] == 'C')
        params->c = ft_strdup(str);
    else if (str[i] == 'S')
        params->s = ft_strdup(str);
    else if (str[i] == 'N')
        params->no = ft_strdup(str);
    else if (str[i] == 'S')
        params->so = ft_strdup(str);
    else if (str[i] == 'E')
        params->ea = ft_strdup(str);
    else if (str[i] == 'W')
        params->we = ft_strdup(str);
    
}

void    ft_parsing(t_params *params)
{
    char *str;
    int fd;

    fd = open("/Users/nbouhada/Documents/cub3d/map.cub", O_RDONLY);
    while (get_next_line(fd, &str) > 0)
        ft_fill_params(str, params);
    ft_fill_params(str, params); //CONDITIONNER CA POUR LES FICHIERS VIDES
    if (ft_verify_params(str, params))
        printf("- Paramaters parsing done with success !");
    else
        printf("- Parameters parsing returned error");
}