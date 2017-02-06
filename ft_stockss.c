/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stockss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 23:01:12 by pbourlet          #+#    #+#             */
/*   Updated: 2017/02/06 23:52:16 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**ft_stockss(va_list ap, char **tab, int *d, t_int *l)
{
	wchar_t	*tmp;
	wchar_t	*tmp2;
	int		y;

	y = 0;
	tmp = NULL;
	l->test[l->ii] = 0;
	tmp2 = va_arg(ap, wchar_t *);
	if (tmp2 == NULL)
	{
		tab[d[8]] = ft_strdup("(null)");
		return (tab);
	}
	tmp = ft_wstrdup(tmp2);
	while (tmp[y] != '\0')
	{
		tab[d[8]] = ft_itoabase((unsigned)tmp[y], 2);
		d[8]++;
		y++;
		l->test[l->ii] += 1;
	}
	d[8]--;
	l->ii += 1;
	free(tmp);
	return (tab);
}

char	*ft_stocksimps(char *tab, va_list ap)
{
	char *tmp;

	tmp = va_arg(ap, char *);
	if (tmp != NULL)
		tab = ft_strdup(tmp);
	else
		tab = ft_strdup("(null)");
	return (tab);
}
