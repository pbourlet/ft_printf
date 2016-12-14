/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:26:22 by pbourlet          #+#    #+#             */
/*   Updated: 2016/12/14 13:40:33 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

char	*ft_solvelong(char *tmp, int *i, char *tab)
{
	*i = *i + 1;
	return ((tmp = ft_strjoin(tmp, tab)));
}

char	*ft_solvesimple(char *str, char *s, int *i, char *tab)
{
	if (s[*i] != 'c')
		str = ft_strjoin(str, tab);
	else if (s[*i] == 'c')
		str = ft_strcjoin(str, tab[0]);
	return (str);
}

char	*ft_solve(char *str, char *s, va_list ap, int i, char **tab)
{
	int	a;

	a = 1;
	while (s[i])
	{
		if (s[i - 1] == '%' && (s[i] == 's' || s[i] == 'd' || s[i] == 'c'
		|| s[i] == 'i' || s[i] == 'u' || s[i] == 'p' || s[i] == 'o'))
			str = ft_solvesimple(str, s, &i, tab[a++]);
		else if (s[i - 1] == '%' && s[i] == 'l')
			str = ft_solvelong(str, &i, tab[a++]);
		//		else if (s[i - 1] == '%' && s[i + 1] == '$')
		//			str = ft_ndisp(str, s, ap, &i, tab);
		else if (s[i] != '%')
			str = ft_strcjoin(str, s[i]);
		i++;
	}
	return (str);
}

int		ft_printf(const char * restrict format, ...)
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
	str = ft_solve(str, s, ap, i, stock);
	ft_putstr(str);
	free(stock);
	free(s);
	va_end(ap);
	return (1);
}

int		main(void)
{
	long int li = -42;
	char *p;
	p = malloc(100);
	int lu = -42;
	ft_printf("lol %o \n", 'c');
	printf("lol %o \n", 'c');
//	ft_printf("lol %c %i %d %ld %lu %p\n", 'a', "salut", 19, li, lu, p);
//	printf("lol %c %i %d %ld %lu %p\n", 'a', "salut", 19, li, lu, p);
	return (0);
}
