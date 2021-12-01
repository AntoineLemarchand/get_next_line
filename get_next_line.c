/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:40:15 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/01 12:43:51 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<stdio.h>

static int	ft_loadstatic(int fd, char **remain)
{
	int		bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read && !ft_strchr(remain[fd], '\n'))
	{
		tmp = malloc(BUFFER_SIZE + 1);
		if (!tmp)
			return (1);
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		tmp[bytes_read] = '\0';
		if (bytes_read == -1)
		{
			free(tmp);
			return (1);
		}
		if (remain[fd])
			remain[fd] = ft_strjoin(remain[fd], tmp);
		else
			remain[fd] = ft_strdup(tmp);
		free(tmp);
		if (!remain[fd])
			return (1);
	}
	return (0);
}

static char	*ft_getline(int fd, char	**remain)
{
	size_t	i;
	char	*ret;
	char	*newremain;

	i = 0;
	while (remain[fd][i] && remain[fd][i] != '\n')
		i++;
	if (ft_strlen(remain[fd]) == i)
	{
		ret = ft_strdup(remain[fd]);
		if (!ret)
			return (NULL);
		free(remain[fd]);
		remain[fd] = NULL;
		return (ret);
	}
	ret = ft_substr(remain[fd], 0, i + 1);
	if (!ret)
		return (NULL);
	newremain = ft_substr(remain[fd], i + 1, ft_strlen(remain[fd]));
	free(remain[fd]);
	remain[fd] = newremain;
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*remain[1024];
	char		*buff;

	if (fd < 0 || fd > 1023)
		return (NULL);
	if (ft_loadstatic(fd, remain))
		return (NULL);
	buff = ft_getline(fd, remain);
	if (buff[0] == '\0')
	{
		free(buff);
		free(remain[fd]);
		return (NULL);
	}
	return (buff);
}
/*
int main(int ac, char **av)
{
	(void)ac;
	int	fd = open(av[1], O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s", str);
	free(str);
	while (str)
	{
		str = get_next_line(fd);
		if (str)
			printf("%s", str);
		free(str);
	}
	close(fd);
}
*/
