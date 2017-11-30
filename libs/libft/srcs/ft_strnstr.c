/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:26:19 by jonkim            #+#    #+#             */
/*   Updated: 2017/10/09 21:28:50 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*small == '\0')
		return ((char*)big);
	while (big[i])
	{
		j = 0;
		while (big[i + j] == small[j] && n > i + j)
		{
			j++;
			if (small[j] == '\0')
				return ((char*)(big + i));
		}
		i++;
	}
	return (NULL);
}
