/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:42:20 by pbourlet          #+#    #+#             */
/*   Updated: 2017/02/03 16:25:18 by pbourlet         ###   ########.fr       */
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
	if (t[2] == 1)
	{
		ft_strclr(tab);
		free(tab);
	}
	return (1);
}

void	ft_writeend(char *s, int *i, int *cpt)
{
	while (s[*i] && s[*i] != '%')
	{
		ft_putchar(s[*i]);
		*cpt = *cpt + 1;
		*i = *i + 1;
	}
	*i = *i - (s[*i - 1] == '%' ? 1 : 0);
}

int		ft_testfin(char *s, int *i, int *t, int *cpt)
{
	if (t[2] == -1 && (s[*i] == '\t' || s[*i] == '\r' || s[*i] == '\v'
	|| s[*i] == '\a' || s[*i] == '\f' || s[*i] == '\b'))
		ft_writeend(s, i, cpt);
	else if (t[2] == 0)
	{
		while (s[*i] == '%' || s[*i] == ' ' || s[*i] == 'l'
		|| s[*i] == 'h' || s[*i] == 'j' || s[*i] == 'z')
			*i = *i + 1;
		ft_writeend(s, i, cpt);
	}
	else if (s[*i] != '%')
	{
		ft_putchar(s[*i]);
		*cpt = *cpt + 1;
	}
	return (1);
}

int		ft_solve(int *d, char *s, char **tab)
{
	int	t[10];

	t[0] = 1;
	t[3] = 1;
	t[2] = -1;
	t[4] = -1;
	t[5] = 0;
	while (s[++t[4]])
	{
		if (s[t[4]] == '%')
		{
			ft_flagstock(d, s, t[4] + 1);
			t[2] = ft_testsimp(s, &t[1], t);
			if (t[2] == 1 || t[2] == 2)
				ft_solvefin(d, s, t, tab[t[0]++]);
			else if (t[2] == 3)
				t[3] = ft_solvess(d, tab, t, s);
			else
				ft_testfin(s, &t[1], t, &d[0]);
			t[4] = t[1] - (t[2] == 0 ? 1 : 0);
		}
		else
			ft_testfin(s, &t[4], t, &d[0]);
	}
	return (1);
}
