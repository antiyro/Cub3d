/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:58:40 by nbouhada          #+#    #+#             */
/*   Updated: 2021/03/20 17:12:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int         ft_init_window(t_params *params)
{
    params->window.mlx_win = mlx_new_window(params->window.mlx, params->x, params->y, "cub3d");
    params->ray.posx = params->spawn.x;
    params->ray.posy = params->spawn.y;
    ft_set_dirplan(params);
    mlx_hook(params->window.mlx_win, 2, 1l<<0, ft_controls, params);
    return (1);
}      

int         ft_controls(int key, t_params *params)
{
    params->window.x = 0;
    params->window.y = 0;
    params->window.mlx_img = mlx_new_image(params->window.mlx, params->x, params->y);
    params->window.mlx_img_data = mlx_get_data_addr(params->window.mlx_img, &params->window.bpp, &params->window.size_line, &params->window.endian);
    ft_rays(params);
    if (key == LEFT)
    {
        if (params->map[(int)(params->ray.posy + params->ray.diry * SPEED)][(int)(params->ray.posx)] == '0')
            params->ray.posy += params->ray.diry * SPEED;
        if (params->map[(int)(params->ray.posy)][(int)(params->ray.posx + params->ray.dirx * SPEED)] == '0')
            params->ray.posx += params->ray.dirx * SPEED;
    }
    else if (key == RIGHT)
    {
        if (params->map[(int)(params->ray.posy - params->ray.diry * SPEED)][(int)(params->ray.posx)] == '0')
            params->ray.posy -= params->ray.diry * SPEED;
        if (params->map[(int)(params->ray.posy)][(int)(params->ray.posx - params->ray.dirx * SPEED)] == '0')
            params->ray.posx -= params->ray.dirx * SPEED;
    }
    else if (key == BACK)
    {
        if (params->map[(int)(params->ray.posy)][(int)(params->ray.posy - params->ray.dirx * SPEED)] == '0')
            params->ray.posy -= params->ray.dirx * SPEED;
        if (params->map[(int)(params->ray.posx - params->ray.diry * SPEED)][(int)(params->ray.posx)] == '0')
            params->ray.posx -= params->ray.diry * SPEED;
    }
    else if (key == FORWARD)
    {
        if(params->map[(int)(params->ray.posy + params->ray.dirx * SPEED)][(int)params->ray.posx] == '0')
            params->ray.posy += params->ray.dirx * SPEED;
        if(params->map[(int)(params->ray.posx + params->ray.diry * SPEED)][(int)(params->ray.posx)] == '0')
            params->ray.posx += params->ray.diry * SPEED;
    }
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
    i = 0;
    while (i < params->x)
    {
        params->ray.camerax = 2 * i / (double)params->x - 1;
        params->ray.raydirx = params->ray.dirx + params->ray.planx * params->ray.camerax;
        params->ray.raydiry = params->ray.diry + params->ray.plany * params->ray.camerax;
        params->ray.mapx = (int)params->ray.posx;
        params->ray.mapy = (int)params->ray.posy;
        params->ray.deltaDistX = fabs(1 / params->ray.dirx);
        params->ray.deltaDistY = fabs(1 / params->ray.diry);
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
        while (params->ray.hit == 0)
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
        params->ray.lineheight = (int)(params->y / params->ray.wallDist);
		params->ray.drawstart = -params->ray.lineheight / 2 + params->y / 2;
		if (params->ray.drawstart < 0)
			params->ray.drawstart = 0;
		params->ray.drawend = params->ray.lineheight / 2 + params->y / 2;
		if (params->ray.drawend >= params->y)
			params->ray.drawend = params->y - 1;
        i++;
        printf("%f\n", params->ray.wallDist);
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
            else if (a == (int)params->ray.posy && b == (int)params->ray.posx)
                ft_print_spawn(params, 255);
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