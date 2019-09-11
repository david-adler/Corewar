/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <ibaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:42:11 by ibaran            #+#    #+#             */
/*   Updated: 2019/09/06 13:14:20 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <string.h>
# include <libc.h>
# include "ft_printf.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *str, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *ptr, int value, size_t n);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *ptr, int value);
char				*ft_strrchr(const char *ptr, int value);
char				*ft_strstr(const char *str1, const char *str2);
char				*ft_strnstr(const char *str1, const char *str2, size_t len);
int					ft_strcmp(const char *ptr1, const char *ptr2);
int					ft_strncmp(const char *ptr1, const char *ptr2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memalloc(size_t size);
void				*ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(long long n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_sqrt(int nb);
int					ft_power(int num, int pow);
void				ft_printwordtab(char **array);
t_list				*ft_strsplitlst(char const *s, char c);
t_list				*ft_lstfold(t_list *first, t_list *(*f)(t_list*, t_list*));
char				*ft_ctoa(char c);
char				*ft_nctoa(char c, size_t n);
long long			ft_abs(long long a);
char				*ft_itoa_base(__int128_t nbr, unsigned short base);
char				*ft_strtolower(char *s);
char				*ft_strtoupper(char *s);
char				*ft_ftoa(long double nbr, int precision);
size_t				ft_sumstrstr(const char *str1, const char *str2);
long long			ft_max(long long a, long long b);
long long			ft_min(long long a, long long b);
char				*ft_strcpy_zero(char *dest, const char *src);
char				*ft_strncpy_zero(char *dest, const char *src, size_t n);
char				*ft_strndup(const char *src, size_t n);
void				ft_printinttab(int **array, size_t size);
int					ft_atoi_base(const char *str, size_t base);
int					ft_strisnum(char *str);
int					ft_strisnum_asm(char *str);
void				ft_swap(long long *a, long long *b);
void				ft_freewordtab(char **pointer);
char				*ft_strjoinfree(char *s1, char *s2, int n);
void				ft_fillstr(char *str, char c, size_t n);
__int128_t			ft_atoint128(const char *str);

char				*ft_write_buff(char *line, int *i);
char				*ft_lltoa_base(long long n, int base);
char				*ft_un_lltoa_base(unsigned long long n, int base);
char				*ft_strndupfree(const char *s, size_t n);

int					ft_isnum(char *str);

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
int					get_next_line(const int fd, char **line);

#endif
