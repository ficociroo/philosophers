/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 23:26:12 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/06/11 00:03:32 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strncmp_rev(const char *s1, const char *s2, size_t n)
{
	size_t		len_1;
	size_t		len_2;

	if (n == 0)
		return (0);
	len_1 = ft_strlen(s1) - 1;
	len_2 = ft_strlen(s2) - 1;
	if (len_1 + 1 < n)
		return (-(unsigned char)s2[--len_1]);
	else if (len_2 + 1 < n)
		return ((unsigned char)s1[--len_2]);
	while (n-- > 0)
	{
		if (s1[len_1] != s2[len_2])
			return ((unsigned char)s1[len_1] - ((unsigned char)s2[len_2]));
		len_1--;
		len_2--;
	}
	return (0);
}
