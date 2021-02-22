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

# define TEST ft_putstr_fd("!\n", 0);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# define LINK1 "link1"
# define LINK2 "link2"
# define LINK3 "link3"
# define LINK4 "link4"

# define OBJ1 "obj1"
# define OBJ2 "obj2"

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
void    ft_error_f(int error);
int     ft_rgb(int nb);
void    ft_error_wind(int error, char *wind);
int     ft_wind(char *str);
int     ft_verify_we(t_params *params);
int     ft_verify_no(t_params *params);
int     ft_verify_so(t_params *params);
int     ft_verify_ea(t_params *params);
int     ft_s(char *str);
int     ft_verify_s(t_params *params);
void    ft_error_s(int error);
void    ft_error_all(int error, char *str);
int     ft_verify_all(t_params *params);
int     ft_verify_f(t_params *params);
void	ft_loading(void);

#endif
