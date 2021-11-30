/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:40:15 by alemarch          #+#    #+#             */
/*   Updated: 2021/11/30 14:19:04 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	ft_checkeol(char *buff)
{
	int	i;
	
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char *get_next_line(int fd)
{
	static char	*remain[1024];
	char		*buff;
	char		*ret;

	buff = malloc(BUFFER_SIZE + 1);
	read(fd, buff, BUFFER_SIZE);
	buff[BUFFER_SIZE] = '\0';
	if (ft_checkeol(buff))
	{
		ret = ft_substr(buff, 0, ft_checkeol(buff) + 1);
		remain[fd] = ft_substr(buff, ft_checkeol(buff) + 1, ft_strlen(buff));
		free(remain[fd]);
		return (ret);
	}
	return (buff);
}

#include<stdio.h>
int main(void)
{
  int	fd = open("test.txt", O_RDONLY);
  char *str = get_next_line(fd);
  printf("%s", str);
  free(str);
  str = get_next_line(fd);
  printf("%s", str);
  free(str);
  close(fd);
}
