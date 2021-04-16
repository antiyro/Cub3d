/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_params2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:54:30 by nbouhada          #+#    #+#             */
/*   Updated: 2021/04/16 13:00:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_verify_no(t_params *params)
{
	if (!params->no)
		return (0);
	params->tabs.tab2 = ft_split(params->no, ' ');
	if (ft_strcmp(params->tabs.tab2[0], "NO"))
	{
		ft_error_wind(3, params->tabs.tab2[0]);
		return (0);
	}
	if (ft_tablen(params->tabs.tab2) != 2)
	{
		ft_error_wind(1, params->tabs.tab2[0]);
		ft_free_tab(params->tabs.tab2);
		return (0);
	}
	if (!ft_wind(params->tabs.tab2[1]))
	{
		ft_error_wind(2, params->tabs.tab2[0]);
		return (0);
	}
	else
		params->linkno = ft_strdup(params->tabs.tab2[1]);
	params->menu += 1;
	return (1);
}

int			ft_verify_we(t_params *params)
{
	if (!params->we)
		return (0);
	params->tabs.tab3 = ft_split(params->we, ' ');
	if (ft_strcmp(params->tabs.tab3[0], "WE"))
	{
		ft_error_wind(3, params->tabs.tab3[0]);
		return (0);
	}
	if (ft_tablen(params->tabs.tab3) != 2)
	{
		ft_error_wind(1, params->tabs.tab3[0]);
		return (0);
	}
	if (!ft_wind(params->tabs.tab3[1]))
	{
		ft_error_wind(2, params->tabs.tab3[0]);
		return (0);
	}
	else
		params->linkwe = ft_strdup(params->tabs.tab3[1]);
	params->menu += 1;
	return (1);
}

int			ft_verify_ea(t_params *params)
{
	if (!params->ea)
		return (0);
	params->tabs.tab4 = ft_split(params->ea, ' ');
	if (ft_strcmp(params->tabs.tab4[0], "EA"))
	{
		ft_error_wind(3, params->tabs.tab4[0]);
		return (0);
	}
	if (ft_tablen(params->tabs.tab4) != 2)
	{
		ft_error_wind(1, params->tabs.tab4[0]);
		return (0);
	}
	if (!ft_wind(params->tabs.tab4[1]))
	{
		ft_error_wind(2, params->tabs.tab4[0]);
		return (0);
	}
	else
		params->linkea = ft_strdup(params->tabs.tab4[1]);
	params->menu += 1;
	return (1);
}

int			ft_verify_so(t_params *params)
{
	if (!params->so)
		return (0);
	params->tabs.tab5 = ft_split(params->so, ' ');
	if (ft_strcmp(params->tabs.tab5[0], "SO"))
	{
		ft_error_wind(3, params->tabs.tab5[0]);
		return (0);
	}
	if (ft_tablen(params->tabs.tab5) != 2)
	{
		ft_error_wind(1, params->tabs.tab5[0]);
		return (0);
	}
	if (!ft_wind(params->tabs.tab5[1]))
	{
		ft_error_wind(2, params->tabs.tab5[0]);
		return (0);
	}
	else
		params->linkso = ft_strdup(params->tabs.tab5[1]);
	params->menu += 1;
	return (1);
}

int			ft_verify_s(t_params *params)
{
	if (!params->s)
		return (0);
	params->tabs.tab6 = ft_split(params->s, ' ');
	if (ft_tablen(params->tabs.tab6) != 2)
	{
		ft_error_s(1);
		return (0);
	}
	if (!ft_s(params->tabs.tab6[1]))
	{
		ft_error_s(2);
		return (0);
	}
	params->menu += 1;
	return (1);
}
