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
    if (str[i] == 'R' && !params->r)
        params->r = ft_strdup(str);
    else if (str[i] == 'F' && !params->f)
        params->f = ft_strdup(str);
    else if (str[i] == 'C' && !params->c)
        params->c = ft_strdup(str);
    else if (str[i] == 'N' && !params->no)
        params->no = ft_strdup(str);
    else if (str[i] == 'S' && str[i + 1] == 'O' && !params->so)
        params->so = ft_strdup(str);
    else if (str[i] == 'E' && !params->ea)
        params->ea = ft_strdup(str);
    else if (str[i] == 'W' && !params->we)
        params->we = ft_strdup(str);
    else if (str[i] == 'S' && str[i + 1] != 'O' && !params->s)
        params->s = ft_strdup(str);
       
}

void    ft_parsing(t_params *params)
{
    char *str;
    int fd;

    ft_putstr_fd("Opening map.cup", 0);
    ft_loading();
    fd = open("/Users/nbouhada/Documents/cub3d/map.cub", O_RDONLY);
    ft_putstr_fd("Parsing map.cup", 0);
    ft_loading();
    while (get_next_line(fd, &str) > 0)
        ft_fill_params(str, params);
    ft_fill_params(str, params); //CONDITIONNER CA POUR LES FICHIERS VIDES
    ft_putstr_fd("Checking for errors", 0);
    ft_loading();
    ft_verify_all(params);
    if (ft_verify_params(str, params))
        printf("- Paramaters parsing done with success !");
    else
        printf("- Parameters parsing returned error");
}