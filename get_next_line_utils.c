/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:41:49 by alemarch          #+#    #+#             */
/*   Updated: 2021/11/26 09:59:00 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

