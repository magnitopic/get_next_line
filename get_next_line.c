/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:35:54 by alaparic          #+#    #+#             */
/*   Updated: 2022/10/26 19:39:10 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join_buffer(char *buffer, char *new_str)
{
	
}

static char	*expand_buffer(int fd, char *buffer)
{
	char	*aux;
	int		len;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	aux = calloc((BUFFER_SIZE + 1), sizeof(char));
	len = 1;
	while (len != 0)
	{
		len = read(fd, aux, BUFFER_SIZE);
		aux[len] = '\0';
		buffer = ;
		if (ft_strchr(aux,'\n') != NULL)
			break ;
	}
	aux = "";
	free(buffer);
	buffer = (char *) malloc(BUFFER_SIZE * sizeof(char));
	len = read(fd, aux, BUFFER_SIZE);
	buffer = ft_strjoin(aux, buffer);
	free(aux);
	return (len);
}

static char	*expand_str(char *str)
{
	char	*new_str;
	char	*aux;

	aux = malloc((BUFFER_SIZE + 1) * sizeof(char));
	new_str = ft_strjoin(str, aux);
	free(str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*str;
	int				len;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	buffer=expand_buffer();
	return (str);
}

int	main(void)
{
	int	file;
	file = open("test.txt", O_RDONLY);
	for (int i = 0; i < 3; i++)
		printf("%s", get_next_line(file));
		//get_next_line(file);
	return (0);
}
