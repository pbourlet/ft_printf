/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:59:04 by pbourlet          #+#    #+#             */
/*   Updated: 2017/02/07 00:06:18 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# include <inttypes.h>

typedef struct	s_int
{
	int			test[50];
	int			ii;
	int			bb;
}				t_int;

void			ft_putnstr(char *s, int n);
void			ft_testflags2(int *t, int *d, char *s, char *tab);
size_t			ft_wstrlen(wchar_t *s);
long int		ft_lenlu(unsigned long nb);
int				ft_printf(const char *format, ...);
int				ft_solve(int *d, char *s, char **tab, t_int *l);
int				ft_atoilbase(char *str, int base);
int				ft_solvespec(int *spt, int *cpt, char *s, int *t, char **tab);
int				ft_solvecc(int *cpt, char *tab, int lenb);
int				ft_ccfinal(int *cpt, char *tab, int *t, char *s);
int				ft_solvess(int *d, char **tab, int *t, char *s, t_int *l);
int				ft_solvefin(int *d, char *s, int *t, char *tab);
int				ft_testsimp(char *s, int *i, int *t);
int				ft_testall(char *s, int *i);
int				ft_testpass(char *s, int i);
int				ft_testfinal(int *test, char *s, int *t);
int				ft_testdigit(int *d, char *s, int *t, char *tab);
int				ft_testflags1(int *t, int *d, char *s, char *tab);
int				ft_testflags3(int *t, int *d, char *s, char *tab);
int				ft_flagstock(int *d, char *s, int i);
char			*stup(char *str);
char			*ft_itoalong(long int n);
char			*ft_itoabase(intmax_t nb, int base);
char			*ft_itoalu(uintmax_t n);
char			*ft_itohx(uintmax_t nb);
char			*ft_itosh(unsigned short int nb, int base);
char			*ft_itoaoc(uintmax_t nb);
char			**ft_stock(int *d, char *s, va_list ap, t_int *l);
char			*ft_stocksimp(char *s, va_list ap, int i);
char			*ft_stocksimps(char *tab, va_list ap);
char			*ft_stocklong(char *s, va_list ap, int i);
char			*ft_stockh(char *s, va_list ap, int i);
char			*ft_stockj(char *s, va_list ap, int i);
char			*ft_stockz(char *s, va_list ap, int i);
char			*ft_stockll(char *s, va_list ap, int i);
char			*ft_stockhh(char *s, va_list ap, int i);
char			**ft_stockss(va_list ap, char **tab, int *d, t_int *l);
wchar_t			*ft_wstrdup(wchar_t *s);

#endif
