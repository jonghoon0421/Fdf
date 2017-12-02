/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:56:55 by jonkim            #+#    #+#             */
/*   Updated: 2017/12/01 15:05:26 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_window_move(int keycode, t_total *tot)
{
	keycode == 126 ? tot->move_y -= 7 : 0;
	keycode == 125 ? tot->move_y += 7 : 0;
	keycode == 123 ? tot->move_x -= 7 : 0;
	keycode == 124 ? tot->move_x += 7 : 0;
}

void	ft_window_alt(int keycode, t_total *tot)
{
	keycode == 12 ? tot->angle_x += M_PI / 30 : 0;
	keycode == 13 ? tot->angle_x -= M_PI / 30 : 0;
	keycode == 0 ? tot->angle_y -= M_PI / 30 : 0;
	keycode == 1 ? tot->angle_y += M_PI / 30 : 0;
	keycode == 6 ? tot->angle_z -= M_PI / 30 : 0;
	keycode == 7 ? tot->angle_z += M_PI / 30 : 0;
	keycode == 27 ? tot->zoom -= 0.015 : 0;
	keycode == 24 ? tot->zoom += 0.015 : 0;
	keycode == 31 ? tot->z_scale += 5 : 0;
	keycode == 35 ? tot->z_scale -= 5 : 0;
}

int		ft_window_key(int keycode, t_total *tot)
{
	keycode == 53 ? ft_error_msg("Program exit") : 0;
	(keycode >= 123 && keycode <= 126) ? ft_window_move(keycode, tot) : 0;
	(keycode >= 0 && keycode <= 35) ? ft_window_alt(keycode, tot) : 0;
	keycode == 45 ? ft_init_reset(tot) : 0;
	mlx_clear_window(tot->mlx, tot->win);
	ft_plot_setup(tot);
	FT_ROT(tot);
	ft_plot_pt(tot);
	return (0);
}

int		ft_window_expose(t_total *tot)
{
	if (tot->expose != 0)
	{
		ft_putendl("Refresh");
		mlx_clear_window(tot->mlx, tot->win);
		ft_plot_pt(tot);
	}
	tot->expose = 1;
	return (0);
}
