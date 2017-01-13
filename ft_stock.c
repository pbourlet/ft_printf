/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:47:54 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/13 12:57:39 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**ft_stocksimple(char **tab, char *s, va_list ap, int i, int *a)
{
	if (s[i] == 's')
		tab[*a] = ft_strdup(va_arg(ap, char *));
	else if (s[i] == 'd' || s[i] == 'i')
		tab[*a] = ft_strdup(ft_itoa(va_arg(ap, int)));
	else if (s[i] == 'D')
		tab[*a] = ft_strdup(ft_itoalong(va_arg(ap, long)));
	else if (s[i] == 'c')
		tab[*a] = ft_strcjoin(tab[*a], va_arg(ap, int));
	else if (s[i] == 'C' || (s[i] == 'l' && (s[i + 1] == 'c'
	|| s[i + 1] == 'C')))
		tab[*a] = ft_strdup(ft_itoabase(va_arg(ap, unsigned int), 2));
	else if (s[i] == 'u')
		tab[*a] = ft_strdup(ft_itoalu(va_arg(ap, unsigned)));
	else if (s[i] == 'U')
		tab[*a] = ft_strdup(ft_itoalu(va_arg(ap, unsigned long)));
	else if (s[i] == 'p' || (s[i] == 'l' && s[i + 1] == 'p'))
		tab[*a] = ft_strdup(ft_itohx(va_arg(ap, unsigned long)));
	else if (s[i] == 'x')
		tab[*a] = ft_strdup(ft_itohx(va_arg(ap, unsigned)));
	else if (s[i] == 'o')
		tab[*a] = ft_strdup(ft_itoaoc(va_arg(ap, unsigned)));
	else if (s[i] == 'O')
		tab[*a] = ft_strdup(ft_itoaoc(va_arg(ap, unsigned long)));
	else if (s[i] == 'X')
		tab[*a] = ft_strdup(stup(ft_itohx(va_arg(ap, unsigned))));
	return (tab);
}

char	**ft_stocklong(char **tab, char *s, va_list ap, int i, int *a)
{
	i++;
	if (s[i] == 'i' || s[i] == 'd' || s[i] == 'D')
		tab[*a] = ft_strjoin(tab[*a], ft_itoalong(va_arg(ap, long int)));
	else if (s[i] == 'X')
		tab[*a] = ft_strdup(stup(ft_itohx(va_arg(ap, unsigned long))));
	else if (s[i] == 'x')
		tab[*a] = ft_strdup(ft_itohx(va_arg(ap, unsigned long)));
	else if (s[i] == 'u' || s[i] == 'U')
		tab[*a] = ft_strdup(ft_itoalu(va_arg(ap, unsigned long)));
	else if (s[i] == 'o' || s[i] == 'O')
		tab[*a] = ft_strdup(ft_itoaoc(va_arg(ap, unsigned long)));
//	else
//		*a = *a - 1;
	return (tab);
}
/*
char	**ft_stockspec(char **tab, char *s, va_list ap, int i, int *a)
{
	if (s[i] == 'S')
		tab[*a] = ft_strdup(ft_itoabase(va_arg(ap, wchar_t *), 2));
	return (tab);
}*/

int	testdiff(char *s, int i)
{
	if (!(s[i] == 's' || s[i] == 'd' || s[i] == 'c'	|| s[i] == 'l'
	|| s[i] == 'i' || s[i] == 'u' || s[i] == 'p' || s[i] == 'o'
	|| s[i] == 'x' || s[i] == 'X' || s[i] == 'D' || s[i] == 'O'
	|| s[i] == 'U' || s[i] == 'C' || s[i] == 'h' || s[i] == 'j'))
		return (1);
	if (s[i] == 's' || s[i] == 'd' || s[i] == 'c' || s[i] == 'i'
	|| s[i] == 'u' || s[i] == 'p' || s[i] == 'o' || s[i] == 'x'
	|| s[i] == 'X' || s[i] == 'D' || s[i] == 'O' || s[i] == 'U'
	|| s[i] == 'C')
		return (2);
	if (s[i] == 'l' && (s[i + 1] == 'c' || s[i + 1] == 'p'
	|| s[i + 1] == 'C'))
		return (2);
	if (s[i] == 'l')
		return (ft_stocktestlong(s, &i));
	if (s[i] == 'S')
		return (4);
	if (s[i] == 'h')
		return (5);
	if (s[i] == 'j')
		return (ft_stocktestlong(s, &i) + 3);
	return (0);
}

char	**ft_stock(char *s, va_list ap)
{
	char	**tab;
	int		i;
	int		c;
	int		a;

	i = -1;
	c = 0;
	a = 0;
	if (!(tab = malloc(sizeof(va_list) * 100)))
		return (NULL);
	while (s[++i])
	{
		if (!(c = 0) && s[i] == '%')
		{
			tab[++a] = ft_strnew(0);
			if (testdiff(s, (i + c)) == 1)
				c++;
			if (testdiff(s, (i + c)) == 2)
				tab = ft_stocksimple(tab, s, ap, i + c, &a);
			else if (testdiff(s, (i + c)) == 3)
				tab = ft_stocklong(tab, s, ap, i + c, &a);
			else if (testdiff(s, (i + c)) == 5)
				tab = ft_stockh(tab, s, ap, i + c, &a);
			else if (testdiff(s, (i + c)) == 6)
				tab = ft_stockj(tab, s, ap, i + c, &a);
		}
	}
	return (tab);
}
