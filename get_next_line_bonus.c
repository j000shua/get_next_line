/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:10:45 by jlinguet          #+#    #+#             */
/*   Updated: 2024/01/30 18:01:54 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	set_up(char *buf, char **line)
{
	char	*end;
	size_t	i;
	size_t	j;

	*line = NULL;
	end = ft_strchr(buf, '\n');
	if (!end)
		return (1);
	i = 0;
	while (&buf[i] != end)
		i++;
	*line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (0);
	ft_strlcpy(*line, buf, i + 2);
	j = 0;
	while (++i < BUFFER_SIZE && buf[i])
		buf[j++] = buf[i];
	buf[j] = '\0';
	return (1);
}

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	if (!s)
		return (NULL);
	p = s;
	while (n)
	{
		*p = 0;
		n--;
		p++;
	}
	return (s);
}

int	reading(size_t *nbr, int *fd, char *buf, char **line)
{
	while (*nbr && !ft_strchr(buf, '\n'))
	{
		buf[*nbr] = '\0';
		*line = ft_strjoin(*line, buf);
		if (!line)
			return (0);
		*nbr = read(*fd, buf, BUFFER_SIZE);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buf[1024][BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;
	size_t		nbr;

	if (read(fd, buf[fd], 0) < 0 || !set_up(buf[fd], &line))
		return (NULL);
	if (line)
		return (line);
	line = ft_strdup(buf[fd]);
	if (!line)
		return (NULL);
	nbr = read(fd, buf[fd], BUFFER_SIZE);
	if (!reading(&nbr, &fd, buf[fd], &line))
		return (NULL);
	if (!nbr && buf[fd][0])
		return (ft_bzero(buf[fd], 1), line);
	if (!nbr)
		return (free(line), NULL);
	buf[fd][nbr] = 0;
	if (!set_up(buf[fd], &tmp))
		return (NULL);
	line = ft_strjoin(line, tmp);
	return (free(tmp), line);
}
