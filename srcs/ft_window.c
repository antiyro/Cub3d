/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:58:40 by nbouhada          #+#    #+#             */
/*   Updated: 2021/04/26 14:47:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int         ft_init_var(t_params *params)
{
    ft_sprite_pos(params);
    params->ZBuffer = malloc(sizeof(double) * params->x);
    params->spriteOrder = malloc(sizeof(int) * params->numSprite);
    params->spriteDistance = malloc(sizeof(double) * params->numSprite);
    params->ray.drawendtab = malloc(sizeof(int) * params->x);
    params->ray.drawstarttab = malloc(sizeof(int) * params->x);
    params->ray.sdrawendtab = malloc(sizeof(int) * params->x);
    params->ray.sdrawstarttab = malloc(sizeof(int) * params->x);
    params->ray.sidetab = malloc(sizeof(int) * params->x);
    params->ray.colortab = malloc(sizeof(int *) * params->x);
    params->ray.sdrawstartxtab = malloc(sizeof(int) * params->numSprite);
    int v = 0;
    while(v < params->x)
    {
        params->ray.colortab[v] = malloc(sizeof(int) * params->x);
        v++;
    }
    params->ray.scolortab = malloc(sizeof(int *) * params->x);
    int k = 0;
    while(k < params->x)
    {
        params->ray.scolortab[k] = malloc(sizeof(int) * params->x);
        k++;
    }
    return (1);
}

int         ft_init_window(t_params *params)
{
    ft_putstr_fd("Opening window", 0);
	ft_loading();
    ft_init_var(params);
    if (!ft_load_text(params, 0))
        return (0);
	if (!ft_load_text2(params, 0))
		return (0);
    params->window.mlx_win = mlx_new_window(params->window.mlx, params->x, params->y, "cub3d");
    params->ray.posy = params->spawn.x;
    params->ray.posx = params->spawn.y;
    ft_set_dirplan(params);
    ft_rgbtohex(params);
    if (params->save)
    {
        ft_print_save(params);
        return (1);
    }
    ft_rays(params);
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
    return (0);
}

int     ft_sprites(t_params *params)
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
        params->spriteDistance[i] = ((params->ray.posx - params->sprite[i].x) * (params->ray.posx - params->sprite[i].x) + (params->ray.posy - params->sprite[i].y) * (params->ray.posy - params->sprite[i].y));
        i++;
    }
    ft_sort_sprites(params);
    i = 0;
    while (i < params->numSprite)
    {
        spriteX = params->sprite[params->spriteOrder[i]].x - params->ray.posx;
        spriteY = params->sprite[params->spriteOrder[i]].y - params->ray.posy;
        invDet = 1.0 / (params->ray.planx * params->ray.diry - params->ray.dirx * params->ray.plany);
        transformX = invDet * (params->ray.diry * spriteX - params->ray.dirx * spriteY);
        transformY = invDet * (-params->ray.plany * spriteX + params->ray.planx * spriteY);
        spriteScreenX = (int)((params->x / 2) * (1 + transformX / transformY));
        
        #define uDiv 1
        #define vDiv 1
        #define vMove params->texture[4].height
        int vMoveScreen = (int)(vMove / transformY);

        //height
        spriteHeight = abs((int)(params->y / (transformY))) / vDiv;
        drawStartY = -spriteHeight / 2 + params->y / 2 + vMoveScreen;
        if (drawStartY < 0)
            drawStartY = 0;
        drawEndY = spriteHeight / 2 + params->y / 2 + vMoveScreen;
        if (drawEndY >= params->y)
            drawEndY = params->y - 1;
        //width
        spriteWidth = abs((int)(params->y / (transformY))) / uDiv;
        drawStartX = -spriteWidth / 2 + spriteScreenX;
        if (drawStartX < 0)
            drawStartX = 0;
        drawEndX = spriteWidth / 2 + spriteScreenX;
        if (drawEndX >= params->x)
            drawEndX = params->x - 1;
        stripe = drawStartX;
        params->ray.sdrawstartxtab[i] = drawStartX;
        while (stripe < drawEndX)
        {
            params->text.texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * params->texture[4].width / spriteWidth) / 256;
            if ((transformY > 0) && (stripe > 0) && (stripe < params->x) && (transformY < params->ZBuffer[stripe]))
            {
                y = drawStartY;
                while (y < drawEndY)
                {
                    d = (y - vMoveScreen) * 256 - params->y * 128 + spriteHeight * 128;
                    params->text.texY = ((d * params->texture[4].height) / spriteHeight) / 256;
                    params->text.color = params->texture[4].adr[params->text.texY * params->texture[4].size_line / 4 + params->text.texX];
                    if ((params->text.color & 0x00FFFFFF) != 0 || params->text.color != 0)
                        params->window.mlx_img_data[y * params->window.size_line / 4 + stripe] = params->text.color;
                    y++;
                }
            }
            params->ray.sdrawendtab[stripe] = drawEndY;
            params->ray.sdrawstarttab[stripe] = drawStartY;
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
        j = 0;
        params->window.x++;
        i++;
    }
    ft_sprites(params);
    mlx_put_image_to_window(params->window.mlx, params->window.mlx_win, params->window.mlx_img, 0, 0);
    mlx_destroy_image(params->window.mlx, params->window.mlx_img);
    return (1);
}

void        ft_print_save(t_params *params)
{
    ft_rays(params);
    ft_print_map(params);
}