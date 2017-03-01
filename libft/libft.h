/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:21:22 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/01 17:53:34 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "../includes/ft_printf.h"

size_t	ft_strlen(const char *s);

int		ft_atoi(const char *str);
int		ft_atoibase(const char *str, int base);
int		ft_nblen(int nb);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_toupper(int c);

char	*ft_itoa(int n);
char	*ft_itoabase(intmax_t nb, int base);
char	*ft_strchr(char *s, int c);
char	*ft_strcjoin(char const *s, char const c);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strrev(char *str);
char	*ft_strsub(char const *s, unsigned int start, size_t len);

void	ft_putchar(char c);
void	ft_putnstr(char *s, int n);
void	ft_putstr(char const *s);
void	ft_strclr(char *s);
void	*ft_strnew(size_t size);

#endif
