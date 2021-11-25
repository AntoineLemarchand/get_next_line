/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:40:15 by alemarch          #+#    #+#             */
/*   Updated: 2021/11/25 21:16:14 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_realloc(char *buff, int size)
{
	char	*buff_ret;

	buff_ret = malloc(size * sizeof(char));
	if (!buff_ret)
		return (NULL);
	ft_strcpy(buff_ret, buff);
	free(buff);
	return (buff_ret);
}

char *ft_getline(int fd, int len_read)
{
	char	*buff;
	int		bytes_read;
	int		size;
	int		i;

	read(fd, NULL, len_read);
	buff = malloc(sizeof(char));
	bytes_read = 0;
	while (buff && buff[ft_strlen(buff) - 1] != '\n')
	{
		byte_read++;
		buff = ft_realloc(buff, byte_read);
		size = read(fd, buff, 1);
		if (buff[ft_strlen(buff) - 1] == '\0' && i < len_read)
		{
			free(buff);
			byte_read = 0;
			i++;
		}
	}
	return (buff);
}

char *get_next_line(int fd)
{
	static int	len_read;
	char *ret;

	if (!checkfile)
	{
		ret = ft_getline(fd, len_read);
		return (ret);
	}
	else
		return (NULL);
}
