/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:45:57 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/04/09 14:12:25 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n)
{
	int		i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
	{
		i++;
		n = n * (-1);
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	long	ncpy;
	char	*str;

	ncpy = n;
	len = ft_intlen(ncpy);
	str = ft_newstr(len);
	if (str == NULL)
		return (NULL);
	if (ncpy < 0)
		ncpy = -ncpy;
	*(str + len) = '\0';
	while (len--)
	{
		*(str + len) = (ncpy % 10) + '0';
		ncpy = ncpy / 10;
	}
	if (n < 0)
		*str = '-';
	return (str);
}
