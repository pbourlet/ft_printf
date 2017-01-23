/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:42:20 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/23 21:01:18 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_solvefin(int *cpt, char *s, int *t, char *tab)
{
	int e;

	e = t[4] + 1;
	if (s[t[4] + 1] == ' ' && tab[0] != '-' && (s[t[1]] == 'i'
	|| s[t[1]] == 'd' || s[t[1]] == 'D'))
	{
		ft_putchar(' ');
		*cpt = *cpt + 1;
	}
	if (s[t[1]] == 'p')
		ft_putstr("0x");
	ft_putstr(tab);
	*cpt = *cpt + ft_strlen(tab) + (s[t[1]] == 'p' ? 2 : 0);
	while (s[t[4] + 1] == ' ')
		t[4]++;
	t[4] = t[4] + 1 + (s[t[1] - 1] == 'l' ? 1 : 0)
	+ (s[t[1] - 2] == 'l' ? 2 : 0) + (s[t[1] - 1] == 'h' ? 1 : 0)
	+ (s[t[1] - 2] == 'h' ? 1 : 0) + (s[t[1] - 1] == 'j' ? 1 : 0)
	+ (s[t[1] - 1] == 'z' ? 1 : 0)  + (s[e] == ' ' ? 1 : 0);
	ft_strclr(tab);
	free(tab);
	return (1);
}

int		ft_testfin(char *s, int *t, int *cpt, int *test)
{
	if (t[2] == -1 && (s[t[4]] == '\t' || s[t[4]] == '\r' || s[t[4]] == '\v'
	|| s[t[4]] == '\a' || s[t[4]] == '\f' || s[t[4]] == '\b'))
	{
		while (s[t[4]] && s[t[4]] != '%')
		{
			ft_putchar(s[t[4]]);
			*cpt = *cpt + 1;
			t[4]++;
		}
		t[4]--;
	}
	else if (t[2] == 0)
	{
		while (s[t[4]] == '%' || s[t[4]] == ' ' || s[t[4]] == 'l'
		|| s[t[4]] == 'h' || s[t[4]] == 'j' || s[t[4]] == 'z')
				t[4]++;
		while (s[t[4]] && s[t[4]] != '%')
		{
			ft_putchar(s[t[4]]);
			*cpt = *cpt + 1;
			t[4]++;
		}
	}
	else if (t[2] == -1 || ft_testall(s, &t[1]) == 1)
	{
		if (t[3] == 0)
			return (-1);
		if (ft_testfinal(test, s, t))
			return (1);
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
	int test;

	t[0] = 1;
	t[3] = 1;
	t[1] = 0;
	t[2] = -1;
	t[4] = 0;
	while (s[t[4]])
	{
		if (s[t[4]] == '%')
		{
			t[2] = ft_testsimp(s, &t[4], &t[1]);
			if ((test = 0) || t[2] == 1)
				t[3] = ft_solvefin(cpt, s, t, tab[t[0]++]);
			else if (t[2] == 2)
				t[3] = ft_Cfinal(cpt, tab[t[0]++], t, s);
			else if (t[2] == 3)
				ft_solveS(spt, cpt, tab, t, s);
		}
		if (ft_testfin(s, t, cpt, &test) == -1)
			return (1);
		t[4]++;
	}
	return (1);
}
