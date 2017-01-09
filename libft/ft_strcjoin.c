/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:52:51 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/09 14:53:20 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcjoin(char const *s, char const c)
{
	char	*frais;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(frais = ft_strnew(len + 1)))
		return (NULL);
	frais = ft_strcpy(frais, s);
	frais[len] = c;
	return (frais);
}
