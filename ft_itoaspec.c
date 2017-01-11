/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoaspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 12:57:38 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/11 19:51:08 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoalu(unsigned long n)
{
	char			*str;
	unsigned long	nb;
	unsigned long	i;
	unsigned long	len;

	i = 0;
	nb = n;
	len = ft_lenlu(nb);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (nb == 0)
		return (ft_strcpy(str, "0"));
	while (nb != 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	str[i] = '\0';
	str = ft_strrev(str);
	return (str);
}


char	*ft_itoalong(long int n)
{
	char		*str;
	long		nb;
	long int	i;
	long int	len;

	i = 0;
	nb = n;
	if (n < 0)
		nb = -nb;
	len = ft_nblen(nb);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1 + (n < 0)))))
		return (NULL);
	if (nb == 0)
		return (ft_strcpy(str, "0"));
	while (nb != 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	str = ft_strrev(str);
	return (str);
}

char	*ft_itosh(unsigned short int nb, int base)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = ft_strnew(11)))
		return (NULL);
	if (nb == 0)
		return (ft_strcpy(str, "0"));
	while (nb != 0)
	{
		if (nb % base <= base - 1)
			str[i] = (nb % base) + '0';
		if (nb % base >= 10)
			str[i] = 'a' + ((nb % base) % 10);
		nb = nb / base;
		i++;
	}
	str[i] = '\0';
	str = ft_strrev(str);
	return (str);
}

char	*ft_itohx(unsigned long nb)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = ft_strnew(11)))
		return (NULL);
	if (nb == 0)
		return (ft_strcpy(str, "0"));
	while (nb != 0)
	{
		if (nb % 16 <= 15)
			str[i] = (nb % 16) + '0';
		if (nb % 16 >= 10)
			str[i] = 'a' + ((nb % 16) % 10);
		nb = nb / 16;
		i++;
	}
	str[i] = '\0';
	str = ft_strrev(str);
	return (str);
}

char	*ft_itoaoc(unsigned long nb)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = ft_strnew(11)))
		return (NULL);
	if (nb == 0)
		return (ft_strcpy(str, "0"));
	while (nb)
	{
		str[i] = (nb % 8) + '0';
		nb = nb / 8;
		i++;
	}
	str[i] = '\0';
	str = ft_strrev(str);
	return (str);
}
