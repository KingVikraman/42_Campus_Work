/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:09:06 by zhewong           #+#    #+#             */
/*   Updated: 2025/01/16 17:02:05 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	ft_find_charsep(char str, char c)
{
	if (c == str)
		return (1);
	else if (str == '\0')
		return (1);
	return (0);
}

static int	ft_count_words(const char *str, char c)
{
	int	word;
	int	in_word;

	word = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && !in_word)
		{
			in_word = 1;
			word++;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (word);
}

static void	ft_copy_word(char *dest, const char *from, char c)
{
	int	i;

	i = 0;
	while (ft_find_charsep(from[i], c) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
	return ;
}

static void	ft_transfert(char **tab, const char *str, char c)
{
	int	i;
	int	word;
	int	j;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (ft_find_charsep(str[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (ft_find_charsep(str[i + j], c) == 0)
				j++;
			tab[word] = malloc(sizeof(char) * (j + 1));
			ft_copy_word(tab[word], str + i, c);
			i = i + j;
			word++;
		}
	}
	tab[word] = NULL;
	return ;
}

char	**ft_split(char const *str, char c)
{
	char	**tab;
	int		word;

	if (!str)
		return (NULL);
	word = ft_count_words(str, c);
	tab = malloc(sizeof(char *) * (word + 1));
	if (tab == NULL)
		return (NULL);
	tab[word] = 0;
	ft_transfert(tab, str, c);
	return (tab);
}
