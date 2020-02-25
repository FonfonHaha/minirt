/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:52:53 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/14 02:29:05 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

int		ft_switch(char **s, char **tmp);
void	ft_advance(char *buff, int i);
int		ft_rline(char **line, char *s, char *buff, int i);
int		ft_end(char **line, char *s, int err);
int		get_next_line(int fd, char **line);
int		ft_strlengnl(char const *s);
char	*ft_strdupgnl(const char *s);
char	*ft_strdcpy(const char *s);
int		ft_strchrbn(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
