/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 15:50:09 by jonkim            #+#    #+#             */
/*   Updated: 2017/10/09 22:29:28 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		end;
	int		start;
	int		i;

	if (s == NULL)
		return (NULL);
	end = 0;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end++;
	if (s[end] == '\0')
		return (ft_strnew(0));
	start = end;
	while (s[end + 1] != '\0')
		end++;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	if (!(new = (char*)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	i = -1;
	while (++i < (end - start + 1))
		new[i] = s[i + start];
	new[i] = '\0';
	return (new);
}
