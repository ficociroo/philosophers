/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:14:20 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/02/15 18:32:50 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = -1;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (++i < n && *(ptr1 + i) == *(ptr2 + i))
		;
	if (i == n)
		return (0);
	return (*(ptr1 + i) - *(ptr2 + i));
}
