/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solvespec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:49:22 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/09 18:12:27 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_resul(char *res)
{
	int	un;
	int	deux;
	int	trois;
	int quatre;

	if (res)
	{
		un = ft_atoibase(ft_strsub(res, 0, 8), 2);
		ft_memmove(res, res + 8, 8);
		ft_putchar(un);
	}
	if (res)
	{
		deux = ft_atoibase(ft_strsub(res, 0, 8), 2);
		ft_memmove(res, res + 8, 8);
		ft_putchar(deux);
	}
	if (res)
	{
		trois = ft_atoibase(ft_strsub(res, 0, 8), 2);
		ft_memmove(res, res + 8, 8);
		ft_putchar(trois);
	}
	if (res)
	{
		quatre = ft_atoibase(ft_strsub(res, 0, 8), 2);
		ft_memmove(res, res + 8, 8);
		ft_putchar(quatre);
	}
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

int		ft_solvespec(char *s, int *i, char *tab)
{
	char	tab0[9] = "0xxxxxxx";
	char	tab1[17] = "110xxxxx10xxxxxx";
	char	tab2[25] = "1110xxxx10xxxxxx10xxxxxx";
	char	tab3[33] = "11110xxx10xxxxxx10xxxxxx10xxxxxx";
	char	*res;
	int		lenb;

	res = NULL;
	lenb = ft_strlen(tab);
	if (s[*i] == 'C')
	{
		if (lenb <= 7)
			res = ft_trad(tab0, tab, lenb);
		else if (lenb <= 11)
			res = ft_trad(tab1, tab, lenb);
		else if (lenb <= 16)
			res = ft_trad(tab2, tab, lenb);
		else if (lenb <= 21)
			res = ft_trad(tab3, tab, lenb);
	}
	ft_putendl(res);
	ft_resul(res);
	return (1);
}
