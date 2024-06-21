/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:49:43 by asaenko           #+#    #+#             */
/*   Updated: 2024/03/05 12:50:15 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, char c)
{
	int	i;
	int	count;
	int	word;

	i = 0;
	count = 0;
	word = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[i])
	{
		if (str[i] != c && str[i])
			word = 1;
		if (str[i] == c)
		{
			while (str[i] == c && str[i])
				i++;
			if (str[i])
				count++;
		}
		else
			i++;
	}
	return (count + word);
}

static char	*put_word(char *str, char c)
{
	int		i;
	char	*arr;

	i = 0;
	arr = NULL;
	while (str[i] && str[i] != c)
		i++;
	arr = (char *)malloc(sizeof(char) * (i + 1));
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, str, i + 1);
	return (arr);
}

static void	*free_array(char **array, int i)
{
	while (i > 0)
	{
		free(array[i--]);
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	char	**array;

	i = -1;
	if (!s)
		return (NULL);
	words = count_words((char *)s, c);
	array = malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	while (++i < words)
	{
		while (*s == c)
			s++;
		array[i] = put_word((char *)s, c);
		if (!array)
			free_array(array, i);
		s += ft_strlen(array[i]);
	}
	array[i] = NULL;
	return (array);
}
