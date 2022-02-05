/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:36:23 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/02/18 23:21:24 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;

	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	if (!n)
		return (dest);
	if (pdest <= psrc)
		return (ft_memcpy(pdest, psrc, n));
	pdest += n;
	psrc += n;
	while (n--)
		*--pdest = *--psrc;
	return (pdest);
}
