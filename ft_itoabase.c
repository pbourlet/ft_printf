/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:49:00 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/16 13:29:43 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoabase(intmax_t nb, int base)
{
	char	*str;
	intmax_t	i;
	intmax_t	nt;

	i = 0;
	nt = nb;
	if (!(str = ft_strnew(11)))
		return (NULL);
	if (nb == 0)
		return (ft_strcpy(str, "0"));
	if (nb < 0 && base == 10)
		nb = -nb;
	while (nb != 0)
	{
		if (nb % base <= base - 1)
			str[i] = (nb % base) + '0';
		if (nb % base >= 10)
			str[i] = 'a' + ((nb % base) % 10);
		nb = nb / base;
		i++;
	}
	if (nt < 0 && base == 10)
	{
		str = ft_strcjoin(str, '-');
		i++;
	}
	str[i] = '\0';
	str = ft_strrev(str);
	return (str);
}
