/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 17:02:52 by jonkim            #+#    #+#             */
/*   Updated: 2017/10/09 22:18:11 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**count_words(char **table, char const *str, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		i++;
		if (str[i] == c)
		{
			word_count++;
			while (str[i] == c)
				i++;
		}
	}
	if (str[i - 1] != c)
		word_count++;
	table = (char**)malloc(sizeof(char*) * (word_count + 1));
	if (table == NULL)
		return (table = NULL);
	table[word_count] = NULL;
	return (table);
}

static char	**count_chars(char **table, char const *str, char c)
{
	int	i;
	int	j;
	int	char_count;

	i = 0;
	j = 0;
	char_count = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		i++;
		if (str[i] == c || str[i] == '\0')
		{
			table[j] = (char*)malloc(sizeof(char) * (char_count + 1));
			if (table[j] == NULL)
				return (NULL);
			char_count = 0;
			j++;
			while (str[i] == c)
				i++;
		}
		char_count++;
	}
	return (table);
}

static char	**actual_work(char **table, char const *str, char c)
{
	int	i;
	int	row;
	int	col;

	i = 0;
	row = 0;
	col = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		table[row][col] = str[i];
		i++;
		col++;
		if (str[i] == c || str[i] == '\0')
		{
			table[row][col] = '\0';
			row++;
			col = 0;
			while (str[i] == c)
				i++;
		}
	}
	return (table);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**table;

	if (s == NULL)
		return (NULL);
	table = NULL;
	table = count_words(table, s, c);
	if (table == NULL)
		return (NULL);
	if (s[0] == '\0')
	{
		table[0] = NULL;
		return (table);
	}
	table = count_chars(table, s, c);
	table = actual_work(table, s, c);
	return (table);
}
