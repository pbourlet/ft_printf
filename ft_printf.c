/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:42:27 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/26 22:01:30 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*s;
	char		**stock;
	int		d[7];

	d[0] = 0;
	d[1] = 0;
	d[4] = 0;
	va_start(ap, format);
	s = ft_strdup(format);
	if ((stock = ft_stock(d, s, ap)) == NULL)
		return (-1);
/*	ft_putstr("\nstock[1]:");
	ft_putendl(stock[1]);
	ft_putstr("stock[2]:");
	ft_putendl(stock[2]);
	ft_putstr("stock[3]:");
	ft_putendl(stock[3]);
	ft_putstr("stock[4]:");
	ft_putendl(stock[4]);
	ft_putstr("stock[5]:");
	ft_putendl(stock[5]);
	ft_putstr("stock[6]:");
	ft_putendl(stock[6]);
	ft_putstr("stock[7]:");
	ft_putendl(stock[7]);
	ft_putstr("stock[8]:");
	ft_putendl(stock[8]);
	ft_putstr("stock[9]:");
	ft_putendl(stock[9]);
	ft_putstr("stock[10]:");
	ft_putendl(stock[10]);
*/	ft_solve(d, s, stock);
	free(stock);
/*	ft_putstr("\nstock[1]':");
	ft_putendl(stock[1]);
	ft_putstr("stock[2]':");
	ft_putendl(stock[2]);
	ft_putstr("stock[3]':");
	ft_putendl(stock[3]);
	ft_putstr("stock[4]':");
	ft_putendl(stock[4]);
	ft_putstr("stock[5]':");
	ft_putendl(stock[5]);
	ft_putstr("stock[6]':");
	ft_putendl(stock[6]);
*/	free(s);
	va_end(ap);
	return (d[0]);
}
