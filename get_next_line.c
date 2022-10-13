/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:35:54 by alaparic          #+#    #+#             */
/*   Updated: 2022/10/13 18:38:12 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	int				i;

	i = 0;
	if (!buffer[i])
		read(fd, buffer, BUFFER_SIZE);
	while (buffer[i] != '\n')
	{
		if (!buffer[i]){
			read(fd, buffer, BUFFER_SIZE);
			i = 0;
		}
		i++;
		
	}

	return (buffer);
}

int	main(void)
{
	int	file;
	file = open("test.txt", O_RDONLY);
	for (int i = 0; i< 3; i++)
		printf("%s", get_next_line(file));
	return (0);
}
