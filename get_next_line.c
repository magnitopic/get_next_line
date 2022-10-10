/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:35:54 by alaparic          #+#    #+#             */
/*   Updated: 2022/10/10 17:20:26 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buffer;
	int				bytes;
	static int		i = 0;
	int				j;
	char			*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	j = 0;
	str = malloc((BUFFER_SIZE) * sizeof(char));
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		printf("");
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
	for (int i = 0; i< 3; i++)
	{
		printf("\nText: %s", get_next_line(file));
		printf("\n");
	}
	return (0);
}
