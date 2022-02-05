/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:44:33 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/02/12 19:34:55 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	h;

	str = (char *)s;
	h = (char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == h)
			return (&str[i]);
		i++;
	}
	if (!c)
		return (&str[i]);
	return (0);
}
