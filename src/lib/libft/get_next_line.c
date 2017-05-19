/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:58:29 by apineda           #+#    #+#             */
/*   Updated: 2017/05/12 00:06:22 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_line(char **send, char *buff, char **saved)
{
	char		*temp;
	char		*temper;

	if (buff && *saved)
	{
		temp = ft_strjoin(*saved, buff);
		free(*saved);
		*saved = temp;
	}
	else if (buff && !(*saved))
		*saved = ft_strdup(buff);
	if (*saved)
	{
		if ((temp = ft_strchr(*saved, '\n')))
		{
			*temp = '\0';
			temp++;
			temper = ft_strdup(temp);
			*send = ft_strdup(*saved);
			free(*saved);
			*saved = temper;
			return (1);
		}
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	static char	*saved = NULL;

	ft_bzero((void *)buf, sizeof(char) * (BUFF_SIZE + 1));
	if (!line || fd < 0 || read(fd, buf, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (saved && (ft_line(line, NULL, &saved)))
		return (1);
	while ((ret = read(fd, &buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (ft_line(line, buf, &saved))
			return (1);
	}
	if (saved && *saved)
	{
		*line = ft_strdup(saved);
		ft_strclr(saved);
		return (1);
	}
	return (0);
}
