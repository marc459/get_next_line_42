/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:29:14 by msantos-          #+#    #+#             */
/*   Updated: 2020/10/03 11:16:19 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	int		i;
	int		fd;
	int		retorno;
	char	*line;
		i = 0;
		fd = open("jajaja.txt", O_RDONLY);
		while ((retorno = get_next_line(fd, &line)) == 1)
		{
			printf("%d - ", retorno);
			printf("%s\n", line);
			free(line);
		}
		printf("%d - ", retorno);
		printf("%s\n", line);
		close(fd);
    system("leaks a.out");
    //getchar();

	return (0);
}
