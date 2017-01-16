/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:42:27 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/16 20:21:32 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*s;
	char		**stock;
	int		cpt;
	int			i;

	i = 0;
	cpt = 0;
	va_start(ap, format);
	s = ft_strdup(format);
	if ((stock = ft_stock(s, ap)) == NULL)
		return (-1);
//	ft_putstr("stock[1]:");
//	ft_putendl(stock[1]);
//	ft_putstr("stock[2]:");
//	ft_putendl(stock[2]);
	ft_solve(&cpt, s, i, stock);
	free(stock);
	free(s);
	va_end(ap);
	return (cpt);
}
