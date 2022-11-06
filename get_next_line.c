/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:35:54 by alaparic          #+#    #+#             */
/*   Updated: 2022/11/06 13:16:54 by alaparic         ###   ########.fr       */
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
	aux = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (len != 0)
	{
		ft_bzero(aux, BUFFER_SIZE + 1);
		len = read(fd, aux, BUFFER_SIZE);
		buffer = join_buffer(buffer, aux);
		if (ft_strchr(aux, '\n') != NULL)
			break ;
	}
	free(aux);
	return (buffer);
}

static char	*coppy_to_str(char *buffer)
{
	char	*str;
	int		i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	str = ft_calloc(i, sizeof(char));
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
	aux++;
	if (!aux)
	{
		free(buffer);
		return (NULL);
	}
	str = ft_calloc(ft_strlen(aux), sizeof(char));
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
		return (0);
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	str = coppy_to_str(buffer);
	buffer = set_buffer(buffer);
	return (str);
}

int	main(void)
{
	int	file;
	file = open("test.txt", O_RDONLY);
	for (int i = 0; i < 4; i++)
		printf("%s", get_next_line(file));
		//get_next_line(file);
	return (0);
}