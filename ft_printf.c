/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:42:27 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/18 20:12:47 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*s;
	char		**stock;
	int		cpt;
	int		spt;
	int			i;

	i = 0;
	cpt = 0;
	spt = 0;
	va_start(ap, format);
	s = ft_strdup(format);
	if ((stock = ft_stock(&spt, s, ap)) == NULL)
		return (-1);
	ft_putstr("\nstock[1]:");
	ft_putendl(stock[1]);
	ft_putstr("stock[2]:");
	ft_putendl(stock[2]);
	ft_putstr("stock[3]:");
	ft_putendl(stock[3]);
	ft_solve(&spt, &cpt, s, i, stock);
	free(stock);
	free(s);
	va_end(ap);
	return (cpt);
}
