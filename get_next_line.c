/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikondrat <ikondrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:31:58 by ikondrat          #+#    #+#             */
/*   Updated: 2024/09/25 19:34:39 by ikondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(n * sizeof(char) + 1);
	if (!dup)
		return (NULL);
	while (s[i] && i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*get_next_line(int fd)
{
	char				*out;
	char				*buffer;
	static char			*resto;
	size_t				to_read;
	size_t				i;
	
	if (fd < 0)	
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!resto)
		to_read = read(fd, buffer, BUFFER_SIZE);
	while (to_read > 0)
	{
		i = 0;
		if (!resto)
		{
			while (buffer[i] != '\n')
				i++;
			out = ft_strndup(buffer, i);
			resto = ft_substr(buffer, i + 1, ft_strlen(buffer) - ft_strlen(out));
			printf("entrando en la primera linea");
			return (out);
		}
		else
		{
			printf("entra en el else");
			i++;
			while (resto[i] != '\n')
				i++;
			out = ft_strjoin(out, resto);
			resto = ft_substr(resto, i + 1, ft_strlen(resto) - ft_strlen(out));
			out = ft_strndup(resto, i);
			return(out);
		}
		i++;
	}
	printf("no entra en el bucle");
	return (NULL);
}
int	main(void)
{
	int		fd;
	size_t	i;

	i = 0;
	fd = open("hola.txt", O_RDONLY);
	while (i < 5)
	{
		printf("%s\n", get_next_line(fd));
		i++;
	}
	 close(fd);
}