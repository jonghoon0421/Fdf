/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 20:28:39 by jonkim            #+#    #+#             */
/*   Updated: 2017/10/05 13:24:37 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*begin;

	begin = (char*)str;
	while (*str)
		str++;
	if (c == '\0')
		return ((char*)str);
	while (str > begin)
	{
		if (*str == c)
			return ((char*)str);
		str--;
	}
	if (str == begin && *str == c)
		return ((char*)str);
	else
		return (NULL);
}
