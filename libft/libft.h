/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 22:07:15 by pbourlet          #+#    #+#             */
/*   Updated: 2017/02/22 16:57:56 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

int					ft_atoi(const char *str);
int					ft_atoibase(const char *str, int base);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_toupper(int c);
int					ft_nblen(int nb);

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_strclr(char *s);
void				*ft_strnew(size_t size);

char				*ft_strchr(char *s, int c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcjoin(char const *s1, char const s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_itoa(int n);
char				*ft_strrev(char *str);

size_t				ft_strlen(const char *s);

#endif
