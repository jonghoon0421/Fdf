/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 23:40:53 by jonkim            #+#    #+#             */
/*   Updated: 2017/10/10 01:24:06 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		ft_convert(const char *s, int base)
{
	int		i;
	long	n;

	i = 0;
	n = 0;
	while ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f')
			|| (s[i] >= 'A' && s[i] <= 'F'))
	{
		n *= base;
		if (s[i] >= '0' && s[i] <= '9')
			n += s[i] - 48;
		else if (s[i] >= 'a' && s[i] <= 'f')
			n += s[i] - 87;
		else if (s[i] >= 'A' && s[i] <= 'F')
			n += s[i] - 55;
		i++;
	}
	return (n);
}

int				ft_atoi_base(const char *s, int base)
{
	long	num;
	int		i;
	int		neg;

	num = 0;
	i = 0;
	neg = 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\f'
			|| s[i] == '\v' || s[i] == '\t' || s[i] == '\r')
		i++;
	if (s[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	num = ft_convert(s + i, base);
	return ((int)num * neg);
}
