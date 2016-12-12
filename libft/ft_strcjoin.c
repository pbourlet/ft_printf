/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:52:51 by pbourlet          #+#    #+#             */
/*   Updated: 2016/12/12 16:58:08 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcjoin(char const *s1, char const s2)
{
	char	*frais;
	int		i;
	int		len;

	if ((i = 0) && ft_strcmp(s1, "") == 0)
		return ((char *)s1);
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + sizeof(char);
	if (!(frais = ft_strnew(len)))
		return (NULL);
	while (s1[i] != '\0' && i < len)
	{
		frais[i] = s1[i];
		i++;
	}
	frais[i++] = s2;
	frais[i] = '\0';
	return (frais);
}
