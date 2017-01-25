/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:59:04 by pbourlet          #+#    #+#             */
/*   Updated: 2017/01/25 14:05:04 by pbourlet         ###   ########.fr       */
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
wchar_t		*ft_wstrdup(wchar_t *s);
size_t		ft_wstrlen(wchar_t *s);
char		*ft_itoalong(long int n);
char		*ft_itoalu(uintmax_t n);
char		*ft_itohx(uintmax_t nb);
char		*ft_itosh(unsigned short int nb, int base);
char		*ft_itoaoc(uintmax_t nb);
long int	ft_lenlu(unsigned long nb);
char		*stup(char *str);
int		ft_solve(int *d, char *s, char **tab);
char		*ft_itoabase(long nb, int base);
int			ft_atoilbase(char *str, int base);
int			ft_solvespec(int *spt, int *cpt, char *s, int *t, char **tab);
int			ft_solveC(int *cpt, char *tab);
int			ft_Cfinal(int *cpt, char *tab, int *t, char *s);
int			ft_solveS(int *spt, int *cpt, char **tab, int  *t, char *s);
int			ft_testsimp(char *s, int *i, int *t);
int			ft_testall(char *s, int *i);
int			ft_testfinal(int *test, char *s, int *t);
char		**ft_stock(int *d, char *s, va_list ap);
char		*ft_stocksimp(char *s, va_list ap, int i, int *d);
char		*ft_stockh(char *s, va_list ap, int i, int *d);
char		*ft_stockj(char *s, va_list ap, int i, int *d);
char		*ft_stockz(char *s, va_list ap, int i, int *d);
char		*ft_stockll(char *s, va_list ap, int i, int *d);
char		*ft_stockhh(char *s, va_list ap, int i, int *d);
char		**ft_stockS(int *spt, va_list ap, char **tab, int *a);

#endif
