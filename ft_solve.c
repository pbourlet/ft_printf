/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:42:20 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/18 20:06:19 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_solvefin(int *cpt, char *s, int *i, char *tab)
{
	*i = *i + ((s[*i] == 'l' || s[*i] == 'h' || s[*i] == 'j' ||
	s[*i] == 'z') ? 1 : 0) + ((s[*i + 1] == 'l' || s[*i + 1] == 'h')
	? 1 : 0);
	if (s[*i] ==  'p')
	{
		ft_putstr("0x");
		*cpt = *cpt + 2;
	}
	ft_putstr(tab);
	*cpt = *cpt + ft_strlen(tab);
	return (1);
}

int	ft_testfin(int *cpt, char *s, int *i)
{
	if (s[*i - 1] == '%' && (s[*i] == 'l' || s[*i] == 'h' || s[*i] == 'j'
	|| s[*i] == 'z'))
	{
		if (!s[*i + 1])
		{
			*cpt = -1;
			return (0);
		}
		ft_putchar(s[*i - 1]);
		*cpt = *cpt + 1;
		*i = *i + 1 + ((s[*i] == s[*i + 1]) ? 1 : 0);
		return (1);
	}
	if (!ft_testall(s, i))
		return (1);
	if (s[*i] != '%')
		return (1);
	return (0);
}

int	ft_solve(int *spt, int *cpt, char *s, int i, char **tab)
{
	int	a;
	int	t;
	int	f;

	a = 1;
	f = 1;
	while (s[i])
	{
		t = ft_testsimp(s, &i);
		if (t == 1)
			f = ft_solvefin(cpt, s, &i, tab[a++]);
		else if (t == 3)
			f = ft_solvespec(cpt, tab[a++]);
		else if (t == 4)
			ft_solveS(spt, cpt, tab, &a);
		else if (ft_testfin(cpt, s, &i) == 1)
		{
			if (f == 0)
				return (1);
			ft_putchar(s[i]);
			*cpt = *cpt + 1;
		}
		i++;
	}
	return (1);
}
