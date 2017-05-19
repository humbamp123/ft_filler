/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:19:51 by apineda           #+#    #+#             */
/*   Updated: 2017/05/12 00:09:11 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# include "libft.h"

typedef	struct		s_flags
{
	char			minus;
	char			space;
	char			plus;
	char			pound;
	char			zero;
	char			flgs;
	char			ln_mod;
	int				num;
	int				width;
	int				pres;
	char			in_pres;
	int				cap;
}					t_flags;

typedef	struct		s_print
{
	char			*fin;
	int				save;
	char			*tmp;
	char			*text;
	uintmax_t		var;
	char			neg;
	t_flags			flags;
}					t_print;

int					ft_printf(const char *format, ...);
int					ft_vprintf(const char *format, va_list args);

int					ft_vasprintf(char **ret, const char *fmt, va_list arg);
int					ft_queenies_crazy_write(int fd, char *str, int len);

char				*ft_appendit(t_print *ret, char *str);
char				*ft_appender(char *ret, char *str);
char				*ft_to_upper(char *str);

void				*ft_memalloc(size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
size_t				ft_strlen(const char *s);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s1);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
char				*ft_itoa(intmax_t nbr);
char				*ft_itoa_base(uintmax_t n, short base);
void				ft_strdel(char **as);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strnstr(const char *big, const char *tiny, size_t len);
void				ft_memdel(void **ap);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);

int					ft_printf_c(t_print *ret, const char **fmt, va_list arg);
int					ft_printf_s(t_print *ret, const char **fmt, va_list arg);
int					ft_printf_c_s(t_print *ret, const char **fmt, va_list arg);
int					ft_printf_d(t_print *ret, const char **fmt, va_list arg);
int					ft_printf_p(t_print *ret, const char **fmt, va_list arg);
int					ft_printf_per(t_print *ret, const char **fmt, va_list arg);
int					ft_printf_o(t_print *ret, const char **fmt, va_list arg);
int					ft_printf_u(t_print *ret, const char **fmt, va_list arg);
int					ft_printf_x(t_print *ret, const char **fmt, va_list arg);
int					ft_printf_flg(t_print *ret, const char **fmt, va_list arg);
int					ft_width(t_print *ret, const char **fmt, va_list arg);
int					ft_precision(t_print *ret, const char **fmt, va_list arg);
int					ft_len_mod(t_print *ret, const char **fmt, va_list arg);
int					ft_new_len(t_print *ret, va_list arg);
int					ft_signed(t_print *ret);
char				*ft_wide_char(wchar_t var);

#endif
