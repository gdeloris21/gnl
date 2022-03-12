/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeloris <gdeloris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:36:13 by gdeloris          #+#    #+#             */
/*   Updated: 2022/03/12 21:14:58 by gdeloris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *remainder, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!remainder)
	{
		remainder = (char *)malloc(sizeof(char) * 2);
		remainder[0] = '\0';
	}
	if (!remainder || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(remainder) + ft_strlen(buff)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (remainder)
		while (remainder[++i] != '\0')
			str[i] = remainder[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(remainder) + ft_strlen(buff)] = '\0';
	free(remainder);
	return (str);
}

char	*ft_get_line(char *remainder)
{
	int		i;
	char	*str;

	i = 0;
	if (!remainder[i])
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
	{
		str[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
	{
		str[i] = remainder[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
