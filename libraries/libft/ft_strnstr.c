/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:13:53 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/04/09 14:12:13 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (haystack == needle || *needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && len > 0)
	{
		if (len < ft_strlen(needle))
			return (NULL);
		if (!ft_strncmp(&haystack[i], needle, ft_strlen(needle)))
			return ((char *)haystack + i);
		i++;
		len--;
	}
	return (NULL);
}
