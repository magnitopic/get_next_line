/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:35:54 by alaparic          #+#    #+#             */
/*   Updated: 2022/10/19 10:41:17 by alaparic         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		a;
	int		b;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	i = 0;
	str = malloc(a + b + 1);
	if (!str)
		return (NULL);
	while (a--)
	{
		str[i] = s1[i];
		i++;
	}
	a = i;
	i = 0;
	while (b--)
		str[a++] = s2[i++];
	str[a] = '\0';
	return (str);
}

static int	expand_buffer(int fd, char *buffer)
{
	char	*aux;
	int		len;
	int		i;

	aux = buffer;
	buffer = (char *) malloc(BUFFER_SIZE * sizeof(char));
	len = read(fd, aux, BUFFER_SIZE);
	i = len;
	while (i--)
		buffer[i] = aux[i];
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
	static char		buffer[BUFFER_SIZE];
	static int		i;
	int				j;
	char			*str;
	int				len;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	if (!buffer[i])
	{
		len = expand_buffer(fd, buffer);
		i = 0;
	}
	j = 0;
	str = calloc((BUFFER_SIZE + 1), sizeof(char));
	while (buffer[i] != '\n' && len != 0)
	{
		if (!buffer[i])
		{
			len = expand_buffer(fd, buffer);
			/* if (len == 0)
			{
				free(buffer);
				break ;
			} */
			i = 0;
			str = expand_str(str);
		}
		str[j] = buffer[i];
		j++;
		i++;
	}
	str[j] = buffer[i];
	//printf("%d",buffer[i]);
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
