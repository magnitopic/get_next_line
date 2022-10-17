/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:35:54 by alaparic          #+#    #+#             */
/*   Updated: 2022/10/17 14:28:54 by alaparic         ###   ########.fr       */
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
	new_str = calloc((BUFFER_SIZE + len + 1), sizeof(char));
	while (len != 0)
	{
		new_str[len - 1] = str[len - 1];
		len--;
	}
	free(str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static int		i;
	int				j;
	char			*str;
	int				len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	j = 0;
	str = calloc((BUFFER_SIZE + 1), sizeof(char));
	while (1)
	{
		if (!buffer[i])
		{
			len = read(fd, buffer, BUFFER_SIZE);
			i = 0;
			str = expand_str(str);
		}
		if (len > 0)
			str[j] = buffer[i];
		if (buffer[i] == '\n' || len == 0)
			break ;
		j++;
		i++;
	}
	i++;
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
