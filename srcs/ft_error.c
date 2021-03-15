/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:54:32 by nbouhada          #+#    #+#             */
/*   Updated: 2021/03/15 12:04:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error_messages(int error)
{
	if (error == 1)
	{
		printf("Error\nUse of wrong indentifier\n-'R' for the resolution\n");
		printf("-'F' for the floor color\n-'C' for the sky color\n");
		printf("-'s' for the floor color\n");
		printf("-'NO' for the north texture\n-'WE' for the west texture\n");
		printf("-'SO' for the south texture\n-'EA' for the east texture");
	}
}

void	ft_error_r(int error)
{
	if (error == 1)
	{
		printf("Error\n");
		printf("- Too few arguments in resolution\n");
		printf("- Please write with the following format : R x y\n");
	}
	else if (error == 2)
	{
		printf("Error\n");
		printf("- Bad resolution values entered\n");
		printf("- Please enter a resolution positive with an int format\n");
	}
	else if (error == 3)
	{
		printf("Error\n");
		printf("- The resolution cant be treated as an int\n");
		printf("- Please enter a value less or equal 2147483647\n");
	}
}

void	ft_error_c(int error)
{
	if (error == 1)
	{
		printf("Error\n");
		printf("- Too few color indicators for the ciling\n");
		printf("- Please write with the following format : C r,g,b\n");
	}
	else if (error == 2)
	{
		printf("Error\n");
		printf("- Bad colors values entered\n");
		printf("- Please enter the indicators as a positive int value ");
		printf("between 0 and 255\n");
	}
	else if (error == 3)
	{
		printf("Error\n");
		printf("- Colors parameters cant be treated as an int\n");
		printf("- Please enter the indicators as a positive int value ");
		printf("between 0 and 255\n");
	}
}

void	ft_error_f(int error)
{
	if (error == 1)
	{
		printf("Error\n");
		printf("- Too few color indicators for the floor\n");
		printf("- Please write with the following format : F r,g,b\n");
	}
	else if (error == 2)
	{
		printf("Error\n");
		printf("- Bad colors values entered\n");
		printf("- Please enter the indicators as a positive int value ");
		printf("between 0 and 255\n");
	}
	else if (error == 3)
	{
		printf("Error\n");
		printf("- Colors parameters cant be treated as an int\n");
		printf("- Please enter the indicators as a positive int value ");
		printf("between 0 and 255\n");;
	}
}

void	ft_error_wind(int error, char *wind)
{
	if (error == 1)
	{
		printf("Error\n");
		printf("- Bad values entered for %s\n", wind);
		printf("- Please write with the following format : %s", wind);
		printf(" /Users/nbouhada/Documents/cub3d/sprite/link1\n");
	}
	else if (error == 2)
	{
		printf("Error\n");
		printf("- Bad link for the sprites entered\n");
		printf("- Please write with the following format : %s", wind);
		printf(" /Users/nbouhada/Documents/cub3d/sprite/link1\n");
		printf("- Substituing link1 by one of the 4 allowed sprites :\n");
		printf("- link1\n- link2\n- link3\n- link4\n");
	}
	else if (error == 3)
	{
		printf("Error\n");
		printf("- Bad values entered\n");
		printf("- Please enter : NO (north), SO (south), EA (east), ");
		printf("WE (west)\n");
	}
}
