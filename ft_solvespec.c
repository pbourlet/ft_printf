/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solvespec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:49:22 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/18 19:45:01 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_resul(char *res, int lenb)
{
	ft_putchar(ft_atoibase(ft_strsub(res, 0, 8), 2));
	if (lenb > 7)
		ft_putchar(ft_atoibase(ft_strsub(res, 8, 8), 2));
	if (lenb > 11)
		ft_putchar(ft_atoibase(ft_strsub(res, 16, 8), 2));
	if (lenb > 16)
		ft_putchar(ft_atoibase(ft_strsub(res, 24, 8), 2));
	return (1);
}

char	*ft_trad(char *tab, char *bin, int lenb)
{
	int lent;
	int c;

	c = -1;
	lent = ft_strlen(tab);
	while (lent-- && lenb)
	{
		if (tab[lent] == 'x')
			tab[lent] = bin[--lenb];
	}
	if (ft_strchr(tab, 'x') != NULL)
	{
		while (tab[++c])
		{
			if (tab[c] == 'x')
				tab[c] = '0';
		}
	}
	return (tab);
}

int		ft_solvespec(int *cpt, char *tab)
{
	char	tab0[9] = "0xxxxxxx";
	char	tab1[17] = "110xxxxx10xxxxxx";
	char	tab2[25] = "1110xxxx10xxxxxx10xxxxxx";
	char	tab3[33] = "11110xxx10xxxxxx10xxxxxx10xxxxxx";
	char	*res;
	int		lenb;

	res = NULL;
	lenb = ft_strlen(tab);
	if (lenb <= 7)
		res = ft_trad(tab0, tab, lenb);
	else if (lenb <= 11)
		res = ft_trad(tab1, tab, lenb);
	else if (lenb <= 16)
		res = ft_trad(tab2, tab, lenb);
	else if (lenb <= 21)
		res = ft_trad(tab3, tab, lenb);
	ft_resul(res, lenb);
	*cpt = *cpt + 1 + (lenb > 7 ? 1 : 0) + (lenb > 11 ? 1 : 0)
		+ (lenb > 16 ? 1 : 0);
	return (1);
}

int	ft_solveS(int *spt, int *cpt, char **tab, int *a)
{
	while (*spt)
	{
		ft_solvespec(cpt, tab[*a]);
		*a = *a + 1;
		*spt = *spt - 1;
	}
	return (1);
}
