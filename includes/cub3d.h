/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:42:41 by nbouhada          #+#    #+#             */
/*   Updated: 2021/04/27 13:15:36 by user42           ###   ########.fr       */
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
# include "../mlx/mlx_int.h"
# include <math.h>

// STRUCTURES

struct	s_sprite;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	int		*mlx_img_data;
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
	int 	lineheight;
	double	oldDirX;
	double 	oldPlanX;
	int		*drawendtab;
	int		*drawstarttab;
	int		*sdrawendtab;
	int		*sdrawstarttab;
	int 	*sdrawstartxtab;
	int		*sidetab;
	int		**colortab;
	int		**scolortab;
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
	char	**tab7;
	char	**tab8;
	char	**tab9;
	char	**mapcpy;
}			t_tabs;

typedef struct	s_texture
{
	void		*img;
	int			width;
	int 		height;
	int			*adr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_texture;

typedef struct	s_text
{
	int		texNum;
	double	wallx;
	int		texX;
	int		texY;
	double	step;
	double	texPos;
	unsigned int color;
}				t_text;

typedef struct	s_sprite
{
	double		x;
	double		y;
	int			height;
	int			width;
	int			texture;
	double		first;
	double		second;
	int 		stripe;
    int 		drawstarty;
    int 		drawendy;
    int 		drawstartx;
    int 		drawendx;
    int 		spritescreenx;
    int 		spriteheight;
    int 		spritewidth;
    double 		spritex;
    double 		spritey;
    double 		invdet;
    double 		transformx;
    double 		transformy;
}		t_sprite;

typedef	struct		s_params
{
	char		*r;
	char		*f;
	char		*c;
	char		*s;
	char		*no;
	char		*we;
	char		*ea;
	char		*so;
	int			menu;
	int			x;
	int			y;
	int			c_r;
	int			c_g;
	int			c_b;
	int			f_r;
	int			f_g;
	int			f_b;
	int			hexaf;
	int			hexac;
	char		**map;
	t_tabs		tabs;
	int			wallup;
	int			walldown;
	int			wallleft;
	int			wallright;
	char		*linkno;
	char		*linkso;
	char		*linkwe;
	char		*linkea;
	char		*obj1;
	int			save;
	char		*savearg;
	t_spawn 	spawn;
	t_window 	window;
	t_ray		ray;
	t_texture	texture[5];
	t_text		text;
	//SPRITES
	int			numSprite;
	int			*spriteOrder;
	double		*spriteDistance;
	double		*ZBuffer;
	t_sprite	spritetools;			
	t_sprite	*sprite;
	char		*mapfile;
}					t_params;

// DEFINES

# define TEST ft_putstr_fd("!\n", 0);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# define LINK1 "./textures/wood.xpm"
# define LINK2 "./textures/redbrick.xpm"
# define LINK3 "./textures/sand.xpm"
# define LINK4 "./textures/stone.xpm"
# define OBJ1 "./textures/barrel.xpm"

# define SPEED 0.1
# define ROTSPEED 0.1

#define uDiv 1
#define vDiv 1

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
void				ft_init_struct2(t_params *params);
void				ft_destroy_struct(t_params *params);
void				ft_destroy_struct2(t_params *params);
void				ft_fill_params(char *str, t_params *params, int *count);
int					ft_rgb(int nb);
int					ft_wind(char *str, t_params *params);
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
void				ft_free_tabi(int **tab);
void				ft_set_ray(t_params *params);
int					ft_load_text(t_params *params);
int					ft_load_text2(t_params *params);
int        			ft_destroy_window(int key, t_params *params);
void				ft_rgbtohex(t_params *params);
void				ft_setTexnum(t_params *params);
void				ft_set_dirplan(t_params *params);
void				ft_set_dirplan2(t_params *params);
void				ft_destroy_tabs(t_params *params);
int					ft_sprite_pos(t_params *params);
int					ft_verify_arg(t_params *params);
int 				ft_count_comas(char	*str);
int					ft_verify_save(t_params *params);
void				ft_tabcpy2(t_params *params);
void				ft_print_tab(int **tab);
void				ft_clean(t_params *params);
int					ft_arg_init(t_params *params, int argc, char **argv);

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
int     			ft_sprites(t_params *params);
int         		ft_init_var(t_params *params);
void				ft_sort_sprites(t_params *params);
void        		ft_print_save(t_params *params);

//rays
void    			ft_rays_throw(t_params *params, int *i);
void    			ft_rays_hit(t_params *params);
void    			ft_rays_text(t_params *params);
void    			ft_rays_draw(t_params *params, int *i);

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
void				ft_error_texture(int error);

#endif
