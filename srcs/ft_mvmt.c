/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mvmt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:40:21 by jonkim            #+#    #+#             */
/*   Updated: 2017/11/27 21:20:25 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rot_x(t_total *tot)
{
	float	y;
	float	z;
	int		i;
	int		j;

	i = -1;
	while (++i < tot->pic_hgt)
	{
		j = -1;
		while (++j < tot->pic_wid)
		{
			y = tot->pt[i][j].y;
			z = tot->pt[i][j].z;
			tot->pt[i][j].y = (y * cos(tot->angle_x)) - (z * sin(tot->angle_x));
			tot->pt[i][j].z = (y * sin(tot->angle_x)) + (z * cos(tot->angle_x));
		}
	}
}

void	ft_rot_y(t_total *tot)
{
	float	x;
	float	z;
	int		i;
	int		j;

	i = -1;
	while (++i < tot->pic_hgt)
	{
		j = -1;
		while (++j < tot->pic_wid)
		{
			x = tot->pt[i][j].x;
			z = tot->pt[i][j].z;
			tot->pt[i][j].x = (z * sin(tot->angle_y)) + (x * cos(tot->angle_y));
			tot->pt[i][j].z = (z * cos(tot->angle_y)) - (x * sin(tot->angle_y));
		}
	}
}

void	ft_rot_z(t_total *tot)
{
	float	x;
	float	y;
	int		i;
	int		j;

	i = -1;
	while (++i < tot->pic_hgt)
	{
		j = -1;
		while (++j < tot->pic_wid)
		{
			x = tot->pt[i][j].x;
			y = tot->pt[i][j].y;
			tot->pt[i][j].x = (x * cos(tot->angle_z)) - (y * sin(tot->angle_z));
			tot->pt[i][j].y = (x * sin(tot->angle_z)) + (y * cos(tot->angle_z));
		}
	}
}
