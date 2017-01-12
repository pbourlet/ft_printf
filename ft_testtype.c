/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testtype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:59:54 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/12 19:04:27 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
int	ft_testh(char *s, int *i)
{
	if (s[*i + 1] == 's' || s[*i + 1] == 'd' || s[*i + 1] == 'i' ||
	s[*i + 1] == 'u' || s[*i + 1] == 'o' || s[*i + 1] == 'x' ||
	s[*i + 1] == 'X' || s[*i + 1] == 'D' ||	s[*i + 1] == 'O' ||
	s[*i + 1] == 'U')
		return (5);
	return (0);
}*/

int	ft_stocktestlong(char *s, int *i)
{
	*i = *i + 1;
	if (s[*i] == 's' || s[*i] == 'd' || s[*i] == 'i' || s[*i] == 'u' ||
	s[*i] == 'o' || s[*i] == 'x' || s[*i] == 'X' || s[*i] == 'D' ||
	s[*i] == 'O' || s[*i] == 'U' || s[*i] == 'p' || s[*i] == 'c')
		return (3);
	return (0);
}

int	ft_testlong(char *s, int *i)
{
	int	c;

	c = *i;
	if (s[c] == 'l' || s[c] == 'h')
		c = c + 1;
	if (s[c] == 's' || s[c] == 'd' || s[c] == 'i' || s[c] == 'u' ||
	s[c] == 'o' || s[c] == 'x' || s[c] == 'X' || s[c] == 'D' ||
	s[c] == 'O' ||	s[c] == 'U' || s[c] == 'p' || (s[c - 1] != 'l' &&
	s[c] == 'c'))
		return (1);
	return (0);
}

int	ft_testsimp(char *s, int *i)
{
	if (s[*i - 1] == '%')
	{
		if (ft_testlong(s, i) == 1)
			return (1);
	if (s[*i] == 'C' || (s[*i] == 'l' && (s[*i + 1] == 'c' ||
	s[*i + 1] == 'C')))
	{
		*i = *i + (s[*i] == 'l' ? 1 : 0);
		return (3);
	}
	if (s[*i] == 'S')
		return (4);
//	if (s[*i - 1] == '%' && (s[*i] == 'l' || s[*i] == 'h'))
//		return (ft_testlong(s, i));
//	if (s[*i - 1] == '%' && s[*i] == 'h')
//		return (ft_testh(s, i));
	}
	return (0);
}
/*
int	ft_testspec(char *s, int *i)
{
	if (s[*i - 1] == '%' &
}*/
