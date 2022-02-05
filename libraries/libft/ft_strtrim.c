/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:47:09 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/04/09 14:11:13 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	if (s1 == NULL || *s1 == '\0')
		return (ft_newstr(0));
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	if (s1[start] == '\0')
		return (ft_newstr(0));
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[end]) && end >= start)
		end--;
	len = ((end + 1) - start);
	return (ft_substr(s1, start, len));
}
