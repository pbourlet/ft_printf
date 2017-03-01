/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:49:00 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/01 17:12:33 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_pos(char *str, intmax_t *i, int base, intmax_t nb)
{
	while (nb != 0)
	{
		if (nb % base <= base - 1)
			str[*i] = (nb % base) + '0';
		if (nb % base >= 10)
			str[*i] = 'a' + ((nb % base) % 10);
		nb = nb / base;
		*i = *i + 1;
	}
	str[*i] = '\0';
	return (str);
}

int		ft_nblenmax(intmax_t n, int base)
{
	int			len;
	long double pow;

	pow = 1;
	len = 0;
	if (n < 0)
		len++;
	n < 0 ? n = -n : 0;
	while (n >= (pow *= base))
		len++;
	return (len + 1);
}

char	*ft_itoabase(intmax_t nb, int base)
{
	char		*str;
	intmax_t	i;
	intmax_t	nt;

	i = 0;
	nt = nb;
	if (nb == LONG_MIN)
		return ((str = ft_strdup("-9223372036854775808")));
	if (!(str = ft_strnew(ft_nblenmax(nb, base))))
		return (NULL);
	if (nb == 0)
		return (ft_strcpy(str, "0"));
	if (nb < 0 && base == 10)
		nb = -nb;
	str = ft_pos(str, &i, base, nb);
	if (nt < 0 && base == 10)
	{
		str = ft_strcjoin(str, '-');
		i++;
	}
	str[i] = '\0';
	str = ft_strrev(str);
	return (str);
}
