/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:46:51 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/06/12 00:22:49 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strclen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static void	splitting(char const *s, char c, char **sub_cpy)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		if (s[j] != c)
		{
			i = ft_strclen(&s[j], c);
			*sub_cpy++ = ft_substr(s, j, i);
			j += i - 1;
			i = 0;
		}
		j++;
	}
	*sub_cpy = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**sub_split;
	char	**sub_cpy;
	int		sub_count;

	if (s == NULL)
		return (NULL);
	sub_count = ft_strcount((char *)s, c);
	sub_split = (char **)ft_calloc(sub_count + 1, sizeof(char *));
	if (sub_split == NULL)
		return (NULL);
	sub_cpy = sub_split;
	splitting(s, c, sub_cpy);
	return (sub_split);
}
