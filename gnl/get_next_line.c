/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 19:10:08 by Wjena             #+#    #+#             */
/*   Updated: 2020/07/17 16:19:14 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_expand(char *str, int size)
{
	char	*n_str;
	int		i;

	i = 0;
	if (!(n_str = (char*)ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	while (str[i] != 0)
	{
		n_str[i] = str[i];
		i++;
	}
	free(str);
	return (n_str);
}

void	ft_read(char *tmp_line, char **last_line, int **i, char **drop)
{
	int		k;
	char	*ptr;

	k = 0;
	while (tmp_line[k] != '\0')
	{
		if (tmp_line[k] == '\n')
			break ;
		if ((*i)[0] >= (*i)[2])
			*last_line = ft_expand(*last_line, ((*i)[2] += BUFFER_SIZE));
		(*last_line)[(*i)[0]] = tmp_line[k];
		(*i)[0] += 1;
		k++;
	}
	if ((ptr = ft_strchr(tmp_line, '\n')))
	{
		ptr++;
		*drop = ptr;
	}
}

int		ft_drop_ex(char **drop, int **i, char **last_line, char **line)
{
	if (*drop)
	{
		if (ft_strchr(*drop, '\n'))
		{
			while ((*drop)[(*i)[0]] != '\n')
			{
				(*last_line)[(*i)[0]] = (*drop)[(*i)[0]];
				(*i)[0] += 1;
			}
			*drop = *drop + (*i)[0] + 1;
			*line = ft_strdup(*last_line);
			free(*last_line);
			free(*i);
			return (1);
		}
		while ((*drop)[(*i)[0]] != '\0')
		{
			(*last_line)[(*i)[0]] = (*drop)[(*i)[0]];
			(*i)[0] += 1;
		}
		ft_bzero(*drop, (*i)[0]);
	}
	return (0);
}

int		ft_davai(int *i, char **tmp_line, char **last_line, char **drop)
{
	int	size;

	while ((i[1] = read(i[3], *tmp_line, BUFFER_SIZE)) > 0)
	{
		ft_read(*tmp_line, *&last_line, &i, *&drop);
		if (ft_strchr(*tmp_line, '\n'))
			break ;
		ft_bzero(*tmp_line, BUFFER_SIZE);
	}
	size = i[1];
	free(i);
	if (size < 1)
	{
		free(*tmp_line);
		*tmp_line = NULL;
	}
	return (size);
}

int		get_next_line(int fd, char **line)
{
	char		*last_line;
	static char *tmp_line;
	int			*i;
	static char	*drop;
	int			m;

	if (!tmp_line)
		tmp_line = (char *)ft_calloc(1, BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, tmp_line, 0) < 0
		|| !(i = ft_calloc(sizeof(int), 4))
		|| !(last_line = ft_calloc(1, BUFFER_SIZE)))
		return (ft_free(&tmp_line, &i, &last_line, fd));
	i[0] = 0;
	i[2] = BUFFER_SIZE;
	i[3] = fd;
	if (ft_drop_ex(&drop, &i, &last_line, line))
		return (1);
	ft_bzero(tmp_line, BUFFER_SIZE);
	m = ft_davai(i, &tmp_line, &last_line, &drop);
	*line = ft_strdup(last_line);
	free(last_line);
	return (m == 0 ? 0 : 1);
}
