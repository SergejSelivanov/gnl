/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:51:42 by Wjena             #+#    #+#             */
/*   Updated: 2020/07/14 18:51:49 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char		*t;
	int			i;
	int			m;

	m = 0;
	i = 0;
	while (s1[m] != '\0')
	{
		m++;
	}
	t = (char*)malloc((m + 1) * sizeof(char));
	if (t == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		t[i] = s1[i];
		i++;
	}
	t[i] = '\0';
	return ((char*)t);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	if (!s)
		return ;
	str = s;
	while (n > 0 && str)
	{
		*str = '\0';
		str++;
		n--;
	}
}

int		ft_free(char **tmp_line, int **i, char **last_line, int fd)
{
	if (*tmp_line == NULL)
	{
		if (*i != NULL)
			free(*i);
		if (*last_line != NULL)
			free(*last_line);
		return (-1);
	}
	else if (read(fd, *tmp_line, 0) < 0)
	{
		free(*tmp_line);
		return (-1);
	}
	else if (*i == NULL)
	{
		free(*tmp_line);
		return (-1);
	}
	else if (*last_line == NULL)
	{
		free(*i);
		free(*tmp_line);
		return (-1);
	}
	return (-1);
}

char	*ft_strchr(const char *str, int ch)
{
	int i;
	int m;

	i = 0;
	m = 0;
	while (str[m] != '\0')
	{
		m++;
	}
	if (ch == '\0')
		return ((char *)str + m);
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

void	*ft_calloc(size_t num, size_t size)
{
	void *arr;

	arr = malloc(num * (size + 1));
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, num * (size + 1));
	return (arr);
}
