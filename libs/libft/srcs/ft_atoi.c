/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 16:55:24 by jonkim            #+#    #+#             */
/*   Updated: 2017/10/09 21:49:40 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	num;
	int neg;

	neg = 1;
	num = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == 45)
	{
		neg = -1;
		str++;
	}
	else if (*str == 43)
		str++;
	while (*str <= 57 && *str >= 48)
	{
		num *= 10;
		num += *str - 48;
		str++;
	}
	return (num *= neg);
}
