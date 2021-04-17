/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:58:40 by nbouhada          #+#    #+#             */
/*   Updated: 2021/04/17 11:05:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int         ft_init_var(t_params *params)
{
    params->sprite = malloc(sizeof(t_sprite) * params->numSprite);
    params->spriteOrder = malloc(sizeof(int) * params->numSprite);
    params->spriteDistance = malloc(sizeof(double) * params->numSprite);
    params->ray.drawendtab = malloc(sizeof(int) * params->x);
    params->ray.drawstarttab = malloc(sizeof(int) * params->x);
    params->ray.sidetab = malloc(sizeof(int) * params->x);
    params->ray.colortab = malloc(sizeof(int *) * params->x);
    int v = 0;
    while(v < params->x)
    {
        params->ray.colortab[v] = malloc(sizeof(int) * params->x);
        v++;
    }
    return (1);
}

int         ft_init_window(t_params *params)
{
    ft_putstr_fd("Opening window", 0);
	ft_loading();
    ft_init_var(params);
    if (!ft_load_text(params))
        return (0);
    params->window.mlx_win = mlx_new_window(params->window.mlx, params->x, params->y, "cub3d");
    params->ray.posy = params->spawn.x;
    params->ray.posx = params->spawn.y;
    ft_set_dirplan(params);
    ft_rgbtohex(params);
    ft_print_map(params);
    mlx_hook(params->window.mlx_win, 2, 1l<<0, ft_controls, params);
    mlx_hook(params->window.mlx_win, 33, 1L<<17, ft_destroy_window, params);
    ft_putstr_fd("Window opened with success !", 0);
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
    if (key == ESCAPE)
        ft_destroy_window(key, params);
    return (1);
}

int       ft_destroy_window(int key, t_params *params)
{
    (void)key;
    mlx_destroy_window(params->window.mlx, params->window.mlx_win);
    ft_putstr_fd("\nCleaning session", 0);
    ft_loading();
    ft_putstr_fd("Session closed with success !\n", 0);
    exit(1);
    return (1);
}

int         ft_rays(t_params *params)
{
    int i;
    double ZBuffer[params->x];

    i = 0;
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
        if ((params->ray.sideHit == 0) && (params->ray.raydirx < 0))
            params->text.texNum = 0;
        else if ((params->ray.sideHit == 0) && (params->ray.raydirx > 0))
            params->text.texNum = 1;
        else if ((params->ray.sideHit == 1) && (params->ray.raydiry < 0))
            params->text.texNum = 2;
        else if ((params->ray.sideHit == 1) && (params->ray.raydiry > 0))
            params->text.texNum = 3;
        if (params->ray.sideHit == 0)
            params->text.wallx = params->ray.posy + params->ray.wallDist * params->ray.raydiry;
        else
            params->text.wallx = params->ray.posx + params->ray.wallDist * params->ray.raydirx;
        params->text.wallx -= floor((params->text.wallx));
        params->text.texX = (int)(params->text.wallx * (double)(params->texture[params->text.texNum].width));
        if (params->ray.sideHit == 0 && params->ray.raydirx > 0)
            params->text.texX = params->texture[params->text.texNum].width - params->text.texX - 1;
        if (params->ray.sideHit == 1 && params->ray.raydiry < 0)
            params->text.texX = params->texture[params->text.texNum].width - params->text.texX - 1;
        params->text.step = 1.0 * params->texture[params->text.texNum].height / params->ray.lineheight;
        params->text.texPos = (params->ray.drawstart - params->y / 2 + params->ray.lineheight / 2) * params->text.step;
        int g = params->ray.drawstart;
        int j = 0;
        while (g < params->ray.drawend)
        {
            params->text.texY = (int)params->text.texPos & (params->texture[params->text.texNum].height - 1);
            params->text.texPos += params->text.step;
            params->text.color = params->texture[params->text.texNum].adr[params->text.texY * params->texture[params->text.texNum].size_line / 4 + params->text.texX];
            if (params->ray.sideHit == 1)
                params->text.color = (params->text.color >> 1) & 8355711;
            g++;
            params->ray.colortab[j][i] = params->text.color;
            j++;
        }
        params->ray.drawendtab[i] = params->ray.drawend;
        params->ray.drawstarttab[i] = params->ray.drawstart;
        params->ray.sidetab[i] = params->ray.sideHit;
        ZBuffer[i] = params->ray.wallDist;
        i++;
    }
    ft_sprites(params, ZBuffer);
    return (1);
}

int     ft_sprites(t_params *params, double *Zbuffer)
{
    int i;
    int y;
    int d;
    int stripe;
    int drawStartY;
    int drawEndY;
    int drawStartX;
    int drawEndX;
    int spriteScreenX;
    int spriteHeight;
    int spriteWidth;
    double spriteX;
    double spriteY;
    double invDet;
    double transformX;
    double transformY;

    i = 0;
    while (i < params->numSprite)
    {
        params->spriteOrder[i] = i;
        params->spriteDistance[i] = ((params->ray.posx - params->sprite[i].x) * (params->ray.posx - params->sprite[i].x) + (params->ray.posy - params->sprite[i].y)
            * (params->ray.posy - params->sprite[i].y));
        i++;
    }
    ft_sortSprites(params->spriteOrder, params->spriteDistance, params->numSprite, params);
    i = 0;
    while (i < params->numSprite)
    {
        spriteX = params->sprite[params->spriteOrder[i]].x - params->ray.posx;
        spriteY = params->sprite[params->spriteOrder[i]].y - params->ray.posy;
        invDet = 1.0 / (params->ray.planx * params->ray.diry - params->ray.dirx * params->ray.plany);
        transformX = invDet * (params->ray.diry * spriteX - params->ray.dirx * spriteY);
        transformY = invDet * (-params->ray.plany * spriteX + params->ray.planx * spriteY);
        spriteScreenX = (int)((params->x / 2) * (1 + transformX / transformY));
        //height
        spriteHeight = abs((int)(params->y / transformY));
        drawStartY = -spriteHeight / 2 + params->y / 2;
        if (drawStartY < 0)
            drawStartY = 0;
        drawEndY = spriteHeight / 2 + params->y / 2;
        if (drawEndY >= params->y)
            drawEndY = params->y - 1;
        //width
        spriteWidth = abs((int)(params->y / transformY));
        drawStartX = -spriteWidth / 2 + spriteScreenX;
        if (drawStartX < 0)
            drawStartX = 0;
        drawEndX = spriteWidth / 2 + spriteScreenX;
        if (drawEndX >= params->x)
            drawEndX = params->x - 1;
        stripe = drawStartX;
        while (stripe < drawEndX)
        {
            params->text.texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) + params->texture[4].width / spriteWidth) / 256;
            if (transformY > 0 && stripe > 0 && stripe < params->x && transformY < Zbuffer[stripe])
            {
                y = drawStartY;
                while (y < drawEndY)
                {
                    d = (y) * 256 - params->y * 128 + spriteHeight * 128;
                    params->text.texY = ((d * params->texture[4].height) / spriteHeight) / 256;
                    params->text.color = params->texture[4].adr[params->text.texY * params->texture[params->text.texNum].size_line / 4 + params->text.texX];
                    if ((params->text.color & 0x00FFFFFF) != 0)
                        params->ray.colortab[y][stripe] = params->text.color;
                    y++;
                }
            }
            stripe++;
        }
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
    int k;

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
        k = 0;
        while (j < params->ray.drawendtab[i] && j < params->y)
        {
            if (!params->ray.sidetab[i])
                color = params->ray.colortab[k][i];
            else
                color = params->ray.colortab[k][i];
            params->window.mlx_img_data[params->window.y * params->window.size_line / 4 + params->window.x] = color;
            params->window.y++;
            k++;
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
    /*MINIMAP
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
    }*/
    mlx_put_image_to_window(params->window.mlx, params->window.mlx_win, params->window.mlx_img, 0, 0);
    mlx_destroy_image(params->window.mlx, params->window.mlx_img);
    return (1);
}