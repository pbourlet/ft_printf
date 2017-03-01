/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 21:56:34 by pbourlet          #+#    #+#             */
/*   Updated: 2017/02/28 20:15:55 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_sols(int *t, int *d, char *tab, char *s)
{
	if (t[7] && s[t[1]] == 's')
	{
		ft_putnstr(tab, t[5]);
		d[0] += (t[5] >= t[9] ? t[9] : t[5]);
	}
	else if (t[7] && s[t[1]] == 'S')
		ft_putnsstr(tab, t, d);
	else
		(s[t[1]] == 'c' || s[t[1]] == 'C') && tab[1] == '\0'
		? ft_putchar(*tab) : ft_putstr(tab);
	return (1);
}

void	ft_prec(int *d, char *s, int *t, char *tab)
{
	if ((d[4] && !t[6] && !t[7]) || d[6] != 1 || (d[6] == 1 && d[5] == -1)
	|| (t[5] && d[2] == 2))
		ft_testflags2(t, d, s, tab);
	else if (d[2] == 1 && *tab != '-' && (s[t[1]] == 'i'
	|| s[t[1]] == 'd' || s[t[1]] == 'D') && t[7] && (d[0]++))
		ft_putchar('+');
	while (t[7] && t[5] > t[9] + (d[4] && (s[t[1]] == 'o' || s[t[1]] == 'O')
	? 1 : 0) && s[t[1]] != 'S' && s[t[1]] != 's' && s[t[1]] != 'c'
	&& s[t[1]] != 'C')
	{
		ft_putchar('0');
		t[5]--;
		d[0]++;
	}
	ft_sols(t, d, tab, s);
	while (t[6] && ft_testflags1(t, d, s, tab) > t[8]
	- ((d[2] == 1 && *tab == '-') ? 1 : 0) && d[5] == -1)
	{
		ft_putchar(' ');
		t[6]--;
		d[0]++;
	}
}

void	ft_champ(int *d, char *s, int *t, char *tab)
{
	if ((d[6] == 1 && d[5] != -1) || t[5] >= t[9])
	{
		(tab[0] == '-' ? t[8]++ : 0);
		(tab[0] == '-' ? d[2] = 2 : 0);
		(t[7] ? 0 : ft_testflags2(t, d, s, tab));
		if (t[7])
			((tab[0] == '+' || tab[0] == '-') && t[5] >= t[9]
			? (tab[0] = '0') : 0);
		else if (t[6] != 0)
			((tab[0] == '+' || tab[0] == '-') ? (tab[0] = '0') : 0);
	}
	while (t[6] && ft_testflags1(t, d, s, tab) > t[8]
	- ((d[2] == 1 && *tab == '-') || (d[2] == 2 && !t[7]) ? 1 : 0)
	+ (d[2] == 2 && !t[7] && d[6] ? 1 : 0) && d[5] != -1)
	{
		if ((d[6] && !t[7]) || (d[6] && (s[t[1]] == 'c' || s[t[1]] == 'C'
		|| s[t[1]] == 's' || s[t[1]] == 'S' || !ft_testall(s, &t[1]))))
			ft_putchar('0');
		else
			ft_putchar(' ');
		t[6]--;
		d[0]++;
	}
}

int		ft_testdigit(int *d, char *s, int *t, char *tab)
{
	if ((s[t[1]] == '%' && t[7] ? t[5] = 1 : 1) && !(d[4] && t[7] && !t[5]
	&& *tab == '0' && (s[t[1]] == 'o' || s[t[1]] == 'O')))
		(t[7] && !t[5] && tab[0] == '0' ? tab[0] = '\0' : 0);
	t[9] = (s[t[1]] == 'c' && *tab == 0 ? 1 : ft_strlen(tab));
	(t[7] && t[5] <= t[9] && s[t[1]] == 'S' ? t[5] = ft_wlen(tab, t) : 0);
	(t[7] && t[5] <= t[9] && s[t[1]] == 'S' ? t[9] = t[5] : 0);
	if (t[7] && (s[t[1]] == 's' || s[t[1]] == 'c' || s[t[1]] == 'C'))
		t[8] = (tab[0] == '\0' ? 0 : t[5]) - (t[5] > t[9] && tab[0] != '\0'
		? t[5] - t[9] : 0);
	else if (tab[0] == 0 && (s[t[1]] == 'c' || s[t[1]] == 'C'))
		t[8] = 1;
	else
		t[8] = t[9] + (d[3] && d[2] && tab[0] != '-' ? 0 : d[3])
		- (t[7] && t[5] <= t[9] && *tab == '-' ? 1 : 0) + (t[5] > t[9] ?
		t[5] - t[9] : 0) - (s[t[1]] == 'i' || s[t[1]] == 'd' || s[t[1]] == 'D'
		? 0 : d[3]) - (t[5] > t[9] && tab[0] == '-' ? 1 : 0) - (d[6] && !t[6]
		&& *tab == '-' ? 1 : 0) - ((s[t[1]] == 'i' || s[t[1]] == 'd'
		|| s[t[1]] == 'D') && !t[7] && *tab == '-' ? 1 : 0);
	ft_champ(d, s, t, tab);
	ft_prec(d, s, t, tab);
	if (!(t[7] && (s[t[1]] == 's' || s[t[1]] == 'S')))
		d[0] += t[9];
	return (1);
}
