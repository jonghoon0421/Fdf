/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 17:08:39 by jonkim            #+#    #+#             */
/*   Updated: 2017/10/09 17:54:35 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*conv;
	int		leng;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	leng = ft_find_length(n);
	if (!(conv = (char*)malloc(sizeof(char) * (leng + 1))))
		return (NULL);
	conv[leng] = '\0';
	if (n < 0)
	{
		conv[0] = '-';
		n *= -1;
	}
	while (n > 9)
	{
		conv[--leng] = (n % 10) + 48;
		n /= 10;
	}
	conv[--leng] = n + 48;
	return (conv);
}
