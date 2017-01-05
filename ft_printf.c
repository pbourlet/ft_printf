/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:26:22 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/05 20:00:37 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

char	*ft_solvelong(char *str, int *i, char *tab)
{
	*i = *i + 1;
	return ((str = ft_strjoin(str, tab)));
}

char	*ft_solvesimple(char *str, char *s, int *i, char *tab)
{
	if (s[*i] ==  'p')
	{
		str = ft_strjoin(str, "0x");
		str = ft_strjoin(str, tab);
	}
	else if (s[*i] == 'c' || (s[*i] == 'l' && s[*i + 1] == 'c'))
		str = ft_strcjoin(str, tab[0]);
	else
		str = ft_strjoin(str, tab);
	return (str);
}

int	testtype(char *s, int *i)
{
	if (s[*i - 1] == '%' && (s[*i] == 's' || s[*i] == 'd' || s[*i] == 'c'
	|| s[*i] == 'i' || s[*i] == 'u' || s[*i] == 'p' || s[*i] == 'o'
	|| s[*i] == 'x' || s[*i] == 'X'))
		return (1);
	if (s[*i - 1] == '%' && s[*i] == 'l' && (s[*i + 1] == 'c'
	|| s[*i + 1] == 'p'))
	{
		*i = *i + 1;
		return (1);
	}
	if (s[*i - 1] == '%' && s[*i] == 'l' && (s[*i + 1] == 's' ||
	s[*i + 1] == 'd' || s[*i + 1] == 'i' ||
	s[*i + 1] == 'u' || s[*i + 1] == 'p' || s[*i + 1] == 'o' ||
	s[*i + 1] == 'x' || s[*i + 1] == 'X'))
		return (2);
	return (0);
}

char	*ft_solve(char *str, char *s, int i, char **tab)
{
	int	a;

	a = 1;
	while (s[i])
	{
		if (testtype(s, &i) == 1)
			str = ft_solvesimple(str, s, &i, tab[a++]);
		else if (testtype(s, &i) == 2)
			str = ft_solvelong(str, &i, tab[a++]);
//		else if (s[i - 1] == '%' && s[i + 1] == '$')
//			str = ft_ndisp(str, s, ap, &i, tab);
		else if (s[i] != '%')
		{
			if (s[i - 1] == '%' && s[i] == 'l')
			{
				s[i] = '%';
				a++;
			}
			str = ft_strcjoin(str, s[i]);
		}
		i++;
	}
	return (str);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*s;
	char		**stock;
	char		*str;
	int			i;

	i = 0;
	va_start(ap, format);
	s = ft_strdup(format);
	str = ft_strnew(0);
	if ((stock = ft_stock(s, ap)) == NULL)
		return (0);
	str = ft_solve(str, s, i, stock);
	ft_putstr(str);
	free(stock);
	free(s);
	va_end(ap);
	return (1);
}
