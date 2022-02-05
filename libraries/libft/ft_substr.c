/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:43:44 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/06/12 00:24:34 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_newstr(0));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	new_str = (char *)ft_calloc(len + 1, sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, (s + start), len + 1);
	return (new_str);
}
