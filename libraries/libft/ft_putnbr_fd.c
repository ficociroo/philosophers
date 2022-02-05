/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:46:26 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/04/09 14:11:52 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	cst;
	int		ret;

	cst = (long)n;
	ret = 0;
	if (cst < 0)
	{
		cst = -cst;
		ft_putchar_fd('-', fd);
		ret++;
	}
	if (cst > 9)
	{
		ret += ft_putnbr_fd(cst / 10, fd);
		ret += ft_putchar_fd((cst % 10) + '0', fd);
	}
	else
		ret += ft_putchar_fd(cst + '0', fd);
	return (ret);
}
