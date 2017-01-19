/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:59:04 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/19 20:52:09 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# include <inttypes.h>

int			ft_printf(const char *format, ...);
wchar_t		*ft_wstrdup(wchar_t *s);
size_t		ft_wstrlen(wchar_t *s);
char		*ft_itoalong(long int n);
char		*ft_itoalu(uintmax_t n);
char		*ft_itohx(uintmax_t nb);
char		*ft_itosh(unsigned short int nb, int base);
char		*ft_itoaoc(uintmax_t nb);
long int	ft_lenlu(unsigned long nb);
char		*stup(char *str);
int			ft_solve(int *spt, int *cpt, char *s, char **tab);
char		*ft_itoabase(long nb, int base);
int			ft_solveC(int *cpt, char *tab, int *t);
int			ft_solveS(int *spt, int *cpt, char **tab, int  *t);
int			ft_testsimp(char *s, int *i, int *t);
int			ft_testall(char *s, int *i);
char		**ft_stock(int * spt, char *s, va_list ap);
char		*ft_stocksimp(char *s, va_list ap, int i);
char		*ft_stockh(char *s, va_list ap, int i);
char		*ft_stockj(char *s, va_list ap, int i);
char		*ft_stockz(char *s, va_list ap, int i);
char		*ft_stockll(char *s, va_list ap, int i);
char		*ft_stockhh(char *s, va_list ap, int i);
char		**ft_stockS(int *spt, va_list ap, char **tab, int *a);

#endif
