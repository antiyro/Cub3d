/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:28:02 by nbouhada          #+#    #+#             */
/*   Updated: 2021/03/08 09:49:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		printf("- Invalid map parameter detected\n");
		printf("- Map parameters should be declared at the bottom of map.cup");
		printf(", after others parameters declarations\n");
		printf("- It should be the last declaration and should be declared ");
		printf("as a matrix without empty lines or spaces\n");
	}
	else if (error == 2)
		printf("- Map should be surrounded by walls (represented by 1's)\n");
	else if (error == 3)
		printf("- Map should be declared without empty lines or spaces\n");
	else if (error == 4)
		printf("- Invalid map declaration\n");
	else if (error == 5)
		printf("- Map is missing or invalid\n");
	else if (error == 6)
		printf("- There is more than one spawn parameter\n");
	else if (error == 7)
		printf("- Invalid map character detected\n");
	else if (error == 8)
		printf("- Missing spawn parameter\n");
}

void	ft_error_system(int error)
{
	printf("Error\n");
	if (error == 1)
	{
		printf("- Opening of the .cub file failed\n");
		printf("- Please use the right filepath and an existing map\n");
	}
}