/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:23:44 by pbourlet          #+#    #+#             */
/*   Updated: 2017/02/09 18:42:56 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_tabclr(char **tab, int len)
{
	int i;

	i = 0;
	while (tab[i] && i < len)
	{
		ft_strclr(tab[i]);
		free(tab[i]);
		i++;
	}
}

char	*ft_resul(char *res, char *tab, int lenb)
{
	char	*tronc[4];
	int		ii;

	ii = 0;
	tronc[0] = ft_strsub(res, 0, 8);
	tronc[1] = ft_strsub(res, 8, 8);
	tronc[2] = ft_strsub(res, 16, 8);
	tronc[3] = ft_strsub(res, 24, 8);
	tab[ii++] = ft_atoibase(tronc[0], 2);
	if (lenb > 7)
		tab[ii++] = ft_atoibase(tronc[1], 2);
	if (lenb > 11)
		tab[ii++] = ft_atoibase(tronc[2], 2);
	if (lenb > 16)
		tab[ii++] = ft_atoibase(tronc[3], 2);
	ft_tabclr(tronc, 4);
	return (tab);
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

char	**ft_init(char **tabi)
{
	tabi[0] = ft_strdup("0xxxxxxx");
	tabi[1] = ft_strdup("110xxxxx10xxxxxx");
	tabi[2] = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	tabi[3] = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	return (tabi);
}

char	*ft_bintoa(char *tab)
{
	char	**tabi;
	char	*res;
	int		lenb;
	int		nb;

	tabi = ft_strnew(0);
	ft_init(tabi);
	res = NULL;
	lenb = ft_strlen(tab);
	nb = (lenb <= 21 ? 4 : 0) - (lenb <= 16 ? 1 : 0) - (lenb <= 11 ? 1 : 0)
		- (lenb <= 7 ? 1 : 0);
	if (lenb <= 7)
		res = ft_trad(tabi[0], tab, lenb);
	else if (lenb <= 11)
		res = ft_trad(tabi[1], tab, lenb);
	else if (lenb <= 16)
		res = ft_trad(tabi[2], tab, lenb);
	else if (lenb <= 21)
		res = ft_trad(tabi[3], tab, lenb);
	ft_strclr(tab);
	tab = ft_resul(res, tab, lenb);
	ft_tabclr(tabi, nb - 1);
	ft_strclr(res);
	return (tab);
}
