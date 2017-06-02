/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:56:54 by oseng             #+#    #+#             */
/*   Updated: 2016/02/29 09:36:24 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"

typedef struct	s_env
{
	int			bpp;
	int			size_line;
	int			color;
	int			color0;
	int			color1;
	int			nbcol;
	int			nbfract;
	char		*data;
	int			endian;
	void		*mlx;
	void		*win;
	void		*image;
	float		updown;
	float		horiz;
	float		paramx;
	float		paramy;
	float		param;
	float		xi;
	float		xf;
	float		yi;
	float		yf;
	int			x;
	int			y;
	float		z;
	float		zi;
	float		zr;
	float		c;
	float		ci;
	float		cr;
	int			i;
	int			imax;
	int			iimax;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	float		zoom;
	float		zooom;
	float		img_x;
	float		img_y;
	float		tmp;
	float		width;
	float		length;
}				t_env;

void			ft_error(void);
void			ft_fct(t_env *a);
void			ft_ruby(t_env *a);
t_env			ft_init_ruby(void);
void			ft_init_ruby1(t_env *a);
void			ft_celt(t_env *a);
t_env			ft_init_celt(void);
void			ft_init_celt1(t_env *a);
void			ft_heart(t_env *a);
t_env			ft_init_heart(void);
void			ft_init_heart1(t_env *a);
void			ft_dendrite(t_env *a);
t_env			ft_init_dendrite(void);
void			ft_init_dendrite1(t_env *a);
void			ft_bunny(t_env *a);
t_env			ft_init_bunny(void);
void			ft_init_bunny1(t_env *a);
void			ft_ship(t_env *a);
t_env			ft_init_ship(void);
void			ft_init_ship1(t_env *a);
t_env			ft_init_mandel(void);
void			ft_init_mandel1(t_env *a);
void			ft_mandel(t_env *a);
void			ft_julia(t_env *a);
t_env			ft_init_julia(void);
void			ft_init_julia1(t_env *a);
void			ft_plot(t_env *a);
t_env			ft_mapping(char *str);
int				my_mouse_funct(int button, int x, int y, t_env *e);
int				my_mouse_fct(int x, int y, t_env *e);
int				my_key_funct(int keycode, t_env *a);
void			ft_menu(t_env a, int nb);
void			mlx_pixel_put_to_image(int x, int y, t_env *e);
void			ft_new(int i);
void			mlx_fct(t_env a);
void			ft_fct(t_env *a);

#endif
