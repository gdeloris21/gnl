/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeloris <gdeloris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:36:44 by gdeloris          #+#    #+#             */
/*   Updated: 2022/03/12 21:14:36 by gdeloris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_to_remainder(int fd, char *remainder)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(remainder, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		remainder = ft_strjoin(remainder, buff);
	}
	free(buff);
	return (remainder);
}

char	*ft_new_remainder(char *remainder)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(remainder) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (remainder[i])
		str[j++] = remainder[i++];
	str[j] = '\0';
	free(remainder);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	remainder[fd] = ft_read_to_remainder(fd, remainder[fd]);
	if (!remainder[fd])
		return (NULL);
	line = ft_get_line(remainder[fd]);
	remainder[fd] = ft_new_remainder(remainder[fd]);
	return (line);
}
