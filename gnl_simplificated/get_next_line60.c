/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line60.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:35:59 by marcos            #+#    #+#             */
/*   Updated: 2021/06/09 18:18:19 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line60.h"

char	*ft_strjoint(char *s, char c)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(ft_strlen(s) + 2);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = c;
	dest[i + 1] = '\0';
	free(s);
	return (dest);
}

int	get_next_line(char **line)
{
	int		ret;
	char	buf[2];

	*line = ft_strdup("");
	if (line == NULL || !*line)
		return (-1);
	ret = read(0, buf, 1);
	while (ret > 0)
	{
		if (buf[0] == '\n')
			break ;
		*line = ft_strjoint(*line, buf[0]);
		ret = read(0, buf, 1);
	}
	return (ret);
}

