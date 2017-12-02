/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 17:03:02 by jonkim            #+#    #+#             */
/*   Updated: 2017/10/09 17:22:48 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			i;

	dest = (unsigned char*)str1;
	src = (unsigned char*)str2;
	i = 0;
	while (n > 0)
	{
		dest[i] = src[i];
		if (src[i] == (unsigned char)c)
			return (str1 + i + 1);
		i++;
		n--;
	}
	return (NULL);
}
