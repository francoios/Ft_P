/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:29:04 by frcugy            #+#    #+#             */
/*   Updated: 2015/10/29 14:27:00 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 1
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# define C_NONE         "\033[0m"
# define C_BOLD         "\033[1m"
# define C_BLACK        "\033[30m"
# define C_RED          "\033[31m"
# define C_GREEN        "\033[32m"
# define C_BROWN        "\033[33m"
# define C_BLUE         "\033[34m"
# define C_MAGENTA      "\033[35m"
# define C_CYAN         "\033[36m"
# define C_GRAY         "\033[37m"

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_fd
{
	int					fd;
	char				*original_ptr;
	char				*current_ptr;
	struct s_fd			**begin;
	struct s_fd			*next;
	struct s_fd			*prev;
}						t_fd;

int						get_next_line(int const fd, char **line);
size_t					ft_strlen(const char *str);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
char					*ft_strdup(const char *s1);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t n);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *s1, const char *s2);
char					*ft_strnstr(const char *s1, const char *s2, size_t n);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strclr(char *s);
void					ft_strdel(char **as);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
	char (*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start,
	size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
int						ft_isspace(int c);
char					**ft_strsplit(char const *s, char c);
char					*ft_strtrim(char const *s);
char					*ft_itoa(int n);
void					ft_putstr(char const *str);
void					ft_putstr_fd(char const *str, int fd);
void					ft_putchar_fd(char c, int fd);
void					ft_putchar(char c);
void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);
int						ft_atoi(const char *str);
void					*ft_memccpy(void *dst, const void *src, int c,
	size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					ft_putendl(char const *s);
void					ft_putendl_fd(char const *s, int fd);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
int						ft_tolower(int c);
int						ft_isxdigit(int c);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_putnbr_base(int nb, char *base);
void					ft_unsigned_putnbr(unsigned int n);
int						tab_lenght(char **tab);
char					**ft_tab_cpy(char **tab);
void					ft_tab_read(char **tab);
char					*ft_strndup(char *str, int n);
char					**ft_split_whitespaces(char *str);

#endif
