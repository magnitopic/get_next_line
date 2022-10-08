/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:35:54 by alaparic          #+#    #+#             */
/*   Updated: 2022/10/08 18:16:23 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			buffer[2048];
	int				bytes;
	static int		i = 0;
	int				j;
	char			*str;

	j = 0;
	str = malloc((100) * sizeof(char));
	bytes = read(fd, buffer, 2048);
	while (buffer[i] != '\n') // todo: add cheeker to eof
	{
		str[j] = buffer[i];
		printf("%c", buffer[i]);
		i++;
		j++;
	}
	if (buffer[i] == '\n')
		str[j++] = buffer[i++];
	return (str);
}

int	main(void)
{
	int	file;

	file = open("test.txt", O_RDONLY);
	for (int i = 0; i< 2; i++)
	{
		printf("\nText: %s", get_next_line(file));
		printf("\n");
	}
	return (0);
}
