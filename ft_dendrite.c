/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dendrite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:29:35 by oseng             #+#    #+#             */
/*   Updated: 2016/02/26 14:29:59 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env				ft_init_dendrite(void)
{
	t_env a;

	a.x1 = -1;
	a.x2 = 1;
	a.y1 = -1.2;
	a.y2 = 1.2;
	a.imax = 50;
	a.iimax = 0;
	a.zoom = 200;
	a.zooom = 1;
	a.x = 0;
	a.y = 0;
	a.nbcol = 0;
	a.width = 540;
	a.length = 480;
	a.imax = 50;
	a.horiz = -0.8;
	a.updown = 0;
	a.zoom = 0;
	a.param = 0;
	return (a);
}

void				ft_init_dendrite1(t_env *a)
{
	a->image = mlx_new_image(a->mlx, a->width, a->length);
	a->data = mlx_get_data_addr(a->image, &a->bpp, &a->size_line, &a->endian);
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

void				ft_dendrite(t_env *a)
{
	ft_init_dendrite1(a);
	a->x = 0;
	while (a->x++ < a->img_x && a->x <= a->width)
	{
		a->y = 0;
		while (a->y++ < a->img_y && a->y <= a->length)
		{
			a->zr = a->x / a->zoom + a->x1;
			a->zi = a->y / a->zoom + a->y1;
			a->cr = 0 + a->paramx;
			a->ci = 1 + a->paramy;
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
