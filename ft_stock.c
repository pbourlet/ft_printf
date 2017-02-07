/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:47:54 by pbourlet          #+#    #+#             */
/*   Updated: 2017/02/07 23:41:32 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_stocksimp(char *s, va_list ap, int i)
{
	char *tab;

	tab = ft_strnew(0);
	if (s[i] == 's')
		tab = ft_stocksimps(tab, ap);
	else if (s[i] == '%')
		tab = ft_strdup("%");
	else if (s[i] == 'd' || s[i] == 'i')
		tab = ft_itoa(va_arg(ap, int));
	else if (s[i] == 'c')
		tab = ft_strcjoin(tab, va_arg(ap, int));
	else if (s[i] == 'C')
		tab = ft_bintoa(ft_itoabase(va_arg(ap, unsigned int), 2));
	else if (s[i] == 'u')
		tab = ft_itoalu(va_arg(ap, unsigned));
	else if (s[i] == 'U' || s[i] == 'p' || s[i] == 'O')
		tab = ft_stocklong(s, ap, i);
	else if (s[i] == 'x')
		tab = ft_itohx(va_arg(ap, unsigned));
	else if (s[i] == 'o')
		tab = ft_itoaoc(va_arg(ap, unsigned));
	else if (s[i] == 'X')
		tab = stup(ft_itohx(va_arg(ap, unsigned)));
	return (tab);
}

char	*ft_stocklong(char *s, va_list ap, int i)
{
	char *tab;

	tab = ft_strnew(0);
	while (s[i] == ' ')
		i++;
	if (s[i] == 'l')
		return (ft_stockll(s, ap, i + 1));
	if (s[i] == 'i' || s[i] == 'd' || s[i] == 'D' || s[i - 1] == 'D')
		tab = ft_itoabase(va_arg(ap, intmax_t), 10);
	else if (s[i] == 'X')
		tab = stup(ft_itohx(va_arg(ap, unsigned long)));
	else if (s[i] == 'x')
		tab = ft_itohx(va_arg(ap, unsigned long));
	else if (s[i] == 'p')
		tab = ft_itohx(va_arg(ap, unsigned long));
	else if (s[i] == 'C' || s[i] == 'c')
		tab = ft_bintoa(ft_itoabase(va_arg(ap, unsigned int), 2));
	else if (s[i] == 'u' || s[i] == 'U')
		tab = ft_itoalu(va_arg(ap, unsigned long));
	else if (s[i] == 'o' || s[i] == 'O')
		tab = ft_itoaoc(va_arg(ap, unsigned long));
	return (tab);
}

int		testdiff(char *s, int i)
{
	int res;

	res = 0;
	if (!(s[i] == 's' || s[i] == 'S' || s[i] == 'c' || s[i] == 'C'
	|| s[i] == 'i' || s[i] == 'd' || s[i] == 'D' || s[i] == 'u'
	|| s[i] == 'U' || s[i] == 'p' || s[i] == 'o' || s[i] == 'O'
	|| s[i] == 'x' || s[i] == 'X' || s[i] == 'l' || s[i] == 'h'
	|| s[i] == 'z' || s[i] == 'j' || s[i] == '%'))
		return (1);
	if (s[i] == 'S' || ((ft_testall(s, &i) == 2) && (s[i + 1] == 'S'
	|| s[i + 2] == 'S' || (s[i] == 'l' && s[i + 1] == 's'))))
		return (4);
	if (s[i] == 's' || s[i] == 'd' || s[i] == 'c' || s[i] == 'i'
	|| s[i] == 'u' || s[i] == 'p' || s[i] == 'o' || s[i] == 'x'
	|| s[i] == 'X' || s[i] == 'O' || s[i] == 'U' || s[i] == '%'
	|| s[i] == 'C')
		return (2);
	if (s[i] == 'D' || s[i] == 'l' || s[i] == 'h' || s[i] == 'j'
	|| s[i] == 'z')
	{
		res = (3 + ((s[i] == 'h') ? 2 : 0) + ((s[i] == 'j') ? 3 : 0)
		+ ((s[i] == 'z') ? 4 : 0));
		return (res);
	}
	return (0);
}

char	*ft_teststock(char *s, int i, va_list ap)
{
	if (testdiff(s, i) == 2)
		return (ft_stocksimp(s, ap, i));
	else if (testdiff(s, i) == 3)
		return (ft_stocklong(s, ap, i + 1));
	else if (testdiff(s, i) == 5)
		return (ft_stockh(s, ap, i + 1));
	else if (testdiff(s, i) == 6)
		return (ft_stockj(s, ap, i + 1));
	else if (testdiff(s, i) == 7)
		return (ft_stockz(s, ap, i + 1));
	else
		return (NULL);
}

char	**ft_stock(int *d, char *s, va_list ap)
{
	char	**tab;
	int		i[2];

	i[0] = -1;
	d[8] = 0;
	if (!(tab = malloc(sizeof(va_list) * 100)))
		return (NULL);
	while (s[++i[0]])
	{
		if (!(i[1] = 0) && s[i[0]] == '%')
		{
			tab[++d[8]] = ft_strnew(0);
			i[1] = i[0] + 1;
			if (!s[i[1]] && (d[9] = 1))
				return (NULL);
			while (ft_testpass(s, i[1], 1))
				i[1]++;
			if (testdiff(s, i[1]) == 4)
				tab[d[8]] = ft_stockss(ap, tab[d[8]]);
			else if ((tab[d[8]] = ft_teststock(s, i[1], ap)) == NULL)
				free(tab[d[8]--]);
			i[0] = i[1];
		}
	}
	return (tab);
}
