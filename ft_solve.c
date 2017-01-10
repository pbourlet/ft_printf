/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:42:20 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/10 15:52:09 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_solvelong(int *cpt, int *i, char *tab)
{
	*i = *i + 1;
	*cpt = *cpt + ft_strlen(tab);
	ft_putstr(tab);
	return (1);
}

int	ft_solvesimple(int *cpt, char *s, int *i, char *tab)
{
	if (s[*i] ==  'p')
	{
		ft_putstr("0x");
		ft_putstr(tab);
		*cpt = *cpt + 2;
	}
	else if (s[*i] == 'c')
		ft_putchar(tab[0]);
	else
		ft_putstr(tab);
	*cpt = *cpt + ft_strlen(tab);
	return (1);
}

int	testtype(char *s, int *i)
{
	if (s[*i - 1] == '%' && (s[*i] == 's' || s[*i] == 'd' || s[*i] == 'c'
				|| s[*i] == 'i' || s[*i] == 'u' || s[*i] == 'p' || s[*i] == 'o'
				|| s[*i] == 'x' || s[*i] == 'X' || s[*i] == 'D' || s[*i] == 'O'
				|| s[*i] == 'U'))
		return (1);
	if (s[*i - 1] == '%' && s[*i] == 'l' && (s[*i + 1] == 'p'))
	{
		*i = *i + 1;
		return (1);
	}
	if (s[*i - 1] == '%' && s[*i] == 'l' && (s[*i + 1] == 's' ||
	s[*i + 1] == 'd' || s[*i + 1] == 'i' ||	s[*i + 1] == 'u' ||
	s[*i + 1] == 'o' || s[*i + 1] == 'x' || s[*i + 1] == 'X' ||
	s[*i + 1] == 'D' || s[*i + 1] == 'O' || s[*i + 1] == 'U'))
		return (2);
	if (s[*i - 1] == '%' && s[*i] == 'C')
		return (3);
	if (s[*i - 1] == '%' && s[*i] == 'l' && (s[*i + 1] == 'c' ||
	s[*i + 1] == 'C'))
	{
		*i = *i + 1;
		return (3);
	}
	return (0);
}

int	ft_solve(int *cpt, char *s, int i, char **tab)
{
	int	a;
	int	t;

	a = 1;
	while (s[i])
	{
		t = testtype(s, &i);
		if (t == 1)
			ft_solvesimple(cpt, s, &i, tab[a++]);
		else if (t == 2)
			ft_solvelong(cpt, &i, tab[a++]);
		else if (t == 3)
			ft_solvespec(s, &i, tab[a++]);
		//		else if (s[i - 1] == '%' && s[i + 1] == '$')
		//			str = ft_ndisp(str, s, ap, &i, tab);
		else if (s[i] != '%')
		{
			if (s[i] == '\n')
				*cpt = *cpt - 1;
			ft_putchar(s[i]);
			*cpt = *cpt + 1;
		}
		i++;
	}
	return (1);
}
