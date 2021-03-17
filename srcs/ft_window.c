/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:58:40 by nbouhada          #+#    #+#             */
/*   Updated: 2021/03/17 16:55:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int         ft_init_window(t_params *params)
{
    params->window.mlx_win = mlx_new_window(params->window.mlx, params->x, params->y, "cub3d");
    mlx_hook(params->window.mlx_win, 2, 1l<<0, ft_controls, params);
    return (1);
}      

int         ft_controls(int key, t_params *params)
{
    params->window.x = 0;
    params->window.y = 0;
    params->window.mlx_img = mlx_new_image(params->window.mlx, params->x, params->y);
    params->window.mlx_img_data = mlx_get_data_addr(params->window.mlx_img, &params->window.bpp, &params->window.size_line, &params->window.endian);
    //ft_putnbr_fd(key, 0);
    if (key == LEFT && params->map[params->spawn.y][params->spawn.x - 1] != '1')
    {
        params->spawn.x -= 1;
    }
    else if (key == RIGHT && params->map[params->spawn.y][params->spawn.x + 1] != '1')
    {
        params->spawn.x += 1;
    }
    else if (key == BACK && params->map[params->spawn.y + 1][params->spawn.x] != '1')
    {
        params->spawn.y += 1;
    }
    else if (key == FORWARD && params->map[params->spawn.y - 1][params->spawn.x] != '1')
    {
        params->spawn.y -= 1;
    }
    ft_rays(params);
    mlx_destroy_image(params->window.mlx, params->window.mlx_img);
    if (key == ESCAPE)
    {
        mlx_destroy_window(params->window.mlx, params->window.mlx_win);
        exit(1);
    }
    return (1);
}

int         ft_rays(t_params *params)
{
    int i;
    //double time;
    //double oldTime;
    
    params->ray.posx = params->spawn.x;
    params->ray.posy = params->spawn.y;
    ft_set_dir(params);
    ft_set_plan(params);
    i = 0;
    while (i < params->x)
    {
        params->ray.camerax = 2 * i / (double)params->x - 1;
        params->ray.raydirx = params->ray.dirx + params->ray.planx * params->ray.camerax;
        params->ray.raydiry = params->ray.diry + params->ray.plany * params->ray.camerax;
        params->ray.mapx = (int)params->ray.posx;
        params->ray.mapy = (int)params->ray.posy;
        params->ray.deltaDistX = sqrt(1 + (params->ray.raydiry * params->ray.raydiry) / (params->ray.raydirx * params->ray.raydirx));
        params->ray.deltaDistY = sqrt(1 + (params->ray.raydirx * params->ray.raydirx) / (params->ray.raydiry * params->ray.raydiry));
        params->ray.hit = 0;
        if (params->ray.raydirx < 0)
        {
            params->ray.stepx = -1;
            params->ray.sideDistX = (params->ray.posx - params->ray.mapx) * params->ray.deltaDistX;
        }
        else
        {
            params->ray.stepx = 1;
            params->ray.sideDistX = (params->ray.mapx + 1.0 - params->ray.posx) * params->ray.deltaDistX;
        }
        if (params->ray.raydiry < 0)
        {
            params->ray.stepy = -1;
            params->ray.sideDistY = (params->ray.posy - params->ray.mapy) * params->ray.deltaDistY; 
        }
        else
        {
            params->ray.stepy = 1;
            params->ray.sideDistY = (params->ray.mapy + 1.0 - params->ray.posy) * params->ray.deltaDistY;
        }
        while (!params->ray.hit)
        {
            if (params->ray.sideDistX < params->ray.sideDistY)
            {
                params->ray.sideDistX += params->ray.deltaDistX;
                params->ray.mapx += params->ray.stepx;
                params->ray.sideHit = 0;
            }
            else
            {
                params->ray.sideDistY += params->ray.deltaDistY;
                params->ray.mapy += params->ray.stepy;
                params->ray.sideHit = 1;
            }
            if (params->map[params->ray.mapy][params->ray.mapx] > 0)
                params->ray.hit = 1;
        }
        if (params->ray.sideHit == 0)
            params->ray.wallDist = (params->ray.mapx - params->ray.posx + (1 - params->ray.stepx) / 2) / params->ray.dirx;
        else
            params->ray.wallDist = (params->ray.mapy - params->ray.posy + (1 - params->ray.stepy) / 2) / params->ray.diry;
        i++;
    }
    if (!ft_print_map(params))
        return (0);
    return (1);
}

int         ft_print_map(t_params *params)
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