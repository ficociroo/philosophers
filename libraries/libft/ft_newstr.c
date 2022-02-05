/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 23:05:41 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/04/09 14:11:40 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_newstr(int size)
{
	char	*newstr;

	newstr = (char *)malloc(sizeof(char) * (size + 1));
	if (newstr == NULL)
		return (NULL);
	ft_bzero(newstr, size + 1);
	return (newstr);
}
