/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 18:41:21 by jonkim            #+#    #+#             */
/*   Updated: 2017/10/09 17:48:08 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	k = 0;
	while (dest[i])
		i++;
	while (src[j])
		j++;
	if (size > (i + 1))
	{
		while (k < (size - i - 1))
		{
			dest[i + k] = src[k];
			k++;
		}
		dest[i + k] = '\0';
	}
	if (i <= size)
		return (i + j);
	else
		return (size + j);
}
