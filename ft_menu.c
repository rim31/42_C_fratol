/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:32:03 by oseng             #+#    #+#             */
/*   Updated: 2016/02/26 14:59:05 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_pixel_put_to_image(int x, int y, t_env *e)
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;

	b = (e->color & 0xFF0000) >> 16;
	g = (e->color & 0xFF00) >> 8;
	r = (e->color & 0xFF);
	if (y > 0 && x > 0 && x < e->width && y < e->length)
	{
		e->data[y * e->size_line + x * e->bpp / 8] = r;
		e->data[y * e->size_line + x * e->bpp / 8 + 1] = g;
		e->data[y * e->size_line + x * e->bpp / 8 + 2] = b;
	}
}

void	ft_menu(t_env a, int nb)
{
	if (nb == 91)
		ft_new(8);
	if (nb >= 83 && nb <= 89)
		ft_new(nb - 82);
	mlx_string_put(a.mlx, a.win, 1, 1, 0xff00ff, "Menu  Key");
	mlx_string_put(a.mlx, a.win, 10, 15, 0x009999, "move : <- ^ v ->");
	mlx_string_put(a.mlx, a.win, 10, 30, 0x999999, "zoom : page up or down");
	mlx_string_put(a.mlx, a.win, 10, 45, 0x999999, "iteration : + or -");
	mlx_string_put(a.mlx, a.win, 10, 15, 0x009999, "          | |");
	mlx_string_put(a.mlx, a.win, 10, 60, 0x999999, "fractal : 1 2 3 4 5 6 7 8");
	mlx_pixel_put_to_image(a.x, a.y, &a);
	mlx_hook(a.win, 2, 3, my_key_funct, &a);
	mlx_loop(a.mlx);
}

int		my_key_funct(int keycode, t_env *a)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
		a->updown -= 0.1 / a->zooom;
	if (keycode == 125)
		a->updown += 0.1 / a->zooom;
	if (keycode == 123)
		a->horiz -= 0.1 / a->zooom;
	if (keycode == 124)
		a->horiz += 0.1 / a->zooom;
	if (keycode == 78 && a->imax > 14)
		a->iimax -= 14;
	if (keycode == 69)
		a->iimax += 14;
	if (keycode == 121 && a->zooom > 1.1)
		a->zooom /= 1.10;
	if (keycode == 116)
		a->zooom *= 1.10;
	if (keycode == 49 || (keycode >= 83 && keycode <= 92))
		ft_menu(*a, keycode);
	ft_bzero((void *)a->data, (a->width * a->length));
	ft_fct(a);
	return (0);
}

int		my_mouse_fct(int x, int y, t_env *e)
{
	if (x > 0 && x < e->width && y > 0 && y < e->length)
	{
		e->paramx = (float)((x - e->width / 2) / e->width);
		e->paramy = (float)((y - e->length / 2) / e->length);
		ft_bzero((void *)e->data, (e->width * e->length));
		ft_fct(e);
	}
	return (0);
}

int		my_mouse_funct(int button, int x, int y, t_env *e)
{
	if (button == 5)
	{
		e->zooom *= 1.10;
		e->updown = ((e->length / 2 - y) / e->length) * e->zooom + e->updown;
		e->horiz = ((e->width / 2 - x) / e->width) * e->zooom + e->horiz;
	}
	if (button == 4 && e->zooom > 1)
	{
		e->zooom /= 1.10;
		e->updown = ((e->length / 2 - y) / e->length) * e->zooom + e->updown;
		e->horiz = ((e->width / 2 - x) / e->width) * e->zooom + e->horiz;
	}
	if (button == 3)
		e->nbcol = (e->nbcol != 0) ? 0 : 1;
	ft_bzero((void *)e->data, (e->width * e->length));
	ft_fct(e);
	return (0);
}
