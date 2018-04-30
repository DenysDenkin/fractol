/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:36:54 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/31 18:11:11 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>
# define WIN_W  1024
# define WIN_H  768
# define MOUSE_ZOOM 4
# define MOUSE_UNZOOM 5
# define KEY_ZOOM 116
# define KEY_UNZOOM 121
# define INCR_ITER 24
# define DECR_ITER 27
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define MOUSE_ACTIVE 46
# define EPYLEPSY 14
# define PR_SQRT 8
# define PROC PR_SQRT*PR_SQRT

typedef struct		s_abc
{
	int				a;
	int				b;
	int				c;
}					t_abc;

typedef struct		s_mandel
{
	long double		cr;
	long double		ci;
	long double		nr;
	long double		ni;
	long double		op;
	long double		oi;
}					t_mandel;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*addr;
	char			*name;
	int				mouse_x;
	int				mouse_y;
	int				mouse_active;
	int				epylepsy_active;
	int				max_iter;
	long			x;
	long			y;
	long			z;
	double			zr;
	double			zi;
	int				(*frac)(struct s_mlx *, long, long);
}					t_mlx;

typedef struct		s_addr
{
	int				*addr;
	int				a;
	int				b;
	int				c;
}					t_addr;

typedef struct		s_help
{
	char			*max_i;
	char			*z;
	char			*x;
	char			*y;
	char			*mx;
	char			*my;

}					t_help;

typedef struct		s_pth_arg
{
	t_mlx			*mlx;
	int				*addr;
	long			x_s;
	long			y_s;
	long			x_e;
	long			y_e;
}					t_pth_arg;

int					hook_mouseclick(int button, int x, int y, t_mlx *mlx);
int					cross(t_mlx *mlx);
int					hook_mousemove(int x, int y, t_mlx *mlx);
int					hook_keypress(int key, t_mlx *mlx);
void				putallthepixels(t_mlx mlx);
t_mlx				*init_all(void);
void				mlx_clear_image(t_mlx *mlx);
void				unzoom(t_mlx *mlx);
void				zoom(t_mlx *mlx);
int					usage();
void				free_help(t_help help);
int					choose_fractal(t_mlx *mlx, char *s);
int					julia(t_mlx *mlx, long x, long y);
int					mand(t_mlx *mlx, long x, long y);
int					ship(t_mlx *mlx, long x, long y);
int					tricorn(t_mlx *mlx, long x, long y);
int					cubebrot(t_mlx *mlx, long x, long y);
int					carpet(t_mlx *mlx, long x, long y);
int					quadrabrot(t_mlx *mlx, long x, long y);
int					pentabrot(t_mlx *mlx, long x, long y);
#endif
