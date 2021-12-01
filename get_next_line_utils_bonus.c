/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:41:49 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/01 16:12:57 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start > ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (len--)
		ret[i++] = s[start++];
	ret[i] = '\0';
	return (ret);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		s_len;
	int		i;

	if (!s)
		return (malloc(sizeof(char)));
	s_len = (int)ft_strlen((char *)s);
	i = 0;
	dest = malloc((s_len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	if (!c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin_n_free(char *s1, char *s2)
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
		i = -1;
		while (s1[++i])
			ret[i] = s1[i];
		i = 0;
		while (s2[i])
			ret[s1_len++] = s2[i++];
		ret[s1_len] = '\0';
		free(s1);
		return (ret);
	}
	return (NULL);
}
