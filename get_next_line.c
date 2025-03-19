/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bou <iait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 02:35:49 by iait-bou          #+#    #+#             */
/*   Updated: 2024/03/11 17:34:51 by iait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_line(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_line(char *str)
{
	size_t	i;
	char	*str1;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	str1 = malloc((i + 1) * sizeof(char));
	ft_memcpy(str1, str, i);
	str1[i] = '\0';
	return (str1);
}

static char	*chek_rest(char *str)
{
	size_t	i;
	size_t	b;
	size_t	j;
	char	*str2;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	b = ft_strlen(str) - i;
	str2 = malloc((b + 1) * sizeof(char));
	i++;
	while (j < b)
	{
		str2[j++] = str[i++];
	}
	str2[b] = '\0';
	return (str2);
}

static char	*ft_read_line(int fd, char *tr)
{
	char	*str;
	char	*buf;
	ssize_t	p;

	p = 1;
	buf = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (p > 0 && check_line(tr) != 1)
	{
		p = read(fd, buf, BUFFER_SIZE);
		if (p > 0)
		{
			buf[p] = '\0';
			str = ft_strjoin(tr, buf);
			free(tr);
			tr = str;
		}
	}
	free(buf);
	if (p == -1)
		return (free(tr), NULL);
	return (tr);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*readed;
	char		*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readed = (ft_read_line(fd, readed));
	if (readed == NULL || readed[0] == '\0')
	{
		free(readed);
		readed = NULL;
		return (NULL);
	}
	line = ft_line(readed);
	ptr = chek_rest(readed);
	free(readed);
	readed = ptr;
	return (line);
}
/*
 int	main(void)
 {
		int		fd;
		char	*s;

		fd = open("hello.txt", O_RDONLY);
		while (s != NULL)
		{
			s = get_next_line(fd);
			printf("%s\n", s);
			free(s);
		}
		system("leaks a.out");
 }*/
