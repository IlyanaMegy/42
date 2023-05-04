/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:37:05 by ilymegy           #+#    #+#             */
/*   Updated: 2023/05/02 11:37:15 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <assert.h>
# include <ctype.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//		Partie 1 - Fonctions de la libc
int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
void				ft_bzero(void *s, size_t size);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);

void				*ft_memchr(const void *s, int c, size_t size);
int					ft_memcmp(const void *p1, const void *p2, size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t size);
void				*ft_memmove(void *dst, const void *src, size_t size);
void				*ft_memset(void *pointer, int value, size_t count);

char				*ft_strchr(const char *string, int searchedChar);
char				*ft_strdup(char *src);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
int					ft_strncmp(char *s1, char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *lil, size_t len);
char				*ft_strrchr(const char *string, int searchedChar);

int					ft_tolower(int c);
int					ft_toupper(int c);

//		Partie 2 - Fonctions supplémentaires
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

//		Partie bonus
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
#endif