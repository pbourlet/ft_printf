/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:47:54 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/18 20:26:32 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_stocksimp(char *s, va_list ap, int i)
{
	char *tab;

	if ((tab = ft_strnew(0)) && s[i] == 's')
		tab = ft_strdup(va_arg(ap, char *));
	else if (s[i] == 'd' || s[i] == 'i')
		tab = ft_strdup(ft_itoa(va_arg(ap, int)));
	else if (s[i] == 'c')
		tab = ft_strcjoin(tab, va_arg(ap, int));
	else if (s[i] == 'C')
		tab = ft_strdup(ft_itoabase(va_arg(ap, unsigned int), 2));
	else if (s[i] == 'u')
		tab = ft_strdup(ft_itoalu(va_arg(ap, unsigned)));
	else if (s[i] == 'U')
		tab = ft_strdup(ft_itoalu(va_arg(ap, unsigned long)));
	else if (s[i] == 'p')
		tab = ft_strdup(ft_itohx(va_arg(ap, unsigned long)));
	else if (s[i] == 'x')
		tab = ft_strdup(ft_itohx(va_arg(ap, unsigned)));
	else if (s[i] == 'o')
		tab = ft_strdup(ft_itoaoc(va_arg(ap, unsigned)));
	else if (s[i] == 'O')
		tab = ft_strdup(ft_itoaoc(va_arg(ap, unsigned long)));
	else if (s[i] == 'X')
		tab = ft_strdup(stup(ft_itohx(va_arg(ap, unsigned))));
	return (tab);
}

char	*ft_stocklong(char *s, va_list ap, int i)
{
	char *tab;

	i++;
	if ((tab = ft_strnew(0)) && s[i] == 'l')
		return (ft_stockll(s, ap, i));
	if (s[i] == 'i' || s[i] == 'd' || s[i] == 'D' || s[i - 1] == 'D')
		tab = ft_strdup(ft_itoalong(va_arg(ap, long)));
	else if (s[i] == 'X')
		tab = ft_strdup(stup(ft_itohx(va_arg(ap, unsigned long))));
	else if (s[i] == 'x')
		tab = ft_strdup(ft_itohx(va_arg(ap, unsigned long)));
	else if (s[i] == 'p')
		tab = ft_strdup(ft_itohx(va_arg(ap, unsigned long)));
	else if (s[i] == 'C' || s[i] == 'c')
		tab = ft_strdup(ft_itoabase(va_arg(ap, unsigned int), 2));
	else if (s[i] == 'u' || s[i] == 'U')
		tab = ft_strdup(ft_itoalu(va_arg(ap, unsigned long)));
	else if (s[i] == 'o' || s[i] == 'O')
		tab = ft_strdup(ft_itoaoc(va_arg(ap, unsigned long)));
	return (tab);
}

int	testdiff(char *s, int i)
{
	if (!(s[i] == 's' || s[i] == 'd' || s[i] == 'c'	|| s[i] == 'l'
	|| s[i] == 'i' || s[i] == 'u' || s[i] == 'p' || s[i] == 'o'
	|| s[i] == 'x' || s[i] == 'X' || s[i] == 'D' || s[i] == 'O'
	|| s[i] == 'U' || s[i] == 'C' || s[i] == 'h' || s[i] == 'j'
	|| s[i] == 'z' || s[i] == 'S'))
		return (1);
	if ((ft_testall(s, &i) == 2) && (s[i + 1] == 'S' || s[i + 2] == 'S'))
		return (4);
	if (s[i] == 's' || s[i] == 'd' || s[i] == 'c' || s[i] == 'i'
	|| s[i] == 'u' || s[i] == 'p' || s[i] == 'o' || s[i] == 'x'
	|| s[i] == 'X' || s[i] == 'O' || s[i] == 'U'
	|| s[i] == 'C')
		return (2);
	if (s[i] == 'D' || s[i] == 'l' || s[i] == 'h' || s[i] == 'j'
	|| s[i] == 'z')
		return (3 + ((s[i] == 'h') ? 2 : 0) + ((s[i] == 'j') ? 3 : 0)
			+ ((s[i] == 'z') ? 4 : 0));
	return (0);
}

char	**ft_stock(int *spt, char *s, va_list ap)
{
	char	**tab;
	int		sspt;
	int		i;
	int		c;
	int		a;

	i = -1;
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
				tab[a] = ft_stocksimp(s, ap, i + c);
			else if (testdiff(s, (i + c)) == 3)
				tab[a] = ft_stocklong(s, ap, i + c);
			else if (testdiff(s, (i + c)) == 4)
			{
				sspt = a;
				tab = ft_stockS(ap, tab, &a);
				*spt = a - sspt;
			}
			else if (testdiff(s, (i + c)) == 5)
				tab[a] = ft_stockh(s, ap, i + c);
			else if (testdiff(s, (i + c)) == 6)
				tab[a] = ft_stockj(s, ap, i + c);
			else if (testdiff(s, (i + c)) == 7)
				tab[a] = ft_stockz(s, ap, i + c);
		}
	}
	return (tab);
}
