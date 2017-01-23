/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solveC.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:27:46 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/23 20:14:17 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_resul(char *res, int lenb)
{
	char *tronc[4];

	tronc[0] = ft_strsub(res, 0, 8);
	tronc[1] = ft_strsub(res, 8, 8);
	tronc[2] = ft_strsub(res, 16, 8);
	tronc[3] = ft_strsub(res, 24, 8);
	ft_putchar(ft_atoibase(tronc[0], 2));
	if (lenb > 7)
		ft_putchar(ft_atoibase(tronc[1], 2));
	if (lenb > 11)
		ft_putchar(ft_atoibase(tronc[2], 2));
	if (lenb > 16)
		ft_putchar(ft_atoibase(tronc[3], 2));
	ft_strclr(tronc[0]);
	ft_strclr(tronc[1]);
	ft_strclr(tronc[2]);
	ft_strclr(tronc[3]);
	ft_strdel(tronc);
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

int		ft_solveC(int *cpt, char *tab)
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
	ft_strclr(tab);
	free(tab);
	return (1);
}

int		ft_Cfinal(int *cpt, char *tab, int *t, char *s)
{
	int e;

	e = t[4] + 1;
	ft_solveC(cpt, tab);
	while (s[t[4] + 1] == ' ')
		t[4]++;
	t[4] = t[4] + 1 + (s[t[1] - 1] == 'l' ? 1 : 0)
		+ (s[t[1] - 2] == 'l' ? 1 : 0) + (s[t[1] - 1] == 'h' ? 1 : 0)
		+ (s[t[1] - 2] == 'h' ? 1 : 0) + (s[t[1] - 1] == 'j' ? 1 : 0)
		+ (s[t[1] - 1] == 'z' ? 1 : 0)  + (s[e] == ' ' ? 1 : 0);
	return (1);
}
