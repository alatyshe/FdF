/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:54:23 by alatyshe          #+#    #+#             */
/*   Updated: 2017/02/18 16:47:46 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*manipulating_list(t_list **ptr, int fd)
{
	t_list	*temp;

	temp = *ptr;
	if (ptr == NULL)
	{
		if (!(temp = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		temp->content = ft_strnew(0);
		temp->content_size = fd;
		temp->next = NULL;
	}
	while (temp)
	{
		if (temp->content_size == (size_t)fd)
			return (temp);
		temp = temp->next;
	}
	if (!(temp = (t_list*)malloc(sizeof(t_list))))
		return (0);
	temp->content = ft_strnew(0);
	temp->content_size = fd;
	temp->next = NULL;
	ft_lstadd(ptr, temp);
	return (*ptr);
}

static int		fin_eol(t_list **list, char **line)
{
	char	*tmp;
	t_list	*lst;

	lst = *list;
	if ((tmp = ft_strchr(lst->content, '\n')) != NULL)
	{
		*tmp++ = '\0';
		tmp = ft_strdup(tmp);
		*line = ft_strdup(lst->content);
		free(lst->content);
		lst->content = tmp;
		return (1);
	}
	return (0);
}

static int		fi_eof(t_list **list, char **line, int bytes)
{
	char	*tmp;
	t_list	*lst;

	lst = *list;
	if (bytes == 0 && (tmp = ft_strchr(lst->content, '\n')) == NULL)
	{
		tmp = ft_strchr(lst->content, '\0');
		if (tmp == lst->content)
			return (0);
		else
		{
			*line = ft_strdup(lst->content);
			free(lst->content);
			lst->content = ft_strnew(0);
			return (1);
		}
	}
	return (0);
}

static int		closed_fd(t_list **lst)
{
	t_list *tmp;

	tmp = *lst;
	free(tmp->content);
	tmp->content = ft_strnew(0);
	return (-1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*ptr;
	char			buf[BUFF_SIZE + 1];
	int				bytes;
	char			*tmp;
	t_list			*sec_ptr;

	sec_ptr = manipulating_list(&ptr, fd);
	bytes = 1;
	if (!line || fd < 0)
		return (-1);
	while (bytes > 0)
	{
		bytes = read(fd, buf, BUFF_SIZE);
		buf[bytes] = '\0';
		tmp = ft_strjoin(sec_ptr->content, buf);
		free(sec_ptr->content);
		sec_ptr->content = tmp;
		if ((tmp = ft_strchr(sec_ptr->content, '\n')) != 0)
			break ;
	}
	if ((bytes < 0) && (closed_fd(&sec_ptr) == -1))
		return (-1);
	if ((fin_eol(&sec_ptr, line) == 1) || (fi_eof(&sec_ptr, line, bytes) == 1))
		return (1);
	return (0);
}
