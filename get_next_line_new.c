/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikondrat <ikondrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:08:35 by ikondrat          #+#    #+#             */
/*   Updated: 2024/09/28 21:16:11 by ikondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *ft_free(char *str)
{
	if (str)
	{
		free (str);
		str = NULL;
	}
	return (NULL);
}

char	*check_last_line(char *out)
{
	if (!out)
		return (NULL);
	if (ft_strlen(out) == 0)
	{
		ft_free(out);
		return (NULL);
	}
	return (out);
}

char	*small_line(char **line)
{
	size_t	i;
	char	*left;
	char	*out;
	
	if (!line || !(*line))
		return (NULL);
	i = 0;
	while ((*line)[i] != '\n' && (*line)[i])
		i++;
	if ((*line)[i] == '\n')
	{
		out = ft_substr(*line, 0, i + 1);
		if (!out)
			return(ft_free(*line));
		left = ft_strdup(*line + i + 1);
		if (!left)
			return(ft_free(*line));
		free(*line);
		*line = left;
		return(check_last_line(out));
	}
	out = ft_strdup(*line);
	free(*line);
	*line = NULL;
	return(check_last_line(out));
}

char	*big_line(int fd, char *buffer)
{
	ssize_t		to_read;
	static char	*line;
	char		*aux;

	to_read = 1;
	while(to_read > 0)
	{
		to_read = read(fd, buffer, BUFFER_SIZE);
		if (to_read == -1)
			return(ft_free(buffer));
		buffer[to_read] = '\0';
		if (!line)
			line = ft_strdup("");
		aux = ft_strjoin(line, buffer);
		free (line);
		line = aux;
		if (ft_strchr(line, '\n') || to_read == 0)
			break ;
	}
	free(buffer);
	return (small_line(&line));
}

char	*get_next_line(int fd)
{
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return(NULL);
	return (big_line(fd, buffer));
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("hola3.txt", O_RDONLY);
// 	line = get_next_line(fd);
	
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free (line);
// 		line = get_next_line(fd);
// 	}
// 	close (fd);
// }
