/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:39:20 by zhewong           #+#    #+#             */
/*   Updated: 2025/01/16 20:39:26 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char	*buf_dest;
	unsigned char	*buf_src;

	buf_dest = (unsigned char *)dest;
	buf_src = (unsigned char *)src;
	if (dest == src)
		return (dest);
	while (size--)
		*(buf_dest++) = *(buf_src++);
	return (dest);
}

char	*flatten_env_var(t_env_elem *env_elem, t_mem *mem)
{
	char	*ret;
	size_t	key_len;
	size_t	val_len;
	size_t	total_len;

	if (!env_elem || !env_elem->key || !env_elem->value)
		return (NULL);
	key_len = ft_strlen(env_elem->key);
	val_len = ft_strlen(env_elem->value);
	total_len = key_len + val_len + 2;
	ret = (char *)malloc(sizeof(char) * total_len);
	if (!ret)
		failure(-1, mem);
	ft_memcpy(ret, env_elem->key, key_len);
	ret[key_len] = '=';
	ft_memcpy(ret + key_len + 1, env_elem->value, val_len);
	ret[key_len + 1 + val_len] = '\0';
	return (ret);
}

int	list_env_len(t_env_list *env)
{
	int			count;
	t_env_elem	*elem;

	count = 0;
	if (!env)
		return (0);
	elem = env->first;
	while (elem)
	{
		count++;
		elem = elem->next;
	}
	return (count);
}

char	**ft_env_string_tab(t_env_list *env, t_mem *mem)
{
	int			i;
	int			length;
	char		**ret;
	t_env_elem	*elem;

	length = list_env_len(env);
	ret = (char **)malloc(sizeof(char *) * (length + 1));
	if (!ret)
		failure(-1, mem);
	ret[length] = NULL;
	i = 0;
	if (env)
		elem = env->first;
	else
		elem = NULL;
	while (elem)
	{
		ret[i] = flatten_env_var(elem, mem);
		i++;
		elem = elem->next;
	}
	return (ret);
}
