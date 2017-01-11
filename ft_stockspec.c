/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stockspec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:48:00 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/11 20:10:15 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**ft_stockh(char **tab, char *s, va_list ap, int i, int *a)
{
	i++;
	if (s[i] == 'i' || s[i] == 'd')
		tab[*a] = ft_strdup(ft_itoa((short)va_arg(ap, int)));
	else if (s[i] == 'c')
		tab[*a] = ft_strcjoin(tab[*a], (short)va_arg(ap, int));
	else if (s[i] == 'X')
		tab[*a] = ft_strdup(stup(ft_itosh(va_arg(ap, unsigned), 16)));
	else if (s[i] == 'x' || s[i] == 'p')
		tab[*a] = ft_strdup(ft_itosh(va_arg(ap, unsigned), 16));
	else if (s[i] == 'u' || s[i] == 'U')
		tab[*a] = ft_strdup(ft_itosh(va_arg(ap, unsigned), 10));
	else if (s[i] == 'o' || s[i] == 'O')
		tab[*a] = ft_strdup(ft_itosh(va_arg(ap, unsigned), 8));
	return (tab);
}
