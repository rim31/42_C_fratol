/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:33:34 by oseng             #+#    #+#             */
/*   Updated: 2016/02/26 14:34:18 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				ft_new(int i)
{
	ft_mapping(ft_itoa(i));
}

void				ft_fct(t_env *a)
{
	if (a->nbfract == 1)
		ft_mandel(a);
	else if (a->nbfract == 2)
		ft_julia(a);
	else if (a->nbfract == 3)
		ft_ship(a);
	else if (a->nbfract == 4)
		ft_bunny(a);
	else if (a->nbfract == 5)
		ft_dendrite(a);
	else if (a->nbfract == 6)
		ft_heart(a);
	else if (a->nbfract == 7)
		ft_ruby(a);
	else if (a->nbfract == 8)
		ft_celt(a);
}

void				ft_error(void)
{
	t_env			a;

	a.mlx = mlx_init();
	a.win = mlx_new_window(a.mlx, 500, 400, "mlx 42");
	a.image = mlx_new_image(a.mlx, 500, 400);
	mlx_string_put(a.mlx, a.win, 10, 30, 0xff00ff, "ERROR ! :-P");
	a.data = mlx_get_data_addr(a.image, &a.bpp, &a.size_line, &a.endian);
	mlx_string_put(a.mlx, a.win, 10, 10, 0x009999, "press ESC");
	mlx_pixel_put_to_image(a.x, a.y, &a);
	mlx_hook(a.win, 2, 6, my_key_funct, &a);
	sleep(1);
}

/*
**mlx_loop(a.mlx);
*/

int					main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_atoi(argv[1]) > 0 && ft_atoi(argv[1]) < 9)
			ft_mapping(argv[1]);
	}
	ft_error();
	ft_putstr("\033[92mCHOOSE A NUMBER\033[0m\n1 : Mandelbrot\n2 : Julia\n");
	ft_putstr("3 : Burningship: \n4 : Buggs Bunny\n5 : Dentrite\n");
	ft_putstr("6 : Bird of prey\n7 : tricorne\n8 : My spiral bud\n");
	return (0);
}
