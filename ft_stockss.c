/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stockss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 23:01:12 by pbourlet          #+#    #+#             */
/*   Updated: 2017/02/09 18:44:21 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_stockss(va_list ap, char *tab)
{
	wchar_t	*tmp;
	wchar_t	*tmp2;
	char	*tmp3;
	int		y;

	y = 0;
	tmp = NULL;
	tmp3 = NULL;
	tmp2 = va_arg(ap, wchar_t *);
	if (tmp2 == NULL)
	{
		tab = ft_strdup("(null)");
		return (tab);
	}
	tmp = ft_wstrdup(tmp2);
	while (tmp[y] != '\0')
	{
		tmp3 = ft_itoabase((unsigned)tmp[y], 2);
		y++;
		tab = ft_strjoin(tab, ft_bintoa(tmp3));
	}
	free(tmp);
	free(tmp3);
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
