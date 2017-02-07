/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:42:42 by pbourlet          #+#    #+#             */
/*   Updated: 2017/02/07 15:53:36 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoibase(const char *str, int base)
{
	unsigned	char	*sstr;
	int					i;
	int					neg;
	int					num;

	i = 0;
	neg = 0;
	num = 0;
	sstr = (unsigned char *)str;
	while (sstr[i] <= ' ')
		i++;
	if (sstr[i] == '-')
		neg = 1;
	if ((sstr[i] == '-') || (sstr[i] == '+'))
		i++;
	while (sstr[i] >= '0' && sstr[i] <= (base - 1) + '0')
	{
		num *= base;
		num += (sstr[i] - '0');
		i++;
	}
	if (neg == 1)
		return (-num);
	else
		return (num);
}
