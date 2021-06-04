/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:49:49 by msantos-          #+#    #+#             */
/*   Updated: 2020/01/18 18:44:03 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen2(const char *str)
{
	int size;

	size = 0;
	while (str[size] != '\0' && str[size] != '\n')
	{
		size += 1;
	}
	return (size);
}

void	armageddon(char **str)
{
	free(*str);
    *str = NULL;
}

int		appendline(char **stat, char **line, int fd)
{
	char	*str;
	int		len;

	len = ft_strlen2(stat[fd]);
	*line = ft_substr(stat[fd], 0, len);
	str = ft_strdup(&stat[fd][len + 1]);
	free(stat[fd]);
	stat[fd] = str;
	return (1);
}

int		output(int bytes, char **stat, char **line, int fd)
{
	if (bytes < 0)
		return (-1);
	else if (bytes == 0 && (stat[fd] == NULL || stat[fd][0] == '\0'))
	{
		*line = ft_strdup("");
		armageddon(&stat[fd]);
		return (0);
	}
	else if (ft_strchr(stat[fd], '\n'))
	{
		return (appendline(stat, line, fd));
	}
	else
	{
		*line = ft_strdup(stat[fd]);
		armageddon(&stat[fd]);
		return (0);
	}
}

int		get_next_line(int fd, char **line)
{
	int			bytes;
	char		*buff;
	char		*tmp;
	static char *stat[4096];

	if (fd == -1 || line == NULL || BUFFER_SIZE < 1 ||
	!(buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while ((bytes = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		if (stat[fd])
		{
			tmp = ft_strjoin(stat[fd], buff);
			free(stat[fd]);
			stat[fd] = tmp;
		}
		else
			stat[fd] = ft_strdup(buff);
		if (ft_strchr(stat[fd], '\n'))
			break ;
	}
	free(buff);
	return (output(bytes, stat, line, fd));
}
