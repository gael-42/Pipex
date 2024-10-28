/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:08:53 by lemarian          #+#    #+#             */
/*   Updated: 2024/09/13 15:26:42 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_left(char *buffer)
{
	int		i;
	int		j;
	char	*left;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	left = ft_calloc((ft_strlen(buffer) - i + 1), 1);
	if (!left)
		return (free(buffer), NULL);
	i++;
	j = 0;
	while (buffer[i])
		left[j++] = buffer[i++];
	free(buffer);
	return (left);
}

char	*make_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_calloc(i + 2, 1);
	else
		line = ft_calloc(i + 1, 1);
	if (!line)
		return (free(buffer), NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*join_buff(char *old_buff, char *fresh_buff)
{
	char	*big_buff;

	big_buff = ft_strjoin(old_buff, fresh_buff);
	if (!big_buff)
		return (free(old_buff), NULL);
	free(old_buff);
	return (big_buff);
}

char	*read_file(int fd, char *old_buff)
{
	char	*fresh_buff;
	int		byte_read;

	if (!old_buff)
		old_buff = ft_calloc(1, 1);
	if (!old_buff)
		return (free(old_buff), NULL);
	if (ft_strchr(old_buff, '\n'))
		return (old_buff);
	fresh_buff = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!fresh_buff)
		return (free(old_buff), NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, fresh_buff, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(fresh_buff), free(old_buff), NULL);
		fresh_buff[byte_read] = '\0';
		old_buff = join_buff(old_buff, fresh_buff);
		if (ft_strchr(fresh_buff, '\n'))
			break ;
	}
	free(fresh_buff);
	return (old_buff);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = make_line(buffer);
	buffer = save_left(buffer);
	return (line);
}

/*int	main(void)
{
	int	fd;
	char	*str;


	fd = open("doc.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	close(fd);
}*/
