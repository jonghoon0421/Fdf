/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:29:00 by jonkim            #+#    #+#             */
/*   Updated: 2017/11/30 00:22:14 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_read_store(t_total *tot)
{
	int i;
	int j;

	i = -1;
	tot->pt = (t_point**)malloc(sizeof(t_point*) * tot->pic_hgt);
	tot->ptdup = (t_point**)malloc(sizeof(t_point*) * tot->pic_hgt);
	if (tot->pt == NULL)
		ft_error_msg("Memory allocation failed");
	while (++i < tot->pic_hgt)
	{
		tot->pt[i] = (t_point*)malloc(sizeof(t_point) * tot->pic_wid);
		tot->ptdup[i] = (t_point*)malloc(sizeof(t_point) * tot->pic_wid);
	}
	i = -1;
	while (++i < tot->pic_hgt)
	{
		j = -1;
		while (++j < tot->pic_wid)
		{
			tot->pt[i][j].x = j;
			tot->pt[i][j].y = i;
			tot->pt[i][j].z = (tot->map[i][j]) * (tot->z_scale / tot->max_z);
		}
	}
}

void	ft_read_buf(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (!ft_strchr(FT_CHKBUF, str[i]))
			ft_error_msg("File error");
	}
}

int		ft_read_line(char **av, t_total *tot)
{
	int		i;
	char	buf[BUFF_SIZE + 1];
	int		line_cnt;
	int		ret;
	int		fd;

	if ((fd = open(av[0], O_RDONLY)) < 0)
		ft_error_msg("File error");
	line_cnt = 0;
	(ret = read(fd, buf, BUFF_SIZE)) <= 0 ? ft_error_msg("File error") : 0;
	while (ret > 0)
	{
		buf[ret] = '\0';
		ft_read_buf(buf);
		i = -1;
		while (buf[++i] != '\0')
		{
			if (buf[i] == '\n')
				line_cnt++;
		}
		ret = read(fd, buf, BUFF_SIZE);
	}
	tot->pic_hgt = line_cnt;
	(line_cnt == 1 || line_cnt == 0) ? ft_error_msg("File error") : 0;
	return (line_cnt);
}

void	ft_read_tmp(char **tmp, t_total *tot, int j)
{
	int i;

	i = 0;
	while (tmp[i] != NULL)
		i++;
	tot->map[j] = (int*)malloc(sizeof(int) * i);
	if (tot->pic_wid == 0)
		tot->pic_wid = i;
	else if ((tot->pic_wid != 0 && tot->pic_wid != i) || i == 1)
		ft_error_msg("File error");
	i = -1;
	while (tmp[++i] != NULL)
	{
		if (ft_atoi(tmp[i]) < tot->min_z)
			tot->min_z = ft_atoi(tmp[i]);
		if (ft_atoi(tmp[i]) > tot->max_z)
			tot->max_z = ft_atoi(tmp[i]);
		tot->map[j][i] = ft_atoi(tmp[i]);
	}
}

void	ft_read_file(char **av, t_total *tot)
{
	char	**tmp;
	int		j;
	char	*line;

	if ((tot->fd = open(av[0], O_RDONLY)) < 0)
		ft_error_msg("File error");
	tot->map = (int**)malloc(sizeof(int*) * (ft_read_line(av, tot) + 1));
	j = -1;
	while (get_next_line(tot->fd, &line) == 1)
	{
		tmp = ft_strsplit(line, ' ');
		ft_read_tmp(tmp, tot, ++j);
	}
	tot->max_z += fabs(tot->min_z);
	tot->min_z -= tot->min_z;
	ft_read_store(tot);
}
