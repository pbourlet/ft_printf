/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:12:10 by pbourlet          #+#    #+#             */
/*   Updated: 2017/02/28 22:14:03 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	**ft_stocking(char *s, int *i, va_list ap, char **tab)
{
	int y;
	int	z;

	y = i[1];
	while (!ft_testall(s, &y) && s[y] != '%' && s[y])
	{
		if (s[y] == '*')
		{
			tab[i[2]++] = ft_teststock(s, y, ap);
			y++;
			i[1] = y;
		}
		y++;
	}
	z = y - 1;
	(ft_testall(s, &y) || (s[y] == '%' && ft_testall(s, &z))
	? i[1] = y : 0);
	if ((tab[i[2]] = ft_teststock(s, i[1], ap)) == NULL)
		free(tab[i[2]--]);
	return (tab);
}
