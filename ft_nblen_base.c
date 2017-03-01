/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 19:52:23 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/01 19:52:25 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nblen_base(long long n, int base)
{
	int			len;
	long double	pow;

	pow = 1;
	len = 0;
	if (n < 0)
		len++;
	n < 0 ? n = -n : 0;
	while (n >= (pow *= base))
		len++;
	return (len + 1);
}

int		ft_unblen_base(uintmax_t n, int base)
{
	int			len;
	long double	pow;

	pow = 1;
	len = 0;
	while (n >= (pow *= base))
		len++;
	return (len + 1);
}
