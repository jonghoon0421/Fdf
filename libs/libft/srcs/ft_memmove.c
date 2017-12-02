/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 20:16:05 by jonkim            #+#    #+#             */
/*   Updated: 2017/10/09 22:09:44 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char	*dest;
	char	*src;
	size_t	i;

	i = -1;
	dest = (char*)str1;
	src = (char*)str2;
	if (dest < src)
		while (++i < n)
			*(dest + i) = *(src + i);
	else
		while ((int)(--n) >= 0)
			*(dest + n) = *(src + n);
	return (str1);
}
