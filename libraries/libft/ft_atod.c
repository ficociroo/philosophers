/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:16:59 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/10/11 12:34:47 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [ENG] The function ft_atod, enables the conversion of a char array into a
** type double variable.
** For its correct functioning the array argument can be be initiated with white
** spaces, followed by a '+' or '-' signal, the value and must be finished with
** non-digit char or '\0'.
** This function can't convert all possible values of a double, been apparentely
** limited to [-9999999999.999998, 8589934592.999842].
**
** [POR_BR] A função ft_atod, possibilita converter uma ordem de caracteres
** (char *) numa variável de tipo double.
** Para o seu correto funcionamento o argumento da ordem pode ser iniciado com
** espaços em brancos, seguido do sinal '+' ou '-', o valor e precisa ser
** finalizada com caracteres não-dígitos ou '\0'.
** Essa função não dá conta de converter todos o valores possíveis de double,
** aparentemente estando limitada à [-9999999999.999998, 8589934592.999842].
*/

static int	handle_sign(int *i, const char *str)
{
	if (str[*i] == '+' || str[*i] == '-')
	{
		*i = *i + 1;
		if (str[*i - 1] == '-')
			return (-1);
	}
	return (1);
}

double	ft_atod(const char *str)
{
	int		sign;
	double	num;
	double	power;
	int		i;

	power = 1;
	num = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = handle_sign(&i, str);
	while (ft_isdigit((int)str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (ft_isdigit((int)str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		power *= 10;
		i++;
	}
	return (sign * num / power);
}
