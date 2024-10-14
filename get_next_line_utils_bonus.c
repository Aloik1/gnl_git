/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikondrat <ikondrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:29:59 by ikondrat          #+#    #+#             */
/*   Updated: 2024/09/30 18:33:29 by ikondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	if (len > ft_strlen(str) - start)
		len = ft_strlen(str) - start;
	substr = (char *)malloc(len * sizeof(char) + 1);
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = str[start + i];
		i++;
	}
	while (str[start + i] && i < len && start < ft_strlen(str))
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = s[i];
	return (dup);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	dest = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*out;

	i = 0;
	out = (char *)s;
	while (out[i])
	{
		if (out[i] == (char)c)
			return (out + i);
		i++;
	}
	if (out[i] == (char)c && out[i] == '\0')
		return (out + i);
	return (NULL);
}
