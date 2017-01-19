/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:42:20 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/19 21:10:34 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_solvefin(int *cpt, char *s, int *t, char *tab)
{
	int e;

	e = 0;
	if (s[t[4] + 1] == ' ' && ft_atoi(tab) > 0 && (s[t[1]] == 'i'
	|| s[t[1]] == 'd' || s[t[1]] == 'D') && (e = 1))
		ft_putchar(' ');
	if (s[t[1]] == 'p')
	{
		ft_putstr("0x");
		*cpt = *cpt + 2;
	}
	ft_putstr(tab);
	*cpt = *cpt + ft_strlen(tab) + (e == 1 ? 1 : 0);
	while (s[t[4] + 1] == ' ')
		t[4]++;
	t[4] = t[4] + 1 + (s[t[1] - 1] == 'l' ? 1 : 0)
	+ (s[t[1] - 2] == 'l' ? 1 : 0) + (s[t[1] - 1] == 'h' ? 1 : 0)
	+ (s[t[1] - 2] == 'h' ? 1 : 0) + (s[t[1] - 1] == 'j' ? 1 : 0)
	+ (s[t[1] - 1] == 'z' ? 1 : 0)  + (e == 1 ? 1 : 0);
	ft_strclr(tab);
	free(tab);
	return (1);
}

int		ft_testfin(char *s, int *t, int *cpt)
{
//	if (t[3] == 2)
//		return (1);
	if (t[2] == 0 || ft_testall(s, &t[1]) == 1)
	{
		if (t[3] == 0)
			return (-1);
		if ((s[t[1] - 1] == 'l' && ft_testall(s, &t[4])))
			return (1);
		if (!(s[t[4]] == '%' && ft_testall(s, &t[1])))
		{
			ft_putchar(s[t[4]]);
			*cpt = *cpt + 1;
			return (1);
		}
		if (s[t[4]] != '%')
		{
			ft_putchar(s[t[4]]);
			*cpt = *cpt + 1;
		}
	}
	return (1);
}

int	ft_solve(int *spt, int *cpt, char *s, char **tab)
{
	int	t[5];

	t[0] = 1;
	t[3] = 1;
	t[1] = 0;
	t[2] = 0;
	t[4] = 0;
	while (s[t[4]])
	{
		if (s[t[4]] == '%')
		{
			t[2] = ft_testsimp(s, &t[4], &t[1]);
			if (t[2] == 1)
				t[3] = ft_solvefin(cpt, s, t, tab[t[0]++]);
			else if (t[2] == 2)
				t[3] = ft_solveC(cpt, tab[t[0]++], t);
			else if (t[2] == 3)
				ft_solveS(spt, cpt, tab, t);
		}
		else if (ft_testfin(s, t, cpt) == -1)
			return (1);
		t[4]++;
	}
	return (1);
}
