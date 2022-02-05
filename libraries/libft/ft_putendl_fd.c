/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:46:17 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/04/09 14:15:39 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	ret;

	ret = 0;
	if (s)
	{
		ret = ft_putstr_fd(s, fd);
		ret += ft_putchar_fd('\n', fd);
	}
	return (ret);
}
