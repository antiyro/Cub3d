/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:58:40 by nbouhada          #+#    #+#             */
/*   Updated: 2021/03/30 11:49:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int         ft_init_window(t_params *params)
{
    params->window.mlx_win = mlx_new_window(params->window.mlx, params->x, params->y, "cub3d");
    params->ray.posy = params->spawn.x;
    params->ray.posx = params->spawn.y;
    ft_set_dirplan(params);
    ft_rgbtohex(params);
    mlx_hook(params->window.mlx_win, 2, 1l<<0, ft_controls, params);
    mlx_hook(params->window.mlx_win, 33, 1L<<17, ft_destroy_window, params);
    return (1);
}      

int         ft_controls(int key, t_params *params)
{
    if (key == LEFT)
    {
        if (params->map[(int)(params->ray.posx)][(int)(params->ray.posy + params->ray.dirx * SPEED)] == '0') 
            params->ray.posy += params->ray.dirx * SPEED;
        if (params->map[(int)(params->ray.posx + params->ray.diry * SPEED)][(int)(params->ray.posy)] == '0')
            params->ray.posx -= params->ray.diry * SPEED;
    }
    else if (key == RIGHT)
    {
        if (params->map[(int)(params->ray.posx)][(int)(params->ray.posy - params->ray.dirx * SPEED)] == '0')
            params->ray.posy -= params->ray.dirx * SPEED;
        if (params->map[(int)(params->ray.posx - params->ray.diry * SPEED)][(int)(params->ray.posy)] == '0')
            params->ray.posx += params->ray.diry * SPEED;
    }
    else if (key == BACK)
    {
        if (params->map[(int)(params->ray.posx - params->ray.dirx * SPEED)][(int)(params->ray.posy)] == '0')
            params->ray.posx -= params->ray.dirx * SPEED;
        if (params->map[(int)(params->ray.posx)][(int)(params->ray.posy - params->ray.diry * SPEED)] == '0')
            params->ray.posy -= params->ray.diry * SPEED;
    }
    else if (key == FORWARD)
    {
        if (params->map[(int)(params->ray.posx + params->ray.dirx * SPEED)][(int)(params->ray.posy)] == '0') 
            params->ray.posx += params->ray.dirx * SPEED;
        if (params->map[(int)(params->ray.posx)][(int)(params->ray.posy + params->ray.diry * SPEED)] == '0')
            params->ray.posy += params->ray.diry * SPEED;
    }
    else if (key == ROT_RIGHT)
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
    }
    ft_rays(params);
    ft_print_map(params);
    mlx_destroy_image(params->window.mlx, params->window.mlx_img);
    if (key == ESCAPE)
        ft_destroy_window(key, params);
    return (1);
}

int       ft_destroy_window(int key, t_params *params)
{
    (void)key;
    mlx_destroy_window(params->window.mlx, params->window.mlx_win);
            exit(1);
    return (1);
}

int         ft_rays(t_params *params)
{
    int i;
    int v;

    i = 0;
    v = 0;
    if (!ft_load_text(params))
        return (0);
    params->ray.drawendtab = malloc(sizeof(int) * params->x);
    params->ray.drawstarttab = malloc(sizeof(int) * params->x);
    params->ray.sidetab = malloc(sizeof(int) * params->x);
    params->ray.colortab = malloc(sizeof(int *) * params->x);
    while(v < params->x)
    {
        params->ray.colortab[v] = malloc(sizeof(int) * params->x);
        v++;
    }
    ft_set_ray(params);
    while (i < params->x)
    {
        params->ray.camerax = 2 * i / (double)params->x - 1;
        params->ray.raydirx = params->ray.dirx + params->ray.planx * params->ray.camerax;
        params->ray.raydiry = params->ray.diry + params->ray.plany * params->ray.camerax;
        params->ray.mapx = (int)params->ray.posx;
        params->ray.mapy = (int)params->ray.posy;
        params->ray.deltaDistX = fabs(1 / params->ray.raydirx);
        params->ray.deltaDistY = fabs(1 / params->ray.raydiry);
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
            params->ray.wallDist = (params->ray.mapx - params->ray.posx + (1 - params->ray.stepx) / 2) / params->ray.raydirx;
        else
            params->ray.wallDist = (params->ray.mapy - params->ray.posy + (1 - params->ray.stepy) / 2) / params->ray.raydiry;
        params->ray.lineheight = (int)(params->y / params->ray.wallDist);
		params->ray.drawstart = -params->ray.lineheight / 2 + params->y / 2;
		if (params->ray.drawstart < 0)
			params->ray.drawstart = 0;
		params->ray.drawend = params->ray.lineheight / 2 + params->y / 2;
		if (params->ray.drawend >= params->y)
			params->ray.drawend = params->y - 1;
        params->text.texNum = 1;
        if (params->ray.sideHit == 0)
            params->text.wallx = params->ray.posy + params->ray.wallDist * params->ray.raydirx;
        else
            params->text.wallx = params->ray.posx + params->ray.wallDist * params->ray.raydiry;
        params->text.wallx = (params->text.wallx - (int)params->text.wallx) * 10;
        params->text.texX = (int)(params->text.wallx * (double)params->texture[0].width);
        if (params->ray.sideHit == 0 && params->ray.raydirx > 0)
            params->text.texX = params->texture[0].width - params->text.texX - 1;
        if (params->ray.sideHit == 1 && params->ray.raydiry < 0)
            params->text.texX = params->texture[0].width - params->text.texX - 1;
        params->text.step = 1.0 * params->texture[0].height / params->ray.lineheight;
        params->text.texPos = (params->ray.drawstart - params->y / 2 + params->ray.lineheight / 2) * params->text.step;
        int g = params->ray.drawstart;
        int j = 0;
        while (g < params->ray.drawend)
        {
            params->text.texY = (int)params->text.texPos & (params->texture[0].height - 1);
            params->text.texPos += params->text.step;
            params->text.color = params->texture[0].adr[params->text.texY * params->texture[0].size_line / 4 + params->text.texX];
            if (params->ray.sideHit == 1)
                params->text.color = (params->text.color >> 1) & 8355711;
            g++;
            params->ray.colortab[j][i] = params->text.color;
            j++;
        }
        params->ray.drawendtab[i] = params->ray.drawend;
        params->ray.drawstarttab[i] = params->ray.drawstart;
        params->ray.sidetab[i] = params->ray.sideHit;
        i++;
    }
    return (1);
}

int        ft_print_map(t_params *params)
{
    int color;
    params->window.x = 0;
    params->window.y = 0;
    params->window.mlx_img = mlx_new_image(params->window.mlx, params->x, params->y);
    params->window.mlx_img_data = (int *)mlx_get_data_addr(params->window.mlx_img, &params->window.bpp, &params->window.size_line, &params->window.endian);
    int j;
    int i;

    i = 0;
    while (i < params->x)
    {
        params->window.y = 0;
        j = 0;
        while (j < params->ray.drawstarttab[i])
        {
            params->window.mlx_img_data[params->window.y * params->window.size_line / 4 + params->window.x] = params->hexac;
            params->window.y++;
            j++;
        }
        while (j < params->ray.drawendtab[i] && j < params->y)
        {
            if (!params->ray.sidetab[i])
                color = params->ray.colortab[j][i];
            else
                color = params->ray.colortab[j][i] / 2;
            params->window.mlx_img_data[params->window.y * params->window.size_line / 4 + params->window.x] = color;
            params->window.y++;
            j++;
        }
        while (j < params->y)
        {
            params->window.mlx_img_data[params->window.y * params->window.size_line / 4 + params->window.x] = params->hexaf;
            params->window.y++;
            j++;
        }
        params->window.x++;
        i++;
    }
    free(params->ray.sidetab);
    free(params->ray.drawstarttab);
    free(params->ray.drawendtab);
    int n = 0;
    while (n < params->x)
    {
        free(params->ray.colortab[n]);
        n++;
    }
    free(params->ray.colortab);
    /*MINIMAP*/
    int a;
    int b;

    a = 0;
    params->window.y = 0;
    while (params->map[a])
    {
        b = 0;
        params->window.x = 0;
        while (params->map[a][b])
        {
            if (params->map[a][b] == '1')
                ft_print_pixel(params, 1000);
            else if (a == (int)params->ray.posx && b == (int)params->ray.posy)
                ft_print_spawn(params, 255);
            else if (params->map[a][b] == '0')
                ft_print_pixel(params, 5000);
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