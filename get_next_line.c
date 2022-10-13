/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:35:54 by alaparic          #+#    #+#             */
/*   Updated: 2022/10/13 20:16:19 by alaparic         ###   ########.fr       */
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

static char	*str_space(char *str)
{
	char	*new_str;
	int		len;

	len = 0;
	if (*str != '\0')
	{
		len = ft_strlen(str);
	}

	new_str = malloc((BUFFER_SIZE + len) * sizeof(char));
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
	str = NULL;
	
	//str = str_space(str);
	i = 0;
	j = 0;
	if (!buffer[i])
		read(fd, buffer, BUFFER_SIZE);
	while (buffer[i] != '\n')
	{
		if (!buffer[i])
		{
			read(fd, buffer, BUFFER_SIZE);
			//str = str_space(str);
			i = 0;
		}
		i++;
	}
	return (str);
}

int	main(void)
{
	int	file;
	file = open("test.txt", O_RDONLY);
	for (int i = 0; i< 3; i++)
		printf("%s", get_next_line(file));
	return (0);
}
