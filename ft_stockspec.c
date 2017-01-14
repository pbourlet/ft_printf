/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stockspec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:48:00 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/14 16:21:02 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**ft_stockh(char **tab, char *s, va_list ap, int i, int *a)
{
	i++;
	if (s[i] == 'i' || s[i] == 'd')
		tab[*a] = ft_strdup(ft_itoa((short)va_arg(ap, int)));
	else if (s[i] == 's')
		tab[*a] = ft_strdup(va_arg(ap, char *));
	else if (s[i] == 'c')
		tab[*a] = ft_strcjoin(tab[*a], va_arg(ap, int));
	else if (s[i] == 'C')
		tab[*a] = ft_strdup(ft_itoabase(va_arg(ap, unsigned int), 2));
	else if (s[i] == 'X')
		tab[*a] = ft_strdup(stup(ft_itosh(va_arg(ap, unsigned), 16)));
	else if (s[i] == 'x')
		tab[*a] = ft_strdup(ft_itosh(va_arg(ap, unsigned), 16));
	else if (s[i] == 'p')
		tab[*a] = ft_strdup(ft_itohx(va_arg(ap, unsigned long)));
	else if (s[i] == 'u' || s[i] == 'U')
		tab[*a] = ft_strdup(ft_itosh(va_arg(ap, unsigned), 10));
	else if (s[i] == 'o' || s[i] == 'O')
		tab[*a] = ft_strdup(ft_itosh(va_arg(ap, unsigned), 8));
	return (tab);
}

char	**ft_stockj(char **tab, char *s, va_list ap, int i, int *a)
{
	i++;
	if (s[i] == 'i' || s[i] == 'd')
		tab[*a] = ft_strdup(ft_itoabase(va_arg(ap, intmax_t), 10));
	else if (s[i] == 's')
		tab[*a] = ft_strdup(va_arg(ap, char *));
	else if (s[i] == 'c' || s[i] == 'C')
		tab[*a] = ft_strdup(ft_itoabase(va_arg(ap, unsigned int), 2));
	else if (s[i] == 'X')
		tab[*a] = ft_strdup(stup(ft_itohx(va_arg(ap, uintmax_t))));
	else if (s[i] == 'x')
		tab[*a] = ft_strdup(ft_itohx(va_arg(ap, uintmax_t)));
	else if (s[i] == 'p')
		tab[*a] = ft_strdup(ft_itohx(va_arg(ap, uintmax_t)));
	else if (s[i] == 'u' || s[i] == 'U')
		tab[*a] = ft_strdup(ft_itoalu(va_arg(ap, uintmax_t)));
	else if (s[i] == 'o' || s[i] == 'O')
		tab[*a] = ft_strdup(ft_itoabase(va_arg(ap, uintmax_t), 8));
	return (tab);
}

char	**ft_stockz(char **tab, char *s, va_list ap, int i, int *a)
{
	i++;
	if (s[i] == 'i' || s[i] == 'd')
		tab[*a] = ft_strdup(ft_itoabase(va_arg(ap, ssize_t), 10));
	else if (s[i] == 's')
		tab[*a] = ft_strdup(va_arg(ap, char *));
	else if (s[i] == 'c' || s[i] == 'C')
		tab[*a] = ft_strdup(ft_itoabase(va_arg(ap, unsigned int), 2));
	else if (s[i] == 'X')
		tab[*a] = ft_strdup(stup(ft_itohx(va_arg(ap, size_t))));
	else if (s[i] == 'x')
		tab[*a] = ft_strdup(ft_itohx(va_arg(ap, size_t)));
	else if (s[i] == 'p')
		tab[*a] = ft_strdup(ft_itohx(va_arg(ap, size_t)));
	else if (s[i] == 'u' || s[i] == 'U')
		tab[*a] = ft_strdup(ft_itoalu(va_arg(ap, size_t)));
	else if (s[i] == 'o' || s[i] == 'O')
		tab[*a] = ft_strdup(ft_itoabase(va_arg(ap, size_t), 8));
	return (tab);
}
