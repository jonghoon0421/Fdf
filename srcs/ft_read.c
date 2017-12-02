/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:29:00 by jonkim            #+#    #+#             */
/*   Updated: 2017/12/01 13:55:03 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_read_allocate(t_total *tot)
{
	int i;

	i = -1;
	tot->pt = (t_point**)malloc(sizeof(t_point*) * tot->pic_hgt);
	tot->ptdup = (t_point**)malloc(sizeof(t_point*) * tot->pic_hgt);
	if (tot->pt == NULL || tot->ptdup == NULL)
		ft_error_msg("Memory allocation failed");
	while (++i < tot->pic_hgt)
	{
		tot->pt[i] = (t_point*)malloc(sizeof(t_point) * tot->pic_wid);
		tot->ptdup[i] = (t_point*)malloc(sizeof(t_point) * tot->pic_wid);
		if (tot->pt[i] == NULL || tot->ptdup[i] == NULL)
			ft_error_msg("Memory allocation failed");
	}
}

void	ft_read_buf(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (!ft_strchr(FT_CHECK_BUF, str[i]))
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
	(ret = read(fd, buf, BUFF_SIZE)) == 0 ? ft_error_msg("File error") : 0;
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

void	ft_read_tmp(char **tmp, t_total *tot, int i)
{
	int j;

	j = 0;
	while (tmp[j] != NULL)
		j++;
	if ((tot->map[i] = (int*)malloc(sizeof(int) * j)) == NULL)
		ft_error_msg("Memory allocation failed");
	if (tot->pic_wid == 0)
		tot->pic_wid = j;
	else if ((tot->pic_wid != 0 && tot->pic_wid != j) || j == 1)
		ft_error_msg("File error");
	j = -1;
	while (tmp[++j] != NULL)
	{
		if (ft_atoi(tmp[j]) < tot->min_z)
			tot->min_z = ft_atoi(tmp[j]);
		if (ft_atoi(tmp[j]) > tot->max_z)
			tot->max_z = ft_atoi(tmp[j]);
		tot->map[i][j] = ft_atoi(tmp[j]);
	}
}

void	ft_read_file(char **av, t_total *tot)
{
	char	**tmp;
	int		i;
	char	*line;

	if (ft_strstr(av[0], ".fdf") == NULL)
		ft_error_msg("Only [.fdf] files are supported");
	if ((tot->fd = open(av[0], O_RDONLY)) < 0)
		ft_error_msg("File error");
	tot->map = (int**)malloc(sizeof(int*) * (ft_read_line(av, tot) + 1));
	if (tot->map == NULL)
		ft_error_msg("Memory allocation failed");
	i = -1;
	while (get_next_line(tot->fd, &line) == 1)
	{
		tmp = ft_strsplit(line, ' ');
		ft_read_tmp(tmp, tot, ++i);
	}
	tot->max_z -= tot->min_z;
	tot->min_z = 0;
	ft_read_allocate(tot);
}
