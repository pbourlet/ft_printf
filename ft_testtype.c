/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testtype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:59:54 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/23 20:56:40 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_testfinal(int *test, char *s, int *t)
{
	if (*test == 0 && ((((s[t[4] - 2] == ' ' || s[t[4] - 2] == '%')
	&& s[t[4] - 1] == 'l') || s[t[4] - 1] == 'h' || s[t[4] - 1] == 'j'
	|| s[t[4] - 1] == 'z'	|| s[t[1] - 1] == '%')
	&& ft_testall(s, &t[1]) == 1) && s[t[1]] == s[t[4]] && (*test = 1))
		return (1);
	return (0);
}

int	ft_testall(char *s, int *i)
{
	if ((s[*i] == 'l' || s[*i + 1] == 'l'|| s[*i] == 'h' || s[*i + 1] == 'h'
	|| s[*i] == 'j'	|| s[*i] == 'z') && !(s[*i] == 's' || s[*i] == 'S'
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

int	ft_testsimp(char *s, int *i, int *t)
{
	int	c;
	int tt;

	c = *i;
	tt = *t;
	c++;
	while (s[c] == ' ')
	    c++;
	*t = c;
	if (s[*t] == 'l' || s[*t] == 'h' || s[*t] == 'j' || s[*t] == 'z')
		*t = *t + 1;
	if (s[*t] == 'l' || s[*t] == 'h')
		*t = *t + 1;
	if (s[*t] == 'C' || (s[c + 1] != 'l' && s[c] == 'l' && s[*t] == 'c'))
		return (2);
	if (s[*t] == 'S' || (s[c + 1] != 'l' && s[c] == 'l' && s[*t] == 's'))
		return (3);
	if (ft_testall(s, t) == 1)
		return (1);
	return (0);
}
