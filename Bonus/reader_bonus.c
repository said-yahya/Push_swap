/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:10:59 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/21 14:32:56 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*get_next_line(int fd)
{
	size_t		bytes_read;
	char		*buffer;
	char		*line;
	static char	*remainder;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes_read = 1;
	if (!buffer || fd < 0 || BUFFER_SIZE <= 0)
		return (free(buffer), NULL);
	while ((!remainder || !ft_strchr(remainder, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(remainder), remainder = NULL, NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin_f(remainder, buffer);
	}
	free(buffer);
	if (!remainder || remainder[0] == '\0')
		return (free(remainder), remainder = NULL, NULL);
	line = line_here(remainder);
	remainder = nextline(remainder);
	return (line);
}

char	*line_here(char *remainder)
{
	int		i;
	char	*line;

	i = 0;
	if (!remainder || remainder[0] == '\0')
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		i++;
	line = ft_substr(remainder, 0, i);
	return (line);
}

char	*nextline(char *remainder)
{
	int		i;
	char	*new;
	char	*endpoint;

	endpoint = ft_strchr(remainder, '\n');
	if (!endpoint || endpoint[1] == 0)
	{
		free(remainder);
		return (NULL);
	}
	new = malloc(ft_strlen(endpoint + 1) + 1);
	if (!new)
		return (NULL);
	i = 1;
	while (endpoint[i])
	{
		new[i - 1] = endpoint[i];
		i++;
	}
	new[i - 1] = 0;
	free(remainder);
	return (new);
}

/* char	*ft_strdup(char *s)
{
	size_t	i;
	size_t	j;
	char	*cpy;

	i = ft_strlen(s);
	cpy = malloc((sizeof(char)) * (i + 1));
	j = 0;
	if (!cpy)
		return (NULL);
	while (j < i)
	{
		cpy[j] = s[j];
		j++;
	}
	cpy[j] = 0;
	return (cpy);
} */

/* char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = 0;
	return (new);
}
 */
