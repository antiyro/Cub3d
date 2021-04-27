/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:31:34 by nbouhada          #+#    #+#             */
/*   Updated: 2021/04/27 15:31:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_init_struct(t_params *params)
{
	params->r = 0;
	params->f = 0;
	params->c = 0;
	params->s = 0;
	params->no = 0;
	params->so = 0;
	params->we = 0;
	params->ea = 0;
	params->x = 0;
	params->y = 0;
	params->spawn.wind = 0;
	params->spawn.x = 0;
	params->spawn.y = 0;
	params->hexac = 0;
	params->hexaf = 0;
	params->linkno = 0;
	params->linkso = 0;
	params->linkwe = 0;
	params->linkea = 0;
	params->obj1 = 0;
	params->numSprite = 0;
	params->tabs.tab = 0;
	ft_init_struct2(params);
	ft_set_ray(params);
}

void		ft_init_struct2(t_params *params)
{
	params->ray.drawendtab = 0;
	params->ray.drawstarttab = 0;
	params->ray.sidetab = 0;
	params->ray.colortab = 0;
	params->ZBuffer = 0;
	params->spriteOrder = 0;
	params->spriteDistance = 0;
	params->sprite = 0;
	params->map = 0;
	params->wallup = 0;
	params->walldown = 0;
	params->wallleft = 0;
	params->wallright = 0;
	params->mapfile = 0;
	params->save = 0;
	params->window.mlx = 0;
	params->window.mlx_win = 0;
	params->window.mlx_img = 0;
	params->window.mlx_img_data = 0;
	params->window.bpp = 0;
	params->window.size_line = 0;
	params->window.endian = 0;
	params->window.x = 0;
	params->window.y = 0;
	ft_init_struct3(params);
}

void		ft_init_struct3(t_params *params)
{
	params->tabs.tab = 0;
	params->tabs.tab1 = 0;
	params->tabs.tab2 = 0;
	params->tabs.tab3 = 0;
	params->tabs.tab4 = 0;
	params->tabs.tab5 = 0;
	params->tabs.tab6 = 0;
	params->tabs.tab7 = 0;
	params->tabs.tab8 = 0;
	params->tabs.tab9 = 0;
}

void		ft_destroy_struct(t_params *params)
{
	if (params->r)
		free(params->r);
	if (params->f)
		free(params->f);
	if (params->c)
		free(params->c);
	if (params->s)
		free(params->s);
	if (params->no)
		free(params->no);
	if (params->so)
		free(params->so);
	if (params->we)
		free(params->we);
	if (params->ea)
		free(params->ea);
	if (params->mapfile)
		free(params->mapfile);
	if (params->ray.drawendtab)
		free(params->ray.drawendtab);
	if (params->ray.drawstarttab)
		free(params->ray.drawstarttab);
	if (params->ZBuffer)
		free(params->ZBuffer);
	if (params->ray.sidetab)
		free(params->ray.sidetab);
	if (params->spriteOrder)
		free(params->spriteOrder);
	if (params->spriteDistance)
		free(params->spriteDistance);
	if (params->sprite)
		free(params->sprite);
	if (params->map)
		ft_free_tab(params->map);
	ft_destroy_struct2(params);
}

void		ft_destroy_struct2(t_params *params)
{
	if (params->linkno)
		free(params->linkno);
	if (params->linkso)
		free(params->linkso);
	if (params->linkwe)
		free(params->linkwe);
	if (params->linkea)
		free(params->linkea);
	if (params->obj1)
		free(params->obj1);
}

void		ft_destroy_tabs(t_params *params)
{
	if (params->tabs.tab)
		ft_free_tab(params->tabs.tab);
	if (params->tabs.tab1)
		ft_free_tab(params->tabs.tab1);
	if (params->tabs.tab2)
		ft_free_tab(params->tabs.tab2);
	if (params->tabs.tab3)
		ft_free_tab(params->tabs.tab3);
	if (params->tabs.tab4)
		ft_free_tab(params->tabs.tab4);
	if (params->tabs.tab5)
		ft_free_tab(params->tabs.tab5);
	if (params->tabs.tab6)
		ft_free_tab(params->tabs.tab6);
	if (params->tabs.tab7)
		ft_free_tab(params->tabs.tab7);
	if (params->tabs.tab8)
		ft_free_tab(params->tabs.tab8);
}
