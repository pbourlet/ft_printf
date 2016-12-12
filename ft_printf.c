/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:26:22 by pbourlet          #+#    #+#             */
/*   Updated: 2016/12/12 18:28:50 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

char	*ft_test(char *tmp, char *s, va_list ap, int i)
{
	while (s[i])
	{
		if (s[i - 1] == '%' && s[i] == 's')
			tmp = ft_strjoin(tmp, va_arg(ap, char *));
		else if (s[i - 1] == '%' && s[i] == 'd')
			tmp = ft_strjoin(tmp, ft_itoa(va_arg(ap, int)));
		else if (s[i - 1] == '%' && s[i] == 'c')
			tmp = ft_strcjoin(tmp, va_arg(ap, int));
		else if (s[i] != '%')
			tmp = ft_strcjoin(tmp, s[i]);
		i++;
	}
	return (tmp);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list		ap;
	char		*s;
	char		*tmp;
	int			i;

	i = 0;
	va_start(ap, format);
	s = ft_strdup(format);
	tmp = ft_strnew(0);
	tmp = ft_test(tmp, s, ap, i);
	ft_putstr(tmp);
	free(s);
	va_end(ap);
	return (1);
}

int		main(void)
{
	ft_printf("lol %d %c\n", 19, 'k', "mdr");
	printf("lol %d %c\n", 19, 'k', "mdr");
	return (0);
}
