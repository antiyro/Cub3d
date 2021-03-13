/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:58:40 by nbouhada          #+#    #+#             */
/*   Updated: 2021/03/13 14:37:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int             ft_init_window(t_params *params)
{
    //ft_init_struct_window(&params);
    params->window.mlx = mlx_init();
    params->window.mlx_win = mlx_new_window(params->window.mlx, params->x, params->y, "cub3d");
    ft_control(params);
    mlx_loop(params->window.mlx);
    return (1);
}

int         ft_control(t_params *params)
{
    int i;

    i = 1;
    mlx_hook(params->window.mlx_win, 2, 1l<<0, ft_digit, params);
    return (1);
}

int         ft_digit(int key, t_params *params)
{
    params->window.x = 0;
    params->window.y = 0;
    params->window.mlx_img = mlx_new_image(params->window.mlx, params->x, params->y);
    params->window.mlx_img_data = mlx_get_data_addr(params->window.mlx_img, &params->window.bpp, &params->window.size_line, &params->window.endian);
    ft_putnbr_fd(key, 0);
    if (key == LEFT && params->map[params->spawn.x - 1][params->spawn.y] != '1')
    {
        params->spawn.x -= 1;
    }
    else if (key == RIGHT && params->map[params->spawn.x + 1][params->spawn.y] != '1')
    {
        params->spawn.x += 1;
    }
    else if (key == BACK && params->map[params->spawn.x][params->spawn.y + 1] != '1')
    {
        params->spawn.y += 1;
    }
    else if (key == FORWARD && params->map[params->spawn.x][params->spawn.y - 1] != '1')
    {
        params->spawn.y -= 1;
    }
    ft_init_minimap(params);
    mlx_destroy_image(params->window.mlx, params->window.mlx_img);
    return (1);
}

int         ft_init_minimap(t_params *params)
{
    int a;
    int b;

    a = 0;
    while (params->map[a])
    {
        b = 0;
        params->window.x = 0;
        while (params->map[a][b])
        {
            if (params->map[a][b] == '1')
                ft_print_pixel(params, 100);
            else if (a == params->spawn.y && b == params->spawn.x)
                ft_print_pixel(params, 2);
            else if (params->map[a][b] == '0')
                ft_print_pixel(params, 255);
            else if (params->map[a][b] == '2')
                ft_print_pixel(params, 100);
            else if (ft_isspace(params->map[a][b]))
                ft_print_pixel(params, 0);
            b++;
            params->window.x+=10;
        }
        a++;
        params->window.y+=10;
    }
    mlx_put_image_to_window(params->window.mlx, params->window.mlx_win, params->window.mlx_img, 0, 0);
    return (1);
}