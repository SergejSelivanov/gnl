/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:32:32 by Wjena             #+#    #+#             */
/*   Updated: 2020/07/09 18:33:07 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *str, int ch);
char	*ft_expand(char *str, int size);
int		ft_drop_ex(char **drop, int **i, char **last_line, char **line);
void	ft_read(char *tmp_line, char **last_line, int **i, char **drop);
int		ft_davai(int *i, char **tmp_line, char **last_line, char **drop);
int		ft_free(char **tmp_line, int **i, char **last_line, int fd);

#endif
