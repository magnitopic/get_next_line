/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:35:54 by alaparic          #+#    #+#             */
/*   Updated: 2022/10/14 18:28:43 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static char	*expand_str(char *str)
{
	char	*new_str;
	int		len;

	len = ft_strlen(str);
	new_str = malloc((BUFFER_SIZE + len) * sizeof(char));
	while (len != 0)
	{
		new_str[len - 1] = str[len - 1];
		len--;
	}
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	int				i;
	int				j;
	char			*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = calloc(BUFFER_SIZE, sizeof(char));
	i = 0;
	j = 0;
	if (!buffer[i])
		read(fd, buffer, BUFFER_SIZE);
	while (buffer[i] != '\n') //todo: vover el puntero del buffer hasta el \n
	{
		if (!buffer[i])
		{
			read(fd, buffer, BUFFER_SIZE);
			str = expand_str(str);
			i = 0;
		}
		str[j] = buffer[i];
		i++;
		j++;
	}
	//printf("%zu",ft_strlen(str));
	return (str);
}

int	main(void)
{
	int	file;
	file = open("test.txt", O_RDONLY);
	for (int i = 0; i< 1; i++)
		printf("\n%s", get_next_line(file));
		//get_next_line(file);
	return (0);
}
