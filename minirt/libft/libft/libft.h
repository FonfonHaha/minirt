/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:11:10 by pcoureau          #+#    #+#             */
/*   Updated: 2019/10/21 14:43:31 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>

int     		ft_puis(int n, int m);
int				ft_strlen(const char *str);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *str, const char *n, size_t len);
int				ft_atoi(const char *str);
float			ft_atof(const char *str);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			ft_bzero(void *str, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdupnos(const char *s1);
char			*ft_strcpynos(char *dest, const char *src);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *str, char c);
void    		*ft_deltab(char **tab);
char			**ft_splitnos(char const *str, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));
void			ft_print_lst(t_list *l);
void			ft_putnbr_base_fd(int nbr, char *base, int fd);
void			ft_putnbrunsint_fd(unsigned int nb, int fd);
void			ft_putptr_fd(unsigned long nbr, char *base, int fd);
int				ft_checkbase(char *base);typedef	struct	s_ftprintf
{
	char		*str_final;
	char		*tmp;
	char		*s;
	void		*arg_content;
	int			l_align;
	int			star;
	int			star_activ;
	int			zero;
	int			zero_activ;
	int			dot;
	int			dot_activ;
	int			neg;
	int			strlenfinal;
	int			len;
}				t_ftprintf;
char			*ft_joina(char *tampostr, char *tampospace, t_ftprintf *mas);
void			*ft_nn(char *ts, t_ftprintf *mas, int len, unsigned long pnum);
void			ft_printd_m(t_ftprintf *mas);
void			ft_printd_dot(int i, t_ftprintf *mas);
void			ft_printd_tmps(char *tampostr, t_ftprintf *mas);
void			ft_printd_star(int i, t_ftprintf *mas);
void			*ft_convp(va_list av, t_ftprintf *mas);
void			*ft_convc(va_list av, t_ftprintf *mas);
void			*ft_convs(va_list av, t_ftprintf *mas);
void			*ft_convu(va_list av, t_ftprintf *mas);
void			*ft_convd(va_list av, t_ftprintf *mas);
void			*ft_convx(va_list av, t_ftprintf *mas);
void			*ft_convxx(va_list av, t_ftprintf *mas);
void			*ft_convprc(t_ftprintf *mas);
int				ft_printf(const char *str, ...);
char			*ft_itoad(int n);
char			*ft_itoau(unsigned int n);
char			*ft_itoax(unsigned int n, char *base);
int				ft_flagalign(t_ftprintf *mas, const char *str, int n);
int				ft_flagzero(t_ftprintf *mas, const char *str, int n);
int				ft_flagwn(t_ftprintf *mas, const char *str, int n);
int				ft_flagws(va_list av, t_ftprintf *mas, const char *str, int n);
int				ft_flagdot(va_list av, t_ftprintf *mas, const char *str, int n);
int				ft_chkflgs(va_list av, t_ftprintf *mas, const char *str, int n);
void			*ft_cnvrt(va_list av, t_ftprintf *mas, const char *str, int n);
void			*ft_getstr(const char *str, t_ftprintf *mas, va_list av);
char			*ft_itoap(unsigned long n, char *base);int		ft_switch(char **s, char **tmp);
void	ft_advance(char *buff, int i);
int		ft_rline(char **line, char *s, char *buff, int i);
int		ft_end(char **line, char *s, int err);
int		get_next_line(int fd, char **line);
int		get_next_line_two(int fd, char **line);
int		ft_strlengnl(char const *s);
char	*ft_strdupgnl(const char *s);
char	*ft_strdcpy(const char *s);
int		ft_strchrbn(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);


#endif
