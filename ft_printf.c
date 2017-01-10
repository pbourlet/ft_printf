/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:42:27 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/10 19:19:41 by pbourlet         ###   ########.fr       */
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
		return (0);
	ft_solve(&cpt, s, i, stock);
	free(stock);
	free(s);
	va_end(ap);
	return (cpt);
}
