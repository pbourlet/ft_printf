/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stockss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 23:01:12 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/31 23:01:23 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**ft_stockss(int *spt, va_list ap, char **tab, int *a)
{
	wchar_t	*tmp;
	int		y;

	y = 0;
	tmp = ft_wstrdup(va_arg(ap, wchar_t *));
	while (tmp[y] != '\0')
	{
		tab[*a] = ft_strdup(ft_itoabase((unsigned)tmp[y], 2));
		*a = *a + 1;
		y++;
		*spt = *spt + 1;
	}
	*a = *a - 1;
	free(tmp);
	return (tab);
}
