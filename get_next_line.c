/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:35:54 by alaparic          #+#    #+#             */
/*   Updated: 2022/11/09 18:39:08 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join_buffer(char *buffer, char *new_str)
{
	char	*aux;

	if (!new_str)
		aux = NULL;
	else
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
		aux = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!aux)
			return (NULL);
		len = read(fd, aux, BUFFER_SIZE);
		buffer = join_buffer(buffer, aux);
		if (ft_strchr(aux, '\n') != NULL)
			len = 0;
		free(aux);
	}
	return (buffer);
}

static char	*copy_to_str(char *buffer)
{
	char	*str;
	int		i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	i++;
	while (i-- != 0)
		str[i] = buffer[i];
	return (str);
}

static char	*set_buffer(char *buffer)
{
	char	*aux;
	char	*str;
	int		i;

	aux = ft_memchr(buffer, '\n', ft_strlen(buffer));
	if (!aux)
	{
		free(buffer);
		return (NULL);
	}
	aux++;
	str = ft_calloc(ft_strlen(aux) + 1, sizeof(char));
	i = -1;
	while (i++ < (int) ft_strlen(str))
		str[i] = aux[i];
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_line(fd, buffer);
	if (!*buffer)
		return (NULL);
	str = copy_to_str(buffer);
	buffer = set_buffer(buffer);
	return (str);
}

/* int	main(void)
{
	int	file;
	file = open("test.txt", O_RDONLY);
	for (int i = 0; i < 3; i++){
		char *cozas = get_next_line(file);
		printf("%s", cozas);
		free(cozas);
	}
	return (0);
} */
