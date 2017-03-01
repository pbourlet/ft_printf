/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:42:27 by pbourlet          #+#    #+#             */
/*   Updated: 2017/02/28 21:46:37 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*s;
	char		**stock;
	int			d[8];

	d[0] = 0;
	d[4] = 0;
	d[1] = 0;
	va_start(ap, format);
	s = ft_strdup(format);
	if ((stock = ft_stock(s, ap)) == NULL)
		return (-1);
	ft_solve(d, s, stock);
	ft_strclr(s);
	free(s);
	free(stock);
	s = NULL;
	stock = NULL;
	va_end(ap);
	return (d[0]);
}
