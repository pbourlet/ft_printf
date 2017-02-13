/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:35:27 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/18 17:08:17 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*ft_wstrdup(wchar_t *s1)
{
	int		i;
	int		len;
	wchar_t	*str;

	i = 0;
	len = 0;
	while (s1[len] != '\0')
	{
		len++;
	}
	if (!(str = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_wstrlen(wchar_t *s)
{
	long i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
