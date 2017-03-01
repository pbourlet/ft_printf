/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stockss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 23:01:12 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/01 01:24:42 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_stockss(va_list ap, char *tab)
{
	char	*tmp;
	wchar_t	*tmp2;
	char	*tmp3;
	int		y;
	int		i;

	y = 0;
	i = 0;
	tab = ft_strnew(0);
	tmp3 = ft_strnew(0);
	tmp2 = va_arg(ap, wchar_t *);
	if (tmp2 == NULL)
		return ((tab = ft_strdup("(null)")));
	while (tmp2[y] != '\0')
	{
		tmp3 = ft_itoabase((unsigned)tmp2[y], 2);
		y++;
		tmp = ft_bintoa(tmp3);
		while (*tmp)
			tab[i++] = *tmp++;
		ft_strclr(tmp3);
		free(tmp3);
	}
	tab[i] = '\0';
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

int		ft_wlen(char *tab, int *t)
{
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	len = 0;
	tmp = NULL;
	tmp = ft_itoabase((unsigned char)tab[i++], 2);
	{
		while (i <= t[5] && tab[i])
		{
			ft_strclr(tmp);
			free(tmp);
			tmp = ft_itoabase((unsigned char)tab[i], 2);
			if (tmp[0] == '1' && tmp[1] == '1')
				len = i;
			i++;
		}
	}
	ft_strclr(tmp);
	free(tmp);
	return (len);
}

void	ft_putnsstr(char *tab, int *t, int *d)
{
	int		i;
	int		len;

	i = 0;
	len = ft_wlen(tab, t);
	while (i < len && tab[i])
	{
		ft_putchar(tab[i++]);
		d[0]++;
	}
}
