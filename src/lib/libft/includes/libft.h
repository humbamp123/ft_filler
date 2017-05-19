/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 11:21:43 by apineda           #+#    #+#             */
/*   Updated: 2017/05/12 00:10:16 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>
# include "libprintf.h"

# define G "\033[32;1m"
# define Y "\033[33;1m"
# define R "\033[31;1m"
# define B "\033[34;1m"
# define W "\033[0m"

# ifndef ERRS
#  define ERR(a, b) if(a){return(b);}
#  define ERR1(a, b, c) if(a){b;return(c);}
#  define ERR2(a, b, c, d) if(a){b;c;return(d);}
#  define ERR3(a, b, c, d, e) if(a){b;c;d;return(e);}
#  define ERR4(a, b, c, d, e, f) if(a){b;c;d;e;return(f);}
# endif

# ifndef ERWS
#  define ERW(a,b,c) if(a){ft_putendl(c); return(b);}
#  define ERW1(a,b,c,d) if(a){b;ft_putendl(d);return(c);}
#  define ERW2(a,b,c,d,e) if(a){b;c;ft_putendl(e);return(d);}
#  define ERW3(a,b,c,d,e,f) if(a){b;c;d;ft_putendl(f);return(e);}
#  define ERW4(a,b,c,d,e,f,g) if(a){b;c;d;e;ft_putendl(g);return(f);}
# endif

# define HEX "0123456789abcdef"
# define BUFF_SIZE 40

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
**Part 1
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *tiny, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
**Part 2
*/

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(intmax_t n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_nbrlen(intmax_t num);
char				*ft_itoa_base(uintmax_t nbr, short base);

/*
**Bonus
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_isspace(char const *str);
int					ft_front_white(char const *str);
int					ft_back_white(char const *str);
int					ft_absval(int num);
int					ft_isupper(int c);
int					ft_islower(int c);
int					get_next_line(const int fd, char **line);
void				ft_arraydel(char **as);

#endif
