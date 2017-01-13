/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:42:20 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/13 12:57:56 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_solvefin(int *cpt, char *s, int *i, char **tab, int *a)
{
	*i = *i + ((s[*i] == 'l' || s[*i] == 'h' || s[*i] == 'j') ? 1 : 0);
	if (tab[*a][0] == '\0')
		*a = *a + 1;
	if (s[*i] ==  'p')
	{
		ft_putstr("0x");
		*cpt = *cpt + 2;
	}
	ft_putstr(tab[*a]);
	*cpt = *cpt + ft_strlen(tab[*a]);
	*a = *a + 1;
	return (1);
}

int	ft_testfin(int *cpt, char *s, int *i)
{
	if (s[*i - 1] == '%' && (s[*i] == 'l' || s[*i] == 'h' || s[*i] == 'j'))
	{
		if (!s[*i + 1])
		{
			*cpt = -1;
			return (0);
		}
		ft_putchar(s[*i - 1]);
		*cpt = *cpt + 1;
		*i = *i + 1;
		return (1);
	}
	if (s[*i] != '%')
		return (1);
	return (0);
}

int	ft_solve(int *cpt, char *s, int i, char **tab)
{
	int	a;
	int	t;

	a = 1;
	while (s[i])
	{
		t = ft_testsimp(s, &i);
		if (t == 1)
			ft_solvefin(cpt, s, &i, tab, &a);
		else if (t == 3)
			ft_solvespec(cpt, s, &i, tab, &a);
//		else if (t == 4)
//			ft_solveS(cpt, s, &i, tab[a++]);
//		else if (t == 5)
//			ft_solvelong(cpt, s, &i, tab[a++]);
		else if (ft_testfin(cpt, s, &i) == 1)
		{
			ft_putchar(s[i]);
			*cpt = *cpt + 1;
		}
		i++;
	}
	return (1);
}
