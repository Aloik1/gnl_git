/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:04:35 by juanherr          #+#    #+#             */
/*   Updated: 2024/09/28 00:22:17 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

static char	*final_line(char *out)
{
	if (ft_strlen(out) == 0)
	{
		free(out);
		return (NULL);
	}
	else
		return (out);
}

static char	*output(char **line)
{
	char	*left;
	char	*out;
	int		i;

	i = 0;
	if (*line == NULL)
		return (NULL);
	while ((*line)[i] != '\n' && (*line)[i])
		i++;
	if ((*line)[i] == '\n')
	{
		out = ft_substr(*line, 0, i + 1);
		left = ft_strdup(*line + (i + 1));
		if (!out || !left)
			return (ft_free(line));
		free(*line);
		*line = left;
		return (out);
	}
	out = ft_strdup(*line);
	free(*line);
	*line = NULL;
	return (final_line(out));
}

static char	*find_newline(int to_read, int fd, char *buffer, char **line)
{
	char	*aux;

	while (to_read > 0)
	{
		buffer[to_read] = '\0';
		if (*line == NULL)
			*line = ft_strdup("");
		aux = ft_strjoin(*line, buffer);
		free(*line);
		*line = aux;
		if (ft_strchr(buffer, '\n'))
			break ;
		to_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (output(line));
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*line;
	int			to_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	to_read = read(fd, buffer, BUFFER_SIZE);
	if (to_read < 0)
	{
		free(buffer);
		free(line);
		line = NULL;
		return (NULL);
	}
	return (find_newline(to_read, fd, buffer, &line));
}

// int	main(void)
// {
// 	int	fd;
// 	char *line;
// 	size_t	i = 0;
	
// 	fd = open("hello.txt", O_RDONLY);
// 	line = get_next_line(fd);
	
// 	//ft_putstr_fd(line, 1);
	
// 	//while (i < 3)
// 	//{
// 	//	printf("%s", line);
// 	//	i++;
// 	//	line = get_next_line(fd);
// 	//}
	
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free (line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }
