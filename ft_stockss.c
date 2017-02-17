/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stockss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 23:01:12 by pbourlet          #+#    #+#             */
/*   Updated: 2017/02/17 01:20:14 by pbourlet         ###   ########.fr       */
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

void	ft_freestrclr(char *tmp)
{
	ft_strclr(tmp);
	free(tmp);
}

void	ft_putnsstr(char *tab, int *t, int *d)
{
	char	*tmp;
	int		i;
	int		len;

	i = 0;
	len = 0;
	tmp = NULL;
	tmp = ft_itoabase((unsigned char)tab[i++], 2);
	while (i <= t[5] && tab[i])
	{
		ft_freestrclr(tmp);
		tmp = (ft_itoabase((unsigned char)tab[i], 2));
		if (tmp[0] == '1' && tmp[1] == '1')
			len = i;
		i++;
	}
	ft_freestrclr(tmp);
	i = 0;
	while (i < len && tab[i] && (d[0]++))
		ft_putchar(tab[i++]);
}
