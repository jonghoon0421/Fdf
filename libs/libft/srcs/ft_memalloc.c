/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 18:05:11 by jonkim            #+#    #+#             */
/*   Updated: 2017/10/05 19:55:48 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*st;

	if (!(st = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(st, size);
	return (void*)st;
}
