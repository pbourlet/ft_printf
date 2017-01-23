/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solveS.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:56:21 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/23 20:14:44 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_Sfinal(int *spt, int *cpt, char **tab, int *t)
{
	while (*spt)
	{
		ft_solveC(cpt, tab[t[0]]);
		t[0]++;
		*spt = *spt - 1;
	}
	return (1);
}

int		ft_solveS(int *spt, int *cpt, char **tab, int *t, char *s)
{
	int e;
	
	e = t[4] + 1;
	ft_Sfinal(spt, cpt, tab, t);
	while (s[t[4] + 1] == ' ')
		t[4]++;
	t[4] = t[4] + (s[t[1] - 1] == 'l' ? 1 : 0)
	+ (s[t[1] - 2] == 'l' ? 1 : 0) + (s[t[1] - 1] == 'h' ? 1 : 0)
	+ (s[t[1] - 2] == 'h' ? 1 : 0) + (s[t[1] - 1] == 'j' ? 1 : 0)
	+ (s[t[1] - 1] == 'z' ? 1 : 0)  + (s[e] == ' ' ? 1 : 0);
	return (1);
}
