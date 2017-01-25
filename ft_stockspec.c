/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stockspec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:48:00 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/25 02:06:32 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_stockh(char *s, va_list ap, int i)
{
	char *tab;

	i++;
	if ((tab = ft_strnew(0)) && s[i] == 'h')
		return (ft_stockhh(s, ap, i));
	if (s[i] == 'i' || s[i] == 'd')
		tab = ft_strdup(ft_itoa((short)va_arg(ap, int)));
	else if (s[i] == 's' || s[i] == 'c' || s[i] == 'C' || s[i] == 'p')
		ft_stocksimp(s, ap, i);
	else if (s[i] == 'X')
		tab = ft_strdup(stup(ft_itosh(va_arg(ap, unsigned), 16)));
	else if (s[i] == 'x')
		tab = ft_strdup(ft_itosh(va_arg(ap, unsigned), 16));
	else if (s[i] == 'u' || s[i] == 'U')
		tab = ft_strdup(ft_itosh(va_arg(ap, unsigned), 10));
	else if (s[i] == 'o' || s[i] == 'O')
		tab = ft_strdup(ft_itosh(va_arg(ap, unsigned), 8));
	return (tab);
}

char	*ft_stockhh(char *s, va_list ap, int i)
{
	char *tab;

	i++;
	if ((tab = ft_strnew(0)) && (s[i] == 'i' || s[i] == 'd'))
		tab = ft_strdup(ft_itoabase((char)va_arg(ap, int), 10));
	else if (s[i] == 's' || s[i] == 'c' || s[i] == 'C' || s[i] == 'p')
		tab = ft_stocksimp(s, ap, i);
	else if (s[i] == 'x')
		tab = ft_strdup(ft_itosh((unsigned char) va_arg(ap, int), 16));
	else if (s[i] == 'X')
		tab = ft_strdup(stup(ft_itosh((unsigned char) va_arg(ap, int), 16)));
	else if (s[i] == 'u')
		tab = ft_strdup(ft_itoabase((unsigned char) va_arg(ap, int), 10));
	else if (s[i] == 'U')
		tab = ft_strdup(ft_itoabase(va_arg(ap, uintmax_t), 10));
	else if (s[i] == 'o' || s[i] == 'O')
		tab = ft_strdup(ft_itosh((unsigned char) va_arg(ap, int), 8));
	return (tab);
}

char	*ft_stockj(char *s, va_list ap, int i)
{
	char *tab;

	i++;
	if ((tab = ft_strnew(0)) && (s[i] == 'i' || s[i] == 'd'))
		tab = ft_strdup(ft_itoabase(va_arg(ap, intmax_t), 10));
	else if (s[i] == 's' || s[i] == 'c' || s[i] == 'C')
		tab = ft_stocksimp(s, ap, i);
	else if (s[i] == 'X')
		tab = ft_strdup(stup(ft_itohx(va_arg(ap, uintmax_t))));
	else if (s[i] == 'x')
		tab = ft_strdup(ft_itohx(va_arg(ap, uintmax_t)));
	else if (s[i] == 'p')
		tab = ft_strjoin("0x", ft_itohx(va_arg(ap, uintmax_t)));
	else if (s[i] == 'u' || s[i] == 'U')
		tab = ft_strdup(ft_itoalu(va_arg(ap, uintmax_t)));
	else if (s[i] == 'o' || s[i] == 'O')
		tab = ft_strdup(ft_itoabase(va_arg(ap, uintmax_t), 8));
	return (tab);
}

char	*ft_stockz(char *s, va_list ap, int i)
{
	char *tab;

	i++;
	if ((tab = ft_strnew(0)) && (s[i] == 'i' || s[i] == 'd'))
		tab = ft_strdup(ft_itoabase(va_arg(ap, ssize_t), 10));
	else if (s[i] == 's' || s[i] == 'c' || s[i] == 'C')
		tab = ft_stocksimp(s, ap, i);
	else if (s[i] == 'X')
		tab = ft_strdup(stup(ft_itohx(va_arg(ap, size_t))));
	else if (s[i] == 'x')
		tab = ft_strdup(ft_itohx(va_arg(ap, size_t)));
	else if (s[i] == 'p')
		tab = ft_strjoin("0x", ft_itohx(va_arg(ap, size_t)));
	else if (s[i] == 'u' || s[i] == 'U')
		tab = ft_strdup(ft_itoalu(va_arg(ap, size_t)));
	else if (s[i] == 'o' || s[i] == 'O')
		tab = ft_strdup(ft_itoabase(va_arg(ap, size_t), 8));
	return (tab);
}

char    *ft_stockll(char *s, va_list ap, int i)
{
	char *tab;

	i++;
	if ((tab = ft_strnew(0)) && (s[i] == 'i' || s[i] == 'd' || s[i] == 'D'))
		tab = ft_strdup(ft_itoabase(va_arg(ap, long long), 10));
	else if (s[i] == 's' || s[i] == 'c' || s[i] == 'C')
		tab = ft_stocksimp(s, ap, i);
	else if (s[i] == 'p')
		tab = ft_strjoin("0x", ft_itohx(va_arg(ap, long long)));
	else if (s[i] == 'X')
		tab = ft_strdup(stup(ft_itohx(va_arg(ap, unsigned long long))));
	else if (s[i] == 'x')
		tab = ft_strdup(ft_itohx(va_arg(ap, unsigned long long)));
	else if (s[i] == 'u' || s[i] == 'U')
		tab = ft_strdup(ft_itoalu(va_arg(ap, unsigned long long)));
	else if (s[i] == 'o' || s[i] == 'O')
		tab = ft_strdup(ft_itoaoc(va_arg(ap, unsigned long long)));
	return (tab);
}
