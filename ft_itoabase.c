/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:49:00 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/09 15:53:20 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoabase(long nb, int base)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = ft_strnew(11)))
		return (NULL);
	if (nb == 0)
		return (ft_strcpy(str, "0"));
	while (nb != 0)
	{
		if (nb % base <= base - 1)
			str[i] = (nb % base) + '0';
		if (nb % base >= 10)
			str[i] = 'a' + ((nb % base) % 10);
		nb = nb / base;
		i++;
	}
	str[i] = '\0';
	str = ft_strrev(str);
	return (str);
}
