/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:05:49 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/02/18 18:03:11 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			destlen;
	size_t			srclen;
	unsigned int	i;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	i = 0;
	while (*dest != '\0' && i < size)
	{
		dest++;
		i++;
	}
	while (*src != '\0' && i < (size - 1) && size)
	{
		*dest++ = *src++;
		i++;
	}
	if (size > destlen && size != 0)
		*dest = '\0';
	if (size < destlen)
		return (srclen + size);
	return (destlen + srclen);
}
