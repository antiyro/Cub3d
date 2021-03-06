/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:42:41 by nbouhada          #+#    #+#             */
/*   Updated: 2021/03/06 13:13:04 by user42           ###   ########.fr       */
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
# include "../srcs/libft/libft.h"

// STRUCTURES

typedef	struct		s_params
{
	char	*r;
	char	*f;
	char	*c;
	char	*s;
	char	*no;
	char	*we;
	char	*ea;
	char	*so;
	int		menu;
	int		x;
	int		y;
	int		c_r;
	int		c_g;
	int		c_b;
	int		f_r;
	int		f_g;
	int		f_b;
	char	**map;
	int		wallup;
	int		walldown;
	int		wallleft;
	int		wallright;
	char	spawn;
}					t_params;

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

//tools
void				ft_init_struct(t_params *params);
void				ft_fill_params(char *str, t_params *params, int *count);
int					ft_rgb(int nb);
int					ft_wind(char *str);
int					ft_s(char *str);
void				ft_loading(void);
int					ft_fill_map(char *str, t_params *params);
int					ft_one(char *str);
int					ft_checkismap(char *str);
int					ft_checkisempty(char *str);
int					ft_checkisspace(char *str);
int					ft_isspace(char c);
char				**ft_tabcpy(char **tab);
int					ft_ispair(int n);

//parsing
void				ft_parsing_params(t_params *params);
void				ft_parsing_params2(t_params *params, int *count, int fd, int *i);
int					ft_parsing_map(t_params *params, int fd, int *i);
void				ft_parsing_map2(t_params
						*params, int fd, int *i, int *error, char *str);
int					get_next_line(int fd, char **line);
char				*read_line(char *str, int fd, int *r);
char				*get_line(char *str, char **line, int r);

//verify
int					ft_verify_params(t_params *params);
int					ft_verify_r(t_params *params);
int					ft_verify_c(t_params *params);
int					ft_verify_f(t_params *params);
int					ft_verify_we(t_params *params);
int					ft_verify_no(t_params *params);
int					ft_verify_so(t_params *params);
int					ft_verify_ea(t_params *params);
int					ft_verify_s(t_params *params);
int					ft_verify_all(t_params *params, int *count);
int					ft_verify_map(t_params *params);
int					ft_verify_walls(t_params *params);
int					ft_verify_flood(t_params *params);
int					ft_verify_spaces(t_params *params);
int					ft_verify_spawn(t_params *params);
int					ft_verify_garbage(t_params *params);

//errors
void				ft_error_messages(int error);
void				ft_error_r(int error);
void				ft_error_c(int error);
void				ft_error_f(int error);
void				ft_error_wind(int error, char *wind);
void				ft_error_s(int error);
void				ft_error_all(int error, char *str);
void				ft_error_map(int error);

#endif
