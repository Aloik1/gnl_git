#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 150
# endif

#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);



#endif