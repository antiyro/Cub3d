/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:42:41 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/18 10:42:43 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// LIBRAIRIES

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

// STRUCTURES

typedef	struct	s_params
{
	char	*r;
	char	*f;
	char	*c;
	char	*s;
	char	*no;
	char	*we;
	char	*ea;
	char	*so;
	int 	menu;
	int 	x;
	int		y;
	int		c_r;
	int		c_g;
	int		c_b;
	int		f_r;
	int		f_g;
	int		f_b;
}				t_params;

// DEFINES

# define TEST ft_putchar_fd('!', 0);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif


// PROTOTYPES

void    ft_init_struct(t_params *params);
void    ft_parsing(t_params *params);
void   ft_fill_params(char *str, t_params *params);
int     ft_verify_params(char *str, t_params *params);
int     ft_verify_r(t_params *params);
int     ft_verify_c(t_params *params);
int		get_next_line(int fd, char **line);
char	*read_line(char *str, int fd, int *r);
char	*get_line(char *str, char **line, int r);
void    ft_error_r(int error);
void    ft_error_c(int error);


#endif
