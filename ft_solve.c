/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:42:20 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/26 21:58:45 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_testdigit(int *d, char *s, int *t, char *tab)
{
	int	lent;

	lent = ft_strlen(tab) + (d[3] && d[2] && tab[0] != '-' ? 0 : d[3]);
//	ft_putstr("lent:");
//	ft_putnbr(lent);
//	ft_putchar('\n');
/*	ft_putstr("d[2]:");
	ft_putnbr(d[2]);
	ft_putstr("d[3]:");
	ft_putnbr(d[3]);
	ft_putstr("d[4]:");
	ft_putnbr(d[4]);
	ft_putstr("d[5]:");
	ft_putnbr(d[5]);
	ft_putstr("d[6]:");
	ft_putnbr(d[6]);
	ft_putstr("t[6]:");
	ft_putnbr(t[6]);
*/	if (d[6] == 1 && d[5] != - 1)
	{
		(tab[0] == '-' ? (lent++ && d[0]++) : 0);
		(tab[0] == '-' ? d[2] = 2 : 0);
		ft_testflags(t, d, s, tab, 2);
		((tab[0] == '+' || tab[0] == '-') ? (tab[0] = '0') : 0);
	}
	while (ft_testflags(t, d, s, tab, 1) > lent && d[5] != -1)
	{
		if (d[6] == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		t[6]--;
		d[0]++;
	}
	if (d[6] != 1 || (d[6] == 1 && d[5] == -1))
		ft_testflags(t, d, s, tab, 2);
	ft_putstr(tab);
	while (ft_testflags(t,d, s, tab, 1) > lent && d[5] == -1)
	{
		ft_putchar(' ');
		t[6]--;
		d[0]++;
	}
	d[0] += ft_strlen(tab) + ft_testflags(t, d, s, tab, 3);
	return (1);
}

int	ft_solvefin(int *d, char *s, int *t, char *tab)
{
	if (d[3] == 1 && d[2] != 1 && (s[t[1]] == 'i' || s[t[1]] == 'd'
	|| s[t[1]] == 'D' || s[t[1]] == 'p') && tab[0] != '-')
	{
		ft_putchar(' ');
		d[0]++;
	}
	ft_testdigit(d, s, t, tab);
	while (s[t[4]] == ' ' || ft_testall(s, &t[4]) != 1)
		t[4]++;
	ft_strclr(tab);
	free(tab);
	return (1);
}

int		ft_writeend(char *s, int *t, int *cpt)
{
	while (s[t[4]] && s[t[4]] != '%')
	{
		ft_putchar(s[t[4]]);
		*cpt = *cpt + 1;
		t[4]++;
	}
	t[4]--;
	return (1);
}

int		ft_testfin(char *s, int *t, int *cpt)
{
	if (t[2] == -1 && (s[t[4]] == '\t' || s[t[4]] == '\r' || s[t[4]] == '\v'
	|| s[t[4]] == '\a' || s[t[4]] == '\f' || s[t[4]] == '\b'))
		ft_writeend(s, t, cpt);
	else if (t[2] == 0)
	{
		while (s[t[4]] == '%' || s[t[4]] == ' ' || s[t[4]] == 'l'
		|| s[t[4]] == 'h' || s[t[4]] == 'j' || s[t[4]] == 'z')
				t[4]++;
		ft_writeend(s, t, cpt);
		t[4]++;
	}
	else if (s[t[4]] != '%')
	{
		ft_putchar(s[t[4]]);
		*cpt = *cpt + 1;
	}
	return (1);
}

int	ft_solve(int *d, char *s, char **tab)
{
	int	t[7];

	t[0] = 1;
	t[3] = 1;
	t[1] = 0;
	t[2] = -1;
	t[4] = 0;
	while (s[t[4]])
	{
		if (s[t[4]] == '%' && s[t[4] + 1])
		{
			t[1] = t[4];
			ft_flagstock(d, s, t[4] + 1);
			t[2] = ft_testsimp(s, &t[1], t);
			if (t[2] == 1)
				t[3] = ft_solvefin(d, s, t, tab[t[0]++]);
			else if (t[2] == 2)
				t[3] = ft_Cfinal(&d[0], tab[t[0]++], t, s);
			else if (t[2] == 3)
				ft_solveS(&d[1], &d[0], tab, t, s);
		}
		else if (ft_testfin(s, t, &d[0]) == -1)
			return (1);
		t[4]++;
	}
	return (1);
}
