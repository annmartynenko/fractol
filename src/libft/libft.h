/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:00:13 by amartyne          #+#    #+#             */
/*   Updated: 2018/04/13 13:23:38 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE  1
# define LOW 0
# define UP 1
# define P 2
# define UNCO 3
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dst, const char *src);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *restrict dst, const void *restrict src, \
size_t n);
void				*ft_memccpy(void *restrict dst, const void *restrict src, \
int c, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memmove(void *dst, const void *src, size_t len);
size_t				ft_strlcat(char *restrict dst, const char *restrict src, \
size_t dstsize);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char*s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const*s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int i);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_swap(int *a, int *b);
void				ft_foreach(int *tab, int length, void (*f)(int));
int					ft_sqrt(int nb);
int					*ft_range(int min, int max);
int					ft_power(int nb, int power);
void				ft_arrfree(char **s);
void				ft_lstaddback(t_list *alst, t_list *new);
int					get_next_line(const int fd, char **line);

typedef struct		s_struct
{
	char			plus;
	char			minus;
	char			space;
	char			hash;
	char			nul;
	int				width;
	int				precision;
	char			sp;
}					t_struct;
int					ft_putchar_pr(char c);
int					ft_putstr_pr(char const *s);
void				ft_putnbr_pr(int n, int *len_res);
void				n_time(int i, int *len_res, char str);
int					ft_itoa_base_pr(long long int n, int base, int letter,\
t_struct flags);
void				word(char format, va_list ap, t_struct flags, int *len_res);
void				number(char format, va_list ap, t_struct flags,\
int *len_res);
int					ft_printf(char *format, ...);
int					count_bin(unsigned int numb);
void				unicode(wchar_t numb, t_struct flags, int mark,\
int *len_res);
void				ft_putunslnbr(unsigned long int n, t_struct flags,\
int *len_res);
void				uni_str(wchar_t *arr, t_struct flags, int *len_res);
void				ft_putlnbr(long long int n, t_struct flags, int *len_res);
int					convert(char format, va_list ap, t_struct flags);
t_struct			find_flag(char *str, int *i, va_list ap);
int					a_len(long long int n, int base, int len, long long *j);
void				if_flags(t_struct flags, int len, int *len_res);
void				next_fl(char *str, int *i, t_struct *flags);
int					if_flags_ito(t_struct flags, int len, int base, int letter);
void				for_minus(t_struct flags, int len, int base, int *len_res);
int					len_unco(int size);
void				ft_putstring(char const *s, t_struct flags, int *len_res);
void				ft_putnumber(long long int n, t_struct flags, int *len_res);
int					specifier(char *format, int *i, va_list ap, t_struct flags);
int					valid(char format);
void				not_spec(t_struct flags, int *len_res);
int					ft_itoa_base_int(unsigned int n, unsigned int base,\
int letter, t_struct flags);
int					ft_itoa_unslong(unsigned long n, unsigned long base,\
int letter, t_struct flags);
int					ft_itoa_max(uintmax_t n, uintmax_t base, int letter,\
t_struct flags);
void				ft_putmax(intmax_t n, t_struct flags, int *len_res);
t_struct			if_flags_d(t_struct flags, int *len, int *len_res);
void				ft_putschar(int n, t_struct flags, int *len_res);
void				for_h(char format, va_list ap, t_struct flags,\
int *len_res);
void				for_l(char format, va_list ap, t_struct flags,\
int *len_res);
void				for_ll(char format, va_list ap, t_struct flags,\
int *len_res);
void				for_hh(char format, va_list ap, t_struct flags,\
int *len_res);
void				ft_putwchr(wchar_t *s, t_struct flags, int *len_res);
int					for_p(t_struct flags, int len);
int					print_space(t_struct flags, int len, int base, int letter);
int					print_nul(t_struct flags, int len, int base, int letter);
int					print_nul_pr(t_struct flags, int len, int base, int letter);
int					specifier_j(char *format, int *i, va_list ap,\
t_struct flags);
void				ft_arrfree_int(int **s);

#endif
