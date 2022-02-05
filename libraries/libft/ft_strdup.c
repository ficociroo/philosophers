/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:43:21 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/02/19 18:29:22 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	size;

	size = ft_strlen(s) + 1;
	new_str = (char *)malloc(size);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s, size);
	return (new_str);
}
