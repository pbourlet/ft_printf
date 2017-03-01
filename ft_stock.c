/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:47:54 by pbourlet          #+#    #+#             */
/*   Updated: 2017/02/28 22:04:14 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_stocksimp(char *s, va_list ap, int i)
{
	char *tab;

	tab = NULL;
	if (s[i] == 's')
		tab = ft_stocksimps(tab, ap);
	else if (s[i] == '%')
		tab = ft_strdup("%");
	else if (s[i] == 'd' || s[i] == 'i' || s[i] == '*')
		tab = ft_itoa(va_arg(ap, int));
	else if (s[i] == 'c' && (tab = ft_strnew(0)))
		tab = ft_strcjoin(tab, va_arg(ap, int));
	else if (s[i] == 'C')
		tab = ft_bintoa(ft_itoabase(va_arg(ap, unsigned int), 2));
	else if (s[i] == 'u')
		tab = ft_itoalu(va_arg(ap, unsigned));
	else if (s[i] == 'U' || s[i] == 'p' || s[i] == 'O' || s[i] == 'D')
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

	tab = NULL;
	while (ft_testpass(s, i))
		i += 1;
	if (s[i] == '%')
		tab = ft_strdup("%");
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

int		ft_stockall(char *s, int *i)
{
	int lm;

	lm = 0;
	while (s[*i] && ft_testall(s, i) != 1 && s[*i] != '%')
	{
		if (s[*i] == 'l')
		{
			(lm != 1 && lm != 2 ? lm = 0 : 0);
			lm = (lm == 0 ? 1 : 0) + (s[*i + 1] == 'l' ? 1 : lm);
		}
		else if (s[*i] == 'h' && lm != 1 && lm != 2)
			lm = (lm == 0 ? 3 : 0) + (s[*i + 1] == 'h' ? 1 : lm);
		else if (s[*i] == 'j' && lm != 1 && lm != 2)
			lm = 5;
		else if (s[*i] == 'z' && lm != 1 && lm != 2)
			lm = 6;
		*i = *i + 1;
	}
	return (lm);
}

char	*ft_teststock(char *s, int i, va_list ap)
{
	int res;
	int ii;

	ii = i;
	res = ft_stockall(s, &i);
	if ((ft_testall(s, &ii) == 1 || s[ii] == '%' || s[ii] == '*') && !res)
		return (ft_stocksimp(s, ap, ii));
	else if (res == 1)
		return (ft_stocklong(s, ap, i));
	else if (res == 2)
		return (ft_stockll(s, ap, i));
	else if (res == 3)
		return (ft_stockh(s, ap, i));
	else if (res == 4)
		return (ft_stockhh(s, ap, i));
	else if (res == 5)
		return (ft_stockj(s, ap, i));
	else if (res == 6)
		return (ft_stockz(s, ap, i));
	else
		return (NULL);
}

char	**ft_stock(char *s, va_list ap)
{
	char	**tab;
	int		i[3];

	i[0] = -1;
	i[2] = 0;
	if (!(tab = malloc(sizeof(va_list) * 100)))
		return (NULL);
	while (s[++i[0]])
	{
		if (!(i[1] = 0) && s[i[0]] == '%')
		{
			i[2]++;
			i[1] = i[0] + 1;
			while (ft_testpass(s, i[1]))
				i[1]++;
			if (s[i[1]] == 'S' || ((ft_testall(s, &i[1]) == 2)
			&& (s[i[1] + 1] == 'S' || s[i[1] + 2] == 'S' || (s[i[1]] == 'l'
			&& s[i[1] + 1] == 's'))))
				tab[i[2]] = ft_stockss(ap, tab[i[2]]);
			else
				tab = ft_stocking(s, i, ap, tab);
			i[0] = i[1];
		}
	}
	return (tab);
}
