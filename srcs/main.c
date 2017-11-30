/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:33:49 by jonkim            #+#    #+#             */
/*   Updated: 2017/11/29 20:16:23 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_total total;

	ft_bzero(&total, sizeof(total));
	if (ac != 2)
		ft_error_msg("./fdf [FILE_NAME]");
	ft_init_val(&total);
	ft_read_file(&av[1], &total);
	total.mlx = mlx_init();
	total.win = mlx_new_window(total.mlx, total.def_wid, total.def_hgt,
			"jonkim's FDF");
	ft_plot_setup(&total);
	ft_plot_pt(&total);
	mlx_hook(total.win, 2, 2, ft_window_key, &total);
	mlx_expose_hook(total.win, ft_window_expose, &total);
	mlx_loop(total.mlx);
	return (0);
}
