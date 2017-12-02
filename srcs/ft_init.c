/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:15:10 by jonkim            #+#    #+#             */
/*   Updated: 2017/12/01 13:31:16 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_val(t_total *tot)
{
	tot->red = 0xFF0000;
	tot->def_wid = 1200;
	tot->def_hgt = 900;
	tot->st_x = tot->def_wid / 2;
	tot->st_y = tot->def_hgt / 2;
	tot->z_scale = 75;
	tot->min_z = 2147483647;
	tot->max_z = -2147483648;
}

void	ft_init_reset(t_total *tot)
{
	tot->angle_x = 0;
	tot->angle_y = 0;
	tot->angle_z = 0;
	tot->zoom = 0;
	tot->z_scale = 100;
	tot->move_y = 0;
	tot->move_x = 0;
}

void	ft_init_msg(t_total *tot)
{
	mlx_string_put(tot->mlx, tot->win, 10, 0, 0xFFFFDF, "[+, -] Zoom");
	mlx_string_put(tot->mlx, tot->win, 10, 15, 0xFFFFDF,
		"[Q, W] Rotate X-axis");
	mlx_string_put(tot->mlx, tot->win, 10, 30, 0xFFFFDF,
		"[A, S] Rotate Y-axis");
	mlx_string_put(tot->mlx, tot->win, 10, 45, 0xFFFFDF,
		"[Z, X] Rotate Z-axis");
	mlx_string_put(tot->mlx, tot->win, 10, 60, 0xFFFFDF,
		"[O, P] Change altitude");
	mlx_string_put(tot->mlx, tot->win, 10, 75, 0xFFFFDF, "[ARROW] Move");
	mlx_string_put(tot->mlx, tot->win, 10, 90, 0xFFFFDF, "[N] Reset");
	mlx_string_put(tot->mlx, tot->win, 10, 105, 0xFFFFDF, "[ESC] Exit");
	mlx_string_put(tot->mlx, tot->win, 490, 870, 0xFFFFDF,
		"Zoom in to see the object");
}

void	ft_init_color_x(t_total *tot, int x, int y)
{
	if (tot->ptdup[y][x].z == tot->ptdup[y][x + 1].z && tot->ptdup[y][x].z == 0)
		tot->color = 0xFF8C8C;
	else if (tot->ptdup[y][x].z == tot->ptdup[y][x + 1].z)
		tot->color = tot->red;
	else
		tot->color = 0x910000;
}

void	ft_init_color_y(t_total *tot, int x, int y)
{
	if (tot->ptdup[y][x].z == tot->ptdup[y + 1][x].z && tot->ptdup[y][x].z == 0)
		tot->color = 0xFF8C8C;
	else if (tot->ptdup[y][x].z == tot->ptdup[y + 1][x].z)
		tot->color = tot->red;
	else
		tot->color = 0x910000;
}
