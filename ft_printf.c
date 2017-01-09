/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:42:27 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/09 14:43:50 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
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
	return (ft_strlen(str));
}
