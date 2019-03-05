/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 10:29:39 by amartyne          #+#    #+#             */
/*   Updated: 2018/07/15 14:12:19 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		what_is_left(char **line, char **str)
{
	char			*temp;
	char			*c;

	if ((c = ft_strchr(*str, '\n')))
	{
		*line = ft_strsub(*str, 0, c - *str);
		temp = *str;
		*str = ft_strsub(*str, (c - *str) + 1, ft_strlen(*str));
		free(temp);
		return (1);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (0);
}

void	do_buff(char **mark, char buf[BUFF_SIZE + 1], char **line, char **str)
{
	char			*temp;
	char			*to_free;

	to_free = *line;
	if (*mark)
	{
		if (!*line)
			*line = ft_strsub(buf, 0, (*mark - buf));
		else
		{
			temp = ft_strsub(buf, 0, (*mark - buf));
			*line = ft_strjoin(*line, temp);
			free(temp);
		}
		*str = ft_strsub(buf, (*mark - buf) + 1, ft_strlen(buf));
	}
	else
	{
		if (!*line)
			*line = ft_strdup(buf);
		else
			*line = ft_strjoin(*line, buf);
	}
	free(to_free);
}

int		read_file(int fd, char **line, char **str)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*c;

	ft_bzero(buf, BUFF_SIZE + 1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if ((c = ft_strchr(buf, '\n')))
		{
			do_buff(&c, buf, line, str);
			return (1);
		}
		else
			do_buff(&c, buf, line, str);
		if (ret != BUFF_SIZE)
			return (1);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*str;
	int				ret;
	t_list			*temp;

	temp = str;
	if (fd < 0 || line == NULL)
		return (-1);
	while (temp && (int)temp->content_size != fd)
		temp = temp->next;
	if (!temp)
	{
		temp = ft_lstnew(0, 0);
		temp->content_size = fd;
		ft_lstadd(&str, temp);
	}
	*line = NULL;
	if (temp->content)
		if (what_is_left(line, (char**)&(temp->content)) == 1)
			return (1);
	ret = read_file(fd, line, (char**)&(temp->content));
	if (!ret && line && *line && **line)
		return (1);
	return (ret);
}
