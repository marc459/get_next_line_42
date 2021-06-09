/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line60.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:12:08 by msantos-          #+#    #+#             */
/*   Updated: 2021/06/09 18:12:53 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE60_H
# define GET_NEXT_LINE60_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# define BUFFER_SIZE 1

int		get_next_line(char **line);
char	*ft_strjoint(char *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
#endif
