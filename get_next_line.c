/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:40:15 by alemarch          #+#    #+#             */
/*   Updated: 2021/11/30 15:50:55 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<stdio.h>

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		s1_len;
	int		s2_len;

	if (s1 && s2)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		ret = malloc((s1_len + s2_len + 1) * sizeof(char));
		if (!ret)
			return (NULL);
		i = 0;
		while (s1[i])
		{
			ret[i] = s1[i];
			i++;
		}
		i = 0;
		while (s2[i])
			ret[s1_len++] = s2[i++];
		ret[s1_len] = '\0';
		return (ret);
	}
	return (NULL);
}

char *get_next_line(int fd)
{
	static char	*remain[1024];
	char		*buff;
	char		*tmp;
	char		*ret;

	buff = "";
	tmp = malloc(BUFFER_SIZE);
	if (remain[fd])
	{
		buff = ft_strjoin(buff, remain[fd]);
		free(remain[fd]);
	}
	read(fd, tmp, BUFFER_SIZE);
	buff = ft_strjoin(buff, tmp);
	buff[BUFFER_SIZE] = '\0';
	if (ft_checkeol(buff))
	{
		ret = ft_substr(buff, 0, ft_checkeol(buff) + 1);
		remain[fd] = ft_substr(buff, ft_checkeol(buff) + 1, ft_strlen(buff));
		printf("\e[1;96m" "%s\n" "\e[0m", remain[fd]);
		return (ret);
	}
	return (buff);
}

int main(void)
{
  int	fd = open("test.txt", O_RDONLY);
  char *str = get_next_line(fd);
  printf("\e[1;93m" "%s" "\e[0m", str);
  free(str);
  while (str)
  {
    str = get_next_line(fd);
    printf("\e[1;93m" "%s" "\e0m", str);
    free(str);
  }
  close(fd);
}
