/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:31:43 by oseng             #+#    #+#             */
/*   Updated: 2016/02/26 14:49:40 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mlx_fct(t_env a)
{
	mlx_mouse_hook(a.win, my_mouse_funct, &a);
	mlx_hook(a.win, 6, 0, my_mouse_fct, &a);
	mlx_hook(a.win, 2, 3, my_key_funct, &a);
}

t_env		ft_mapping(char *str)
{
	t_env	a;

	if (ft_atoi(str) == 2)
		a = ft_init_julia();
	else if (ft_atoi(str) == 1)
		a = ft_init_mandel();
	else if (ft_atoi(str) == 3)
		a = ft_init_ship();
	else if (ft_atoi(str) == 4)
		a = ft_init_bunny();
	else if (ft_atoi(str) == 5)
		a = ft_init_dendrite();
	else if (ft_atoi(str) == 6)
		a = ft_init_heart();
	else if (ft_atoi(str) == 7)
		a = ft_init_ruby();
	else if (ft_atoi(str) == 8)
		a = ft_init_celt();
	a.nbfract = ft_atoi(str);
	a.mlx = mlx_init();
	a.win = mlx_new_window(a.mlx, a.width, a.length, "mlx 42");
	ft_fct(&a);
	mlx_fct(a);
	mlx_loop(a.mlx);
	return (a);
}

/*
**	a->data =
**(int *)mlx_get_data_addr(a->image, &a->bpp, &a->size_line, &a->endian);
*/

void		ft_plot(t_env *a)
{
	if (a->i == a->imax + a->iimax)
	{
		if (a->nbcol == 0)
			a->color = 0x000000;
		else
			a->color = (a->i * a->color1 / (a->imax + a->iimax));
		mlx_pixel_put_to_image(a->x, a->y, a);
	}
	else
	{
		if (a->nbcol == 0)
			a->color = (a->i * 255 * 255 / (a->imax + a->iimax));
		else
			a->color = (a->i * a->color1 / (a->imax + a->iimax));
		mlx_pixel_put_to_image(a->x, a->y, a);
	}
}
