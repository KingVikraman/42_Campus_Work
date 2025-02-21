/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:17:47 by rvikrama          #+#    #+#             */
/*   Updated: 2024/08/13 17:39:15 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *String)
{
	int	i;

	i = 0;
	while (String[i] != '\0')
		i++;
	return (i);
}
//--------------------//

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (sizetotal + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[sizetotal] = 0;
	return (res);
}
//------------------------//

void	*ft_calloc(size_t elementNum, size_t elementSize)
{
	size_t	i;
	char	*allocmem;
	size_t	totalsize;

	totalsize = elementSize * elementNum;
	allocmem = malloc(totalsize);
	if (!allocmem)
	{
		return (NULL);
	}
	i = 0;
	while (i < totalsize)
	{
		allocmem[i] = 0;
		i++;
	}
	return (allocmem);
}
//---------------------------//

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
//--------------------------------//

char	*ft_strchr(const char *string, int searchChar )
{
	char	*str;

	str = (char *)string;
	while (*str != searchChar && *str != 0)
		str++;
	if (*str == searchChar)
		return (str);
	else
		return (NULL);
}
