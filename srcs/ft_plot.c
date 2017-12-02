/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:18:44 by jonkim            #+#    #+#             */
/*   Updated: 2017/11/30 16:43:56 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_plot_prep(t_total *tot, t_point pt1, t_point pt2)
{
	tot->info.swap = 0;
	tot->info.dx = fabs(pt2.x - pt1.x);
	tot->info.dy = fabs(pt2.y - pt1.y);
	tot->info.s1 = SIGN(pt2.x - pt1.x);
	tot->info.s2 = SIGN(pt2.y - pt1.y);
	if (tot->info.dy > tot->info.dx)
	{
		tot->info.tmp = tot->info.dx;
		tot->info.dx = tot->info.dy;
		tot->info.dy = tot->info.tmp;
		tot->info.swap = 1;
	}
	tot->info.d = 2 * tot->info.dy - tot->info.dx;
	tot->info.x = pt1.x;
	tot->info.y = pt1.y;
}

void	ft_plot_connect(t_total *tot, t_point pt1, t_point pt2)
{
	float	i;

	ft_plot_prep(tot, pt1, pt2);
	i = 0;
	while (i < tot->info.dx)
	{
		mlx_pixel_put(tot->mlx, tot->win, tot->st_x + tot->info.x + tot->move_x,
			tot->st_y + tot->info.y + tot->move_y, tot->color);
		while (tot->info.d >= 0)
		{
			tot->info.d = tot->info.d - 2 * tot->info.dx;
			if (tot->info.swap)
				tot->info.x = tot->info.x + tot->info.s1;
			else
				tot->info.y = tot->info.y + tot->info.s2;
		}
		tot->info.d = tot->info.d + 2 * tot->info.dy;
		if (tot->info.swap)
			tot->info.y = tot->info.y + tot->info.s2;
		else
			tot->info.x = tot->info.x + tot->info.s1;
		i++;
	}
}

void	ft_plot_pt(t_total *tot)
{
	int x;
	int y;

	y = 0;
	while (y < tot->pic_hgt)
	{
		x = 0;
		while (x < tot->pic_wid)
		{
			if (x + 1 < tot->pic_wid)
			{
				ft_init_color_x(tot, x, y);
				ft_plot_connect(tot, tot->pt[y][x], tot->pt[y][x + 1]);
			}
			if (y + 1 < tot->pic_hgt)
			{
				ft_init_color_y(tot, x, y);
				ft_plot_connect(tot, tot->pt[y][x], tot->pt[y + 1][x]);
			}
			x++;
		}
		y++;
	}
	ft_init_msg(tot);
}

void	ft_plot_setup(t_total *tot)
{
	int i;
	int j;

	i = -1;
	while (++i < tot->pic_hgt)
	{
		j = -1;
		while (++j < tot->pic_wid)
		{
			tot->pt[i][j].x = (j - (tot->pic_wid / 2)) *
				((tot->def_wid / 2) / tot->pic_wid) * (tot->zoom < 0 ?
				0 : tot->zoom);
			tot->pt[i][j].y = (i - (tot->pic_hgt / 2)) *
				((tot->def_hgt / 2) / tot->pic_hgt) * (tot->zoom < 0 ?
				0 : tot->zoom);
			if (tot->max_z == 0)
				tot->pt[i][j].z = 0;
			else
				tot->pt[i][j].z = (tot->map[i][j] * (tot->z_scale /
					tot->max_z)) * (tot->zoom < 0 ? 0 : tot->zoom);
		}
	}
	ft_plot_dup(tot);
}

void	ft_plot_dup(t_total *tot)
{
	int i;
	int j;

	i = -1;
	while (++i < tot->pic_hgt)
	{
		j = -1;
		while (++j < tot->pic_wid)
		{
			tot->ptdup[i][j].x = (j - (tot->pic_wid / 2)) *
				((tot->def_wid / 2) / tot->pic_wid) * (tot->zoom < 0 ?
				0 : tot->zoom);
			tot->ptdup[i][j].y = (i - (tot->pic_hgt / 2)) *
				((tot->def_wid / 2) / tot->pic_hgt) * (tot->zoom < 0 ?
				0 : tot->zoom);
			if (tot->max_z == 0)
				tot->ptdup[i][j].z = 0;
			else
				tot->ptdup[i][j].z = (tot->map[i][j] * (tot->z_scale /
					tot->max_z)) * (tot->zoom < 0 ? 0 : tot->zoom);
		}
	}
}
