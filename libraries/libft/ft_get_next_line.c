/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:01:45 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 12:32:16 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_line(int fd, char **line, char **str_sta)
{
	int			i;
	char		*strchr;
	char		*temp;

	i = 0;
	strchr = str_sta[fd];
	while (strchr[i] != '\n' && strchr[i] != '\0')
		i++;
	if (strchr[i] == '\n')
	{
		strchr[i] = '\0';
		*line = ft_strdup(strchr);
		temp = ft_strdup(&strchr[i + 1]);
		free(str_sta[fd]);
		str_sta[fd] = temp;
		return (1);
	}
	return (0);
}

int	read_fd(int fd, char **line, char **str_sta, char *buf)
{
	int			ret;
	char		*tmp;

	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (!(str_sta[fd]))
			str_sta[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(str_sta[fd], buf);
			free(str_sta[fd]);
			str_sta[fd] = tmp;
		}
		ret = 1;
		if (check_line(fd, line, str_sta))
			break ;
		ret = read(fd, buf, BUFFER_SIZE);
	}
	if (ret < 0)
		return (-1);
	return (ret);
}

int	last_line(int fd, char **line, char **str_sta)
{
	*line = ft_strdup(str_sta[fd]);
	free(str_sta[fd]);
	str_sta[fd] = NULL;
	return (0);
}

int	check_buffer(char **str_sta, int fd, char **line, char *buf)
{
	int	ret;

	if (str_sta[fd])
	{
		ret = check_line(fd, line, str_sta);
		if (ret > 0)
		{
			free(buf);
			return (1);
		}
	}
	return (0);
}

int	ft_get_next_line(int fd, char **line, int free_flag)
{
	char		*buf;
	static char	*str_sta[RLIMIT_NOFILE];
	int			ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 || fd > RLIMIT_NOFILE)
		return (-1);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	if (free_flag == 1)
		return (gnl_free_str_sta(fd, str_sta, buf));
	if (check_buffer(str_sta, fd, line, buf))
		return (1);
	ret = read_fd(fd, line, str_sta, buf);
	free(buf);
	if (ret != 0 || str_sta[fd] == NULL)
	{
		if (ret == 0 || str_sta[fd] == NULL)
			*line = ft_newstr(0);
		return (ret);
	}
	last_line(fd, line, str_sta);
	return (0);
}
