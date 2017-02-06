/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solvess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 23:17:33 by pbourlet          #+#    #+#             */
/*   Updated: 2017/02/07 00:00:36 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ssfinal(int *d, char **tab, int *t)
{
	while (d[1])
	{
		ft_solvecc(&d[0], tab[t[0]], 0);
		t[0]++;
		d[1]--;
	}
	return (1);
}

int		ft_lent(int spt, int a, char **tab)
{
	int lent;
	int lenb;

	lent = 0;
	lenb = 0;
	while (spt)
	{
		lenb = ft_strlen(tab[a]);
		lent += (lenb <= 21 ? 5 : 0) - (lenb <= 16 ? 1 : 0)
			- (lenb <= 11 ? 1 : 0) - (lenb <= '7' ? 1 : 0);
		spt--;
		a++;
	}
	return (lent);
}

int		ft_testdigitss(int *d, char *s, int *t, char **tab)
{
	int lent;

	lent = ft_lent(d[1], t[0], tab);
	while (ft_testflags1(t, d, s, NULL) > lent && d[5] != -1)
	{
		if (d[6] == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		t[6]--;
		d[0]++;
	}
	(!t[7] ? ft_ssfinal(d, tab, t) : 0);
	while (ft_testflags1(t, d, s, NULL) > lent && d[5] == -1)
	{
		ft_putchar(' ');
		t[6]--;
		d[0]++;
	}
	return (1);
}

int		ft_solvess(int *d, char **tab, int *t, char *s, t_int *l)
{
	if (l->bb <= l->ii)
	{
		d[1] = l->test[l->bb];
		if (ft_strcmp(tab[t[0]], "(null)") == 0)
			ft_solvefin(d, s, t, tab[t[0]]);
		else
			ft_testdigitss(d, s, t, tab);
		l->bb += 1;
	}
	return (1);
}
