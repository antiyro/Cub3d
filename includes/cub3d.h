/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:42:41 by nbouhada          #+#    #+#             */
/*   Updated: 2021/03/22 12:13:51 by user42           ###   ########.fr       */
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
# include "../mlx/mlx.h"
# include <math.h>

// STRUCTURES

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	char	*mlx_img_data;
	int		bpp;
	int		size_line;
	int		endian;
	int 	x;
	int 	y;
}				t_window;

typedef	struct 	s_spawn
{
	double	x;
	double	y;
	char wind;
}				t_spawn;

typedef struct	s_ray
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planx;
	double	plany;
	double	raydirx;
	double	raydiry;
	double	camerax;
	int		mapx;
	int		mapy;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	wallDist;
	int 	stepx;
	int		stepy;
	int		hit;
	int		sideHit;
	int		drawend;
	int		drawstart;
	int lineheight;
}				t_ray;

typedef	struct		s_tabs
{
	char	**tab;
	char	**tab1;
	char	**tab2;
	char	**tab3;
	char	**tab4;
	char	**tab5;
	char	**tab6;
}			t_tabs;

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
	t_tabs	tabs;
	int		wallup;
	int		walldown;
	int		wallleft;
	int		wallright;
	t_spawn spawn;
	t_window window;
	t_ray	ray;
	
	char	*mapfile;
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

# define SPEED 0.1

//keys

# define ROT_LEFT	65361
# define ROT_RIGHT	65363
# define FORWARD	119
# define BACK		115
# define RIGHT		100
# define LEFT		97
# define ESCAPE		65307

// PROTOTYPES

//tools
void				ft_init_struct(t_params *params);
void				ft_destroy_struct(t_params *params);
void				ft_fill_params(char *str, t_params *params, int *count);
int					ft_rgb(int nb);
int					ft_wind(char *str);
int					ft_s(char *str);
void				ft_loading(void);
int					ft_fill_map(t_params *params);
int					ft_one(char *str);
int					ft_checkismap(char *str);
int					ft_checkisempty(char *str);
int					ft_checkisspace(char *str);
int					ft_isspace(char c);
char				**ft_tabcpy(char **tab);
int					ft_ispair(int n);
int					ft_spawn(char c);
int         		ft_digit(int digit, t_params *params);
int					ft_controls(int key, t_params *params);
void				ft_free_tab(char **tab);
void				ft_set_ray(t_params *params);


//parsing
int					ft_parsing_params(t_params *params);
int					ft_parsing_params2(t_params *params, int *count, int fd, int *i);
int					ft_parsing_map(t_params *params, int fd, int *i);
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

//window
int    				ft_init_window(t_params *params);
void				ft_print_pixel(t_params *params, int color);
int					ft_print_map(t_params *params);
int					ft_rays(t_params *params);
void				ft_print_spawn(t_params *params, int color);

//rays
void				ft_set_dirplan(t_params *params);

//errors
void				ft_error_messages(int error);
void				ft_error_r(int error);
void				ft_error_c(int error);
void				ft_error_f(int error);
void				ft_error_wind(int error, char *wind);
void				ft_error_s(int error);
void				ft_error_all(int error, char *str);
void				ft_error_map(int error);
void				ft_error_system(int error);

#endif
