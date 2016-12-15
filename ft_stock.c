/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:47:54 by pbourlet          #+#    #+#             */
/*   Updated: 2016/12/15 17:25:33 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**ft_stocksimple(char **tab, char *s, va_list ap, int i, int *a)
{
	if (s[i] == 's')
		tab[*a] = ft_strdup(va_arg(ap, char *));
	else if (s[i] == 'd' || s[i] == 'i')
		tab[*a] = ft_strdup(ft_itoa(va_arg(ap, int)));
	else if (s[i] == 'c')
		tab[*a] = ft_strcjoin(tab[*a], va_arg(ap, int));
	else if (s[i] == 'u')
		tab[*a] = ft_strdup(ft_itoalu(va_arg(ap, unsigned int)));
	else if (s[i] == 'p')
		tab[*a] = ft_strdup(ft_itohx(va_arg(ap, unsigned long)));
	else if (s[i] == 'x')
		tab[*a] = ft_strdup(ft_itohx(va_arg(ap, unsigned long)));
	else if (s[i] == 'o')
		tab[*a] = ft_strdup(ft_itoaoc(va_arg(ap, unsigned int)));
	else if (s[i] == 'X')
		tab[*a] = ft_strdup(ft_strtoupper(ft_itohx(va_arg(ap, unsigned long))));
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
	if (!(tab = malloc(sizeof(va_list) * 100)))
		return (NULL);
	while (s[++i])
	{
		tab[a] = ft_strnew(0);
		if (!(c = 0) && s[i] == '%')
		{
			if (!(s[i + c] == 's' || s[i + c] == 'd' || s[i + c] == 'c'
			|| s[i + c] == 'l' || s[i + c] == 'i' || s[i + c] == 'u'
			|| s[i + c] == 'p' || s[i + c] == 'o' || s[i + c] == 'x' || s[i + c] == 'X'))
				c++;
			if (s[i + c] == 's' || s[i + c] == 'd' || s[i + c] == 'c'
			|| s[i + c] == 'i' || s[i + c] == 'u' || s[i + c] == 'p'
			|| s[i + c] == 'o' || s[i + c] == 'x' || s[i + c] == 'X')
				tab = ft_stocksimple(tab, s, ap, i + c, &a);
			else if (s[i + c] == 'l')
				tab = ft_stocklong(tab, s, ap, i + c, &a);
			a++;
		}
	}
	return (tab);
}
