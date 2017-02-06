/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testtype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:59:54 by pbourlet          #+#    #+#             */
/*   Updated: 2017/02/06 18:38:51 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_testall(char *s, int *i)
{
	if ((s[*i] == 'l' || s[*i + 1] == 'l' || s[*i] == 'h' || s[*i + 1] == 'h'
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

int		ft_litoa(int *i, char *s)
{
	int res;

	res = 0;
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
	if (s[i] == ' ' || s[i] == '+' || s[i] == '-' || s[i] == '#' || s[i] == '.'
	|| (s[i] >= '0' && s[i] <= '9'))
		return (1);
	return (0);
}

void	ft_testwflg(char *s, int *i, int *t)
{
	while (ft_testpass(s, *i) && s[*i] && s[*i] != '%' && !ft_testall(s, i))
	{
		while (s[*i] == ' ' || s[*i] == '+' || s[*i] == '-' || s[*i] == '#'
			|| s[*i] == '.')
			*i = *i + 1;
		if (s[*i] >= '0' && s[*i] <= '9' && s[*i - 1] == '.')
		{
			t[7] = 1;
			t[5] = ft_litoa(i, s);
		}
		else if (s[*i] >= '0' && s[*i] <= '9' && s[*i - 1 != '.'])
			t[6] = ft_litoa(i, s);
		if (s[*i] == '%' || (!ft_testall(s, i) && !ft_testpass(s, *i)))
			return ;
		*i = *i + (!ft_testall(s, i) ? 1 : 0);
	}
}

int		ft_testsimp(char *s, int *i, int *t)
{
	*i = t[4] + 1;
	t[6] = 0;
	t[7] = 0;
	while (ft_testall(s, i) != 1 && s[*i] != '%' && s[*i])
	{
		ft_testwflg(s, i, t);
		if (!ft_testall(s, i) && !ft_testpass(s, *i) && s[*i] != '%')
			return (0);
		if (s[*i] == 'l' || s[*i] == 'h' || s[*i] == 'j' || s[*i] == 'z')
			*i = *i + 1;
		if (s[*i] == 'l' || s[*i] == 'h')
			*i = *i + 1;
	}
	if (s[*i] == 'C' || (s[*i - 2] != 'l' && s[*i - 1] == 'l' && s[*i] == 'c'))
		return (2);
	if (s[*i] == 'S' || (s[*i - 2] != 'l' && s[*i - 1] == 'l' && s[*i] == 's'))
		return (3);
	if (ft_testall(s, i) == 1 || s[*i] == '%')
		return (1);
	return (0);
}
