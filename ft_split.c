/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:54:13 by cjullien          #+#    #+#             */
/*   Updated: 2020/12/07 19:33:17 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_free(char **tab, int k)
{
	while (--k >= 0)
		free(tab[k]);
	free(tab);
	return (0);
}

int		word_counter(char const *s, char c)
{
	int		counter;
	int		i;
	int		word;

	counter = 0;
	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			word = 0;
		}
		else if (word == 0)
		{
			word = 1;
			counter++;
		}
		i++;
	}
	return (counter);
}

int		splitter(char const *s, char c, char **tab, int word_len)
{
	int	k;
	int	l;
	int j;

	k = 0;
	j = 0;
	while (k < word_counter(s, c))
	{
		word_len = 0;
		while (s[j] && s[j] == c)
			j++;
		while (s[j++] && s[j] != c)
			word_len++;
		if (!(tab[k] = malloc(sizeof(char) * word_len + 1)))
			return (ft_free(tab, k));
		l = -1;
		while (++l <= word_len)
			tab[k][l] = s[l + j - word_len - 1];
		tab[k][l] = '\0';
		k++;
	}
	tab[k] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		word_len;

	word_len = 0;
	if (!s)
		return (NULL);
	if(!(tab = malloc(sizeof(char*) * word_counter(s, c) + 1)))
		return (NULL);
	if(splitter(s, c, tab, word_len))
		return (tab);
	return (NULL);
}
