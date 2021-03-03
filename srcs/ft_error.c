/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:54:32 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/18 13:54:33 by nbouhada         ###   ########.fr       */
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

void	ft_error_s(int error)
{
	if (error == 1)
	{
		printf("Error\n");
		printf("- Bad values entered\n");
		printf("- Please write with the following format : S");
		printf(" /Users/nbouhada/Documents/cub3d/sprite/s\n");
	}
	else if (error == 2)
	{
		printf("Error\n");
		printf("- Bad link for the object entered\n");
		printf("- Please write with the following format : S");
		printf(" /Users/nbouhada/Documents/cub3d/sprite/s\n");
		printf("- Substituing link1 by one of the 2 allowed object :\n");
		printf("- obj1\n- obj2\n");
	}
	else if (error == 3)
	{
		printf("Error\n");
		printf("- Bad values entered\n");
		printf("- Please enter : NO (north), SO (south), EA (east), ");
		printf("WE (west)\n");
	}
}

void	ft_error_all(int error, char *str)
{
	if (error == 1)
	{
		printf("- Missing %s element in map.cub\n", str);
	}
}

void	ft_error_map(int error)
{
	printf("Error\n");
	if (error == 1)
	{
		printf("- Map parameters should be declared at the bottom of map.cup");
		printf(", after others parameters declarations\n");
		printf("- It should be the last declaration and should be declared as a matrix without empty lines or spaces\n");
	}
	else if (error == 2)
		printf("- The map should be surrounded by walls (represented by 1's)\n");
	else if (error == 3)
		printf("- Map should be declared as a matrix without empty lines or spaces\n");
	else if (error == 4)
		printf("- Invalid map declaration\n");
	else if (error == 5)
		printf("- Map is missing or invalid\n");
	else if (error == 5)
		printf("- There is more than one spawn parameter\n");
}
