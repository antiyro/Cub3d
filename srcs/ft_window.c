/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:58:40 by nbouhada          #+#    #+#             */
/*   Updated: 2021/03/23 15:41:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int         ft_init_window(t_params *params)
{
    params->window.mlx_win = mlx_new_window(params->window.mlx, params->x, params->y, "cub3d");
    params->ray.posy = params->spawn.x;
    params->ray.posx = params->spawn.y;
    ft_set_dirplan(params);
    mlx_hook(params->window.mlx_win, 2, 1l<<0, ft_controls, params);
    return (1);
}      

int         ft_controls(int key, t_params *params)
{
    if (key == LEFT)
    {
        if(params->map[(int)(params->ray.posx)][(int)(params->ray.posy + params->ray.dirx * SPEED)] == '0') 
            params->ray.posy += params->ray.dirx * SPEED;
        if(params->map[(int)(params->ray.posx + params->ray.diry * SPEED)][(int)(params->ray.posy)] == '0')
            params->ray.posx += params->ray.diry * SPEED;
    }
    else if (key == RIGHT)
    {
        if(params->map[(int)(params->ray.posx)][(int)(params->ray.posy - params->ray.dirx * SPEED)] == '0')
            params->ray.posy -= params->ray.dirx * SPEED;
        if(params->map[(int)(params->ray.posx - params->ray.diry * SPEED)][(int)(params->ray.posy)] == '0')
            params->ray.posx -= params->ray.diry * SPEED;
    }
    else if (key == BACK)
    {
        if(params->map[(int)(params->ray.posx - params->ray.dirx * SPEED)][(int)(params->ray.posy)] == '0')
            params->ray.posx -= params->ray.dirx * SPEED;
        if(params->map[(int)(params->ray.posx)][(int)(params->ray.posy - params->ray.diry * SPEED)] == '0')
            params->ray.posy -= params->ray.diry * SPEED;
    }
    else if (key == FORWARD)
    {
        if(params->map[(int)(params->ray.posx + params->ray.dirx * SPEED)][(int)(params->ray.posy)] == '0') 
            params->ray.posx += params->ray.dirx * SPEED;
        if(params->map[(int)(params->ray.posx)][(int)(params->ray.posy + params->ray.diry * SPEED)] == '0')
            params->ray.posy += params->ray.diry * SPEED;
    }
    /*else if (key == ROT_RIGHT)
    {
        params->ray.oldDirX = params->ray.dirx;
        params->ray.dirx = params->ray.dirx * cos(-ROTSPEED) - params->ray.diry * sin(-ROTSPEED);
        params->ray.diry = params->ray.oldDirX * sin(-ROTSPEED) + params->ray.diry * cos(-ROTSPEED);
        params->ray.oldPlanX = params->ray.planx;
        params->ray.planx = params->ray.planx * cos(-ROTSPEED) - params->ray.plany * sin(-ROTSPEED);
        params->ray.plany = params->ray.oldPlanX * sin(-ROTSPEED) + params->ray.plany * cos(-ROTSPEED);
    }
    else if (key == ROT_LEFT)
    {
        params->ray.oldDirX = params->ray.dirx;
        params->ray.dirx = params->ray.dirx * cos(ROTSPEED) - params->ray.diry * sin(ROTSPEED);
        params->ray.diry = params->ray.oldDirX * sin(ROTSPEED) + params->ray.diry * cos(ROTSPEED);
        params->ray.oldPlanX = params->ray.planx;
        params->ray.planx = params->ray.planx * cos(ROTSPEED) - params->ray.plany * sin(ROTSPEED);
        params->ray.plany = params->ray.oldPlanX * sin(ROTSPEED) + params->ray.plany * cos(ROTSPEED);
    }*/
    ft_rays(params);
    ft_print_map(params);
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

    i = 0;
    params->ray.linetab = malloc(sizeof(int) * params->x);
    params->ray.drawtab = malloc(sizeof(int) * params->x);
    params->ray.sidetab = malloc(sizeof(int) * params->x);
    while (i < params->x)
    {
        params->ray.drawend = 0;
	    params->ray.drawstart = 0;
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
        while (params->ray.hit == 0)
        {
            if (params->ray.sideDistX < params->ray.sideDistY)
            {
                params->ray.sideDistX = params->ray.sideDistX + params->ray.deltaDistX;
                params->ray.mapx = params->ray.mapx + params->ray.stepx;
                params->ray.sideHit = 0;
            }
            else
            {
                params->ray.sideDistY  = params->ray.sideDistY + params->ray.deltaDistY;
                params->ray.mapy = params->ray.mapy + params->ray.stepy;
                params->ray.sideHit = 1;
            }
            if (params->map[params->ray.mapx][params->ray.mapy] == '1')
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
        params->ray.linetab[i] = params->ray.lineheight;
        params->ray.drawtab[i] = params->ray.drawstart;
        params->ray.sidetab[i] = params->ray.sideHit;
        i++;
    }
    return (1);
}

int         ft_print_map(t_params *params)
{
    /*int a;
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
            else if (a == (int)params->ray.posx && b == (int)params->ray.posy)
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
    }*/
    int color = 100;
    params->window.x = 0;
    params->window.y = 0;
    params->window.mlx_img = mlx_new_image(params->window.mlx, params->x, params->y);
    params->window.mlx_img_data = mlx_get_data_addr(params->window.mlx_img, &params->window.bpp, &params->window.size_line, &params->window.endian);
    int j;
    int i;

    i = 0;
    while (i < params->x)
    {
        params->window.y = 0;
        j = 0;
        while (j < params->ray.drawtab[i])
        {
            params->window.y++;
            j++;
        }
        j = 0;
        while (j < params->ray.linetab[i])
        {
            if (!params->ray.sidetab[i])
                color = 500;
            params->window.mlx_img_data[params->window.x * 4 + 4 * params->x * params->window.y] = color;
            params->window.y++;
            j++;
        }
        params->window.x++;
        i++;
    }
    // free(params->ray.sidetab);
    // free(params->ray.linetab);
    // free(params->ray.drawtab);
    /*MINIMAP*/
    
    mlx_put_image_to_window(params->window.mlx, params->window.mlx_win, params->window.mlx_img, 0, 0);
    return (1);
}