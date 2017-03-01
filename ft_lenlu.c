/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenlu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 12:56:43 by pbourlet          #+#    #+#             */
/*   Updated: 2017/02/28 17:36:58 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

long int	ft_lenlu(unsigned long nb)
{
	long int digit;

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
