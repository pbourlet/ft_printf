/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testtype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:58:26 by pbourlet          #+#    #+#             */
/*   Updated: 2017/02/28 20:42:05 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_testall(char *s, int *i)
{
	if ((s[*i] == 'l' || s[*i] == 'h' || s[*i + 1] == 'h'
		|| s[*i] == 'j' || s[*i] == 'z') && !(s[*i] == 's' || s[*i] == 'S'
		|| s[*i] == 'c' || s[*i] == 'C' || s[*i] == 'i' || s[*i] == 'd'
		|| s[*i] == 'D' || s[*i] == 'u' || s[*i] == 'U' || s[*i] == 'p'
		|| s[*i] == 'o' || s[*i] == 'O' || s[*i] == 'x' || s[*i] == 'X'))
		return (2);
	if (s[*i] == 's' || s[*i] == 'S' || s[*i] == 'c' || s[*i] == 'C'
		|| s[*i] == 'i' || s[*i] == 'd' || s[*i] == 'D' || s[*i] == 'u'
		|| s[*i] == 'U' || s[*i] == 'p' || s[*i] == 'o' || s[*i] == 'O'
		|| s[*i] == 'x' || s[*i] == 'X' || s[*i] == 'l' || s[*i] == 'h'
		|| s[*i] == 'z' || s[*i] == 'j')
		return (1);
	return (0);
}

int		ft_natoi(int *i, char *s, char **tab, int *t)
{
	int res;

	res = 0;
	*i = *i + (s[*i] == '.' ? 1 : 0);
	if (s[*i] == '*')
	{
		res = (tab[t[0]][0] == '-' ? 0 : ft_atoi(tab[t[0]]));
		t[0]++;
		(!res && s[*i - 1] == '.' ? t[7] = 0 : 0);
		*i += 1;
		return (res);
	}
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		res *= 10;
		res += (s[*i] - '0');
		*i = *i + 1;
	}
	return (res);
}

int		ft_testpass(char *s, int i)
{
	if (s[i] == ' ' || s[i] == '+' || s[i] == '-' || s[i] == '#'
	|| s[i] == '.' || (s[i] >= '0' && s[i] <= '9'))
		return (1);
	return (0);
}

void	ft_testwflg(char *s, int *i, int *t, char **tab)
{
	int res;

	while (!(res = 0) && (ft_testpass(s, *i) || s[*i] == '*') && s[*i]
	&& s[*i] != '%' && !ft_testall(s, i))
	{
		while (s[*i] == ' ' || s[*i] == '+' || s[*i] == '-' || s[*i] == '#')
			*i = *i + 1;
		(s[*i] == '.' ? t[7] = 1 : 0);
		if (s[*i] == '.')
			t[5] = ft_natoi(i, s, tab, t);
		else if (((s[*i] >= '0' && s[*i] <= '9') || s[*i] == '*')
		&& s[*i - 1] != '.')
		{
			res = ft_natoi(i, s, tab, t);
			t[6] = (res != 0 || s[*i - 1] == '*' ? res : t[6]);
		}
		if (s[*i] == '%' || (!ft_testall(s, i) && !ft_testpass(s, *i)
		&& s[*i] != '*'))
			return ;
		*i = *i + (!ft_testall(s, i) && !ft_testpass(s, *i)
		&& s[*i] != '*' ? 1 : 0);
	}
	while (s[*i] == ' ' && s[*i])
		*i += 1;
}

int		ft_testsimp(char *s, int *i, int *t, char **tab)
{
	*i = t[4] + 1;
	t[6] = 0;
	t[7] = 0;
	while (ft_testall(s, i) != 1 && s[*i] != '%' && s[*i])
	{
		ft_testwflg(s, i, t, tab);
		if (!ft_testall(s, i) && !ft_testpass(s, *i) && s[*i] != '%'
		&& s[*i] != '*')
			return (0);
		if ((s[*i] == 'l' || s[*i] == 'h' || s[*i] == 'j' || s[*i] == 'z')
		&& s[*i])
			*i = *i + 1;
		if ((s[*i] == 'l' || s[*i] == 'h' || s[*i] == '*') && s[*i])
			*i = *i + 1;
	}
	if ((ft_testall(s, i) == 1 || s[*i] == '%') && s[*i])
		return (1);
	return (0);
}
