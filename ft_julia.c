/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:30:42 by oseng             #+#    #+#             */
/*   Updated: 2016/02/29 09:40:15 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env		ft_init_julia(void)
{
	t_env	a;

	a.x1 = -1;
	a.x2 = 1;
	a.y1 = -1.2;
	a.y2 = 1.2;
	a.imax = 150;
	a.iimax = 0;
	a.zoom = 100;
	a.zooom = 1;
	a.x = 0;
	a.y = 0;
	a.nbcol = 0;
	a.width = 400;
	a.length = 490;
	a.imax = 50;
	a.horiz = 0;
	a.updown = 0;
	a.zoom = 0;
	a.paramx = 0;
	a.paramy = 0;
	return (a);
}

void		ft_init_julia1(t_env *a)
{
	mlx_string_put(a->mlx, a->win, 10, 10, 0xffffff, "Julia");
	a->image = mlx_new_image(a->mlx, a->width, a->length);
	a->data = mlx_get_data_addr(a->image, &a->bpp, &a->size_line, &a->endian);
	a->x1 = -1 - a->horiz;
	a->x2 = 1 - a->horiz;
	a->y1 = -1.2 - a->updown;
	a->y2 = 1.2 - a->updown;
	a->zoom = 200 * a->zooom;
	a->img_x = (a->x2 - a->x1) * a->zoom * a->zooom;
	a->img_y = (a->y2 - a->y1) * a->zoom * a->zooom;
	if (a->nbcol != 0)
	{
		a->color0 = rand() % 999999999;
		a->color = rand() % 999999999;
		a->color1 = rand() % 999999999;
	}
}

void		ft_julia(t_env *a)
{
	ft_init_julia1(a);
	a->x = 0;
	while (a->x++ < a->img_x && a->x <= a->width)
	{
		a->y = 0;
		while (a->y++ < a->img_y && a->y <= a->length)
		{
			a->zr = a->x / a->zoom + a->x1;
			a->zi = a->y / a->zoom + a->y1;
			a->cr = 0.285 + a->paramx;
			a->ci = 0.01 + a->paramy;
			a->i = -1;
			while (a->zr * a->zr + a->zi * a->zi < 4
					&& a->i++ < (a->imax + a->iimax))
			{
				a->tmp = a->zr;
				a->zr = a->zr * a->zr - a->zi * a->zi + a->cr;
				a->zi = 2 * a->tmp * a->zi + a->ci;
			}
			ft_plot(a);
		}
	}
	mlx_put_image_to_window(a->mlx, a->win, a->image, 0, 0);
}
