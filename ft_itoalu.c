/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoalu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:43:02 by pbourlet          #+#    #+#             */
/*   Updated: 2016/12/13 17:41:47 by pbourlet         ###   ########.fr       */
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

char	*ft_itoalu(unsigned long n)
{
	char			*str;
	unsigned long	nb;
	unsigned long	i;
	unsigned long	len;

	i = 0;
	nb = n;
	len = ft_lenlu(nb);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (nb == 0)
		return (ft_strcpy(str, "0"));
	while (nb != 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	str[i] = '\0';
	str = ft_strrev(str);
	return (str);
}
