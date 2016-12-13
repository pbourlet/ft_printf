/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:47:54 by pbourlet          #+#    #+#             */
/*   Updated: 2016/12/13 21:39:49 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itohx(unsigned long nb)
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
		if (nb % 16 <= 15)
			str[i] = (nb % 16) + '0';
		if (nb % 16 >= 10)
			str[i] = 'a' + ((nb % 16) % 10);
		nb = nb / 16;
		i++;
	}
	str[i++] = 'x';
	str[i++] = '0';
	str[i] = '\0';
	str = ft_strrev(str);
	return (str);
}

char	**ft_stocksimple(char **tab, char *s, va_list ap, int i, int *a)
{
	if (s[i] == 's')
		tab[*a] = ft_strjoin(tab[*a], va_arg(ap, char *));
	else if (s[i] == 'd' || s[i] == 'i')
		tab[*a] = ft_strjoin(tab[*a], ft_itoa(va_arg(ap, int)));
	else if (s[i] == 'c')
		tab[*a] = ft_strcjoin(tab[*a], va_arg(ap, int));
	else if (s[i] == 'u')
		tab[*a] = ft_strdup(ft_itoalu(va_arg(ap, unsigned int)));
	else if (s[i] == 'p')
		tab[*a] = ft_strdup(ft_itohx(va_arg(ap, unsigned long)));
	return (tab);
}

char	**ft_stocklong(char **tab, char *s, va_list ap, int i, int *a)
{
	i++;
	if (s[i] == 'i' || s[i] == 'd')
		tab[*a] = ft_strjoin(tab[*a], ft_itoalong(va_arg(ap, long int)));
	else if (s[i] == 'u')
		tab[*a] = ft_strdup(ft_itoalu(va_arg(ap, unsigned long)));
	return (tab);
}

char	**ft_stock(char *s, va_list ap)
{
	char	**tab;
	int		i;
	int		c;
	int		a;

	i = -1;
	c = 0;
	a = 1;
	if (!(*tab = malloc(sizeof(va_list) * 100)))
		return (NULL);
	while (s[++i])
	{
		tab[a] = ft_strnew(0);
		if (!(c = 0) && s[i] == '%')
		{
			if (!(s[i + c] == 's' || s[i + c] == 'd' || s[i + c] == 'c'
			|| s[i + c] == 'l' || s[i + c] == 'i' || s[i + c] == 'u'
			|| s[i + c] == 'p'))
				c++;
			if (s[i + c] == 's' || s[i + c] == 'd' || s[i + c] == 'c'
					|| s[i + c] == 'i' || s[i + c] == 'u' || s[i + c] == 'p')
				tab = ft_stocksimple(tab, s, ap, i + c, &a);
			else if (s[i + c] == 'l')
				tab = ft_stocklong(tab, s, ap, i + c, &a);
			a++;
		}
	}
	return (tab);
}
