/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:35:54 by alaparic          #+#    #+#             */
/*   Updated: 2022/11/01 16:42:51 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join_buffer(char *buffer, char *new_str)
{
	char	*aux;

	aux = ft_strjoin(buffer, new_str);
	free(buffer);
	return (aux);
}

static char	*read_line(int fd, char *buffer)
{
	char	*aux;
	int		len;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	len = 1;
	while (len != 0)
	{
		aux = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		len = read(fd, aux, BUFFER_SIZE);
		buffer = join_buffer(buffer, aux);
		if (ft_strchr(aux, '\n') != NULL)
			break ;
	}
	free(aux);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	/* char			*str; */

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	buffer = read_line(fd, buffer);
	printf("%s", buffer);
	return (NULL);
}

int	main(void)
{
	int	file;
	file = open("test.txt", O_RDONLY);
	for (int i = 0; i < 1; i++)
		//printf("%s", get_next_line(file));
		get_next_line(file);
	return (0);
}
