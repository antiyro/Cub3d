/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:58:40 by nbouhada          #+#    #+#             */
/*   Updated: 2021/03/08 15:17:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int             ft_init_window(t_params *params)
{
    t_window    window;

    ft_init_struct_window(&window);
    window.mlx = mlx_init();
    window.mlx_win = mlx_new_window(window.mlx, params->x, params->y, "cub3d");
    if (!(ft_init_minimap(params, &window)))
        return (0);
    mlx_loop(window.mlx);
    return (1);
}

int         ft_init_minimap(t_params *params, t_window *window)
{
    int a;
    int b;
    int y;
    int x;

    a = 0;
    y = 0;
    while (params->map[a])
    {
        b = 0;
        x = 1;
        while (params->map[a][b])
        {
            if (params->map[a][b] == '1')
                ft_print_pixel(window, x, y, 0xFF0000);
            else if (a == params->spawn.x && b == params->spawn.y)
                ft_print_pixel(window, x, y, 0xFF4500);
            else if (params->map[a][b] == '0')
                ft_print_pixel(window, x, y, 0xFFFFFF);
            else if (params->map[a][b] == '2')
                ft_print_pixel(window, x, y, 0xFFFF00);
            b++;
            x += 10;
        }
        a++;
        y += 10;
    }
    return (1);
}