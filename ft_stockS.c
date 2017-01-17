/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stockS.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 23:50:34 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/17 04:21:45 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

char	**ft_stockS(char **tab, char *s, va_list ap, int i, int *a)
{
	int	y;
	char	*tmp;

	y = 0;
	if (s[i] == 'S' || (s[i] == 'l' && s[i + 1] == 's'))
	{
	tmp = ft_strdup(va_arg(ap, char *));
	while (tmp[y] != '\0')
	{
		tab[*a] = ft_strdup(ft_itoabase((unsigned)tmp[y], 2));
		*a = *a + 1;
		y++;
	}
	free(tmp);
	}
	return(tab);
}
