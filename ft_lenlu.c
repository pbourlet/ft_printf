/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenlu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 12:56:43 by pbourlet          #+#    #+#             */
/*   Updated: 2016/12/14 12:56:48 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	ft_lenlu(unsigned long nb)
{
	long int 	digit;

	digit = 0;
	if (!nb)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		digit++;
	}
	return (digit);
}
