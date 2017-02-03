/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 21:56:34 by pbourlet          #+#    #+#             */
/*   Updated: 2017/02/03 15:01:23 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prec(int *d, char *s, int *t, char *tab)
{
	if (d[6] != 1 || (d[6] == 1 && d[5] == -1) || (t[5] && d[2] == 2))
		ft_testflags2(t, d, s, tab);
	while ((d[2] == 2 ? t[5] - 1 : t[5]) > t[9] && t[5] && t[2] != 2)
	{
		ft_putchar('0');
		t[5]--;
		d[0]++;
	}
	(t[2] == 2 ? ft_ccfinal(&d[0], tab, t, s) : ft_putstr(tab));
	while (ft_testflags1(t, d, s, tab) > t[8] && d[5] == -1)
	{
		ft_putchar(' ');
		t[6]--;
		d[0]++;
	}
}

int		ft_sols(int *t, int *d, char *tab, int lenb)
{
	ft_putnstr(tab, t[5]);
	d[0] += (t[5] >= lenb ? lenb : t[5]);
	return (1);
}

void	ft_champ(int *d, char *s, int *t, char *tab)
{
	if ((d[6] == 1 && d[5] != -1) || t[5] >= t[9])
	{
		(tab[0] == '-' ? (t[8]++ && d[0]++) : 0);
		(tab[0] == '-' ? d[2] = 2 : 0);
		(t[7] ? 0 : ft_testflags2(t, d, s, tab));
		if (t[7])
			((tab[0] == '+' || tab[0] == '-') && t[5] > t[9]
			? (tab[0] = '0') : 0);
		else
			((tab[0] == '+' || tab[0] == '-') ? (tab[0] = '0') : 0);
	}
	while (ft_testflags1(t, d, s, tab) > t[8] && d[5] != -1)
	{
		if (d[6] == 1 && t[7] == 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
		t[6]--;
		d[0]++;
	}
}

int		ft_testdigit(int *d, char *s, int *t, char *tab)
{
	t[9] = ft_strlen(tab) - (d[6] && tab[0] == '-' ? 1 : 0);
	if (t[7] && s[t[1]] == 's')
		return (ft_sols(t, d, tab, t[9]));
	if (t[2] == 2)
	{
		t[8] = (t[9] <= 21 ? 5 : 0) - (t[9] <= 16 ? 1 : 0)
		- (t[9] <= 11 ? 1 : 0) - (t[9] <= '7' ? 1 : 0);
	}
	else
		t[8] = t[9] + (d[3] && d[2] && tab[0] != '-' ? 0 : d[3])
		+ (t[5] > t[9] ? t[5] - t[9] : 0)
		- (t[5] > t[9] && tab[0] == '-' ? 1 : 0);
	ft_champ(d, s, t, tab);
	ft_prec(d, s, t, tab);
	if (t[2] != 2)
		d[0] += t[9] + ft_testflags3(t, d, s, tab);
	return (1);
}
