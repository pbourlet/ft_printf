/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:59:04 by pbourlet          #+#    #+#             */
/*   Updated: 2016/12/14 13:34:10 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int			ft_printf(const char * restrict format, ...);
char		**ft_stock(char *s, va_list ap);
char		*ft_itoalong(long int n);
char		*ft_itoalu(unsigned long n);
char		*ft_itohx(unsigned long nb);
char 		*ft_itoalu(unsigned long n);
long int	ft_lenlu(unsigned long nb);
char		*ft_itoaoc(unsigned long nb);

#endif
