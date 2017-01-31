/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:42:20 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/31 23:30:37 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_solvefin(int *d, char *s, int *t, char *tab)
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
	if (t[2] == 1)
	{
		ft_strclr(tab);
		free(tab);
	}
	return (1);
}

void	ft_writeend(char *s, int *t, int *cpt)
{
	while (s[t[4]] && s[t[4]] != '%')
	{
		ft_putchar(s[t[4]]);
		*cpt = *cpt + 1;
		t[4]++;
	}
	t[4]--;
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

int		ft_solve(int *d, char *s, char **tab)
{
	int	t[10];

	t[0] = 1;
	t[3] = 1;
	t[1] = 0;
	t[2] = -1;
	t[4] = 0;
	t[5] = 0;
	while (s[t[4]])
	{
		if (s[t[4]] == '%' && s[t[4] + 1])
		{
			t[1] = t[4];
			ft_flagstock(d, s, t[4] + 1);
			t[2] = ft_testsimp(s, &t[1], t);
			if (t[2] == 1 || t[2] == 2)
				ft_solvefin(d, s, t, tab[t[0]++]);
			else if (t[2] == 3)
				t[3] = ft_solvess(d, tab, t, s);
		}
		else if (ft_testfin(s, t, &d[0]) == -1)
			return (1);
		t[4]++;
	}
	return (1);
}
