/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:13:05 by jonkim            #+#    #+#             */
/*   Updated: 2017/10/04 20:28:21 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*tmp;

	while (*str)
	{
		if (*str == c)
		{
			tmp = (char*)str;
			return (tmp);
		}
		str++;
	}
	if (c == '\0')
	{
		tmp = (char*)str;
		return (tmp);
	}
	return (NULL);
}
