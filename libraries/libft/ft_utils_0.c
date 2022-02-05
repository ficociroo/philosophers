/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:01:45 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/06/11 18:54:11 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	gnl_free_str_sta(int fd, char **str_sta, char *buf)
{
	free(buf);
	if (str_sta[fd] != NULL)
	{
		free(str_sta[fd]);
		str_sta[fd] = NULL;
		return (2);
	}
	else
		return (-2);
}
