/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:42:20 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/09 18:19:29 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

char	*ft_solvelong(char *str, int *i, char *tab)
{
	*i = *i + 1;
	return ((str = ft_strjoin(str, tab)));
}

char	*ft_solvesimple(char *str, char *s, int *i, char *tab)
{
	if (s[*i] ==  'p')
	{
		str = ft_strjoin(str, "0x");
		str = ft_strjoin(str, tab);
	}
	else if (s[*i] == 'c')
		str = ft_strcjoin(str, tab[0]);
	else
		str = ft_strjoin(str, tab);
	return (str);
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
				s[*i + 1] == 'd' || s[*i + 1] == 'i' ||
				s[*i + 1] == 'u' || s[*i + 1] == 'p' || s[*i + 1] == 'o' ||
				s[*i + 1] == 'x' || s[*i + 1] == 'X' || s[*i + 1] == 'D' ||
				s[*i + 1] == 'O' || s[*i + 1] == 'U'))
		return (2);
	if (s[*i - 1] == '%' && s[*i] == 'C')
		return (3);
	return (0);
}

char	*ft_solve(char *str, char *s, int i, char **tab)
{
	int	a;

	a = 1;
	while (s[i])
	{
		if (testtype(s, &i) == 1)
			str = ft_solvesimple(str, s, &i, tab[a++]);
		else if (testtype(s, &i) == 2)
			str = ft_solvelong(str, &i, tab[a++]);
		else if (testtype(s, &i) == 3)
			ft_solvespec(s, &i, tab[a++]);
		//		else if (s[i - 1] == '%' && s[i + 1] == '$')
		//			str = ft_ndisp(str, s, ap, &i, tab);
		else if (s[i] != '%')
		{
			if (s[i - 1] == '%' && s[i] == 'l')
			{
				s[i] = '\0';

			}
			str = ft_strcjoin(str, s[i]);
		}
		i++;
	}
	return (str);
}
