/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoalong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:52:53 by pbourlet          #+#    #+#             */
/*   Updated: 2016/12/13 15:53:42 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoalong(long int n)
{
	char		*str;
	long		nb;
	long int	i;
	long int	len;

	i = 0;
	nb = n;
	if (n < 0)
		nb = -nb;
	len = ft_nblen(nb);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1 + (n < 0)))))
		return (NULL);
	if (nb == 0)
		return (ft_strcpy(str, "0"));
	while (nb != 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	str = ft_strrev(str);
	return (str);
}
