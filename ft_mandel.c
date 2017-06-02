/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:31:31 by oseng             #+#    #+#             */
/*   Updated: 2016/02/26 14:31:33 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** z0 = 0 & Zn+1 = Zn^2 + C
** Z = Zr +i.Zi & C = Cr + i.Ci ==> i^2 = -1
** devellop and factorise ==>  z = (Zr^2 - Zi^2 + Cr) + i.(2.Zr.Zi + Ci)
** module z < 2
*/

t_env				ft_init_mandel(void)
{
	t_env a;

	a.x1 = -2.1;
	a.x2 = 0.6;
	a.y1 = -1.2;
	a.y2 = 1.2;
	a.imax = 50;
	a.iimax = 0;
	a.zoom = 200;
	a.zooom = 1;
	a.x = 0;
	a.y = 0;
	a.nbcol = 0;
	a.width = 520;
	a.length = 450;
	a.imax = 50;
	a.horiz = 0;
	a.updown = 0;
	a.zoom = 0;
	a.param = 0;
	return (a);
}

void				ft_init_mandel1(t_env *a)
{
	a->image = mlx_new_image(a->mlx, a->width, a->length);
	a->data = mlx_get_data_addr(a->image, &a->bpp, &a->size_line, &a->endian);
	mlx_string_put(a->mlx, a->win, 10, 10, 0xffffff, "Mandel");
	a->x1 = -2.1 - a->horiz;
	a->x2 = 0.6 - a->horiz;
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

void				ft_mandel(t_env *a)
{
	ft_init_mandel1(a);
	a->x = 0;
	while (a->x++ < a->img_x && a->x <= a->width)
	{
		a->y = 0;
		while (a->y++ < a->img_y && a->y <= a->length)
		{
			a->cr = a->x / a->zoom + a->x1;
			a->ci = a->y / a->zoom + a->y1;
			a->zr = 0 + a->paramx;
			a->zi = 0 + a->paramy;
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
