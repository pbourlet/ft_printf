/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:59:04 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/13 11:08:39 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# include <inttypes.h>

int		ft_printf(const char *format, ...);
char		**ft_stock(char *s, va_list ap);
char		*ft_itoalong(long int n);
char		*ft_itoalu(unsigned long n);
char		*ft_itohx(unsigned long nb);
char		*ft_itosh(unsigned short int nb, int base);
char 		*ft_itoalu(unsigned long n);
long int	ft_lenlu(unsigned long nb);
char		*ft_itoaoc(unsigned long nb);
char		*stup(char *str);
int		ft_solve(int *cpt, char *s, int i, char **tab);
char		*ft_itoabase(long nb, int base);
int		ft_solvespec(int *cpt, char *s, int *i, char **tab, int *a);
int		ft_testsimp(char *s, int *i);
char		**ft_stockh(char **tab, char *s, va_list ap, int i, int *a);
char		**ft_stockj(char **tab, char *s, va_list ap, int i, int *a);
int		ft_stocktestlong(char *s, int *i);

#endif
