/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboulogn <tboulogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:49:38 by tboulogn          #+#    #+#             */
/*   Updated: 2024/11/15 15:39:19 by tboulogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			word++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (word);
}

int	ft_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_free(char **words, int j)
{
	while (j > 0)
	{
		free(words[--j]);
	}
	return (NULL);
}

char	**ft_malloc(char const *s, char c)
{
	char	**words;
	int		num_words;

	num_words = count_words(s, c);
	words = malloc((num_words + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		i;
	int		j;
	int		word_len;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	words = ft_malloc(s, c);
	if (!words)
		return (NULL);
	while (s[i] && j < count_words(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		word_len = ft_len(&s[i], c);
		words[j] = ft_substr(s, i, word_len);
		if (!words[j])
			ft_free(words, j);
		i += word_len;
		j++;
	}
	words[j] = NULL;
	return (words);
}
