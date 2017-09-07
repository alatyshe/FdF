/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:26:31 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/12 18:26:32 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		ft_fill_t_unit2(char *str, int *i, int x, t_unit **lst)
{
	int		len;

	len = ft_strlen(str) + (*i);
	if (str[(*i)] == ',')
	{
		(*lst)->color = ft_rgb(ft_atoi_base(str + (*i) + 3, 16));
		while (str[(*i)] != ' ' && len > (*i))
			(*i)++;
	}
	else
		(*lst)->color = ft_rgb(0XFFFFFF);
	(*lst)->x = x;
}

int			ft_fill_t_unit(char *str, t_unit **lst, int y)
{
	int			i;
	int			x;
	int			len;

	x = 0;
	i = 0;
	len = ft_strlen(str);
	while (len > i)
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		{
			(*lst)->z = ft_atoi(str + i);
			while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
				i++;
			ft_fill_t_unit2(str, &i, x, lst);
			(*lst)->flag = ((*lst)->z > 0) ? 1 : 0;
			(*lst)->y = y;
			(*lst)->next = ft_lstnew_unit();
			(*lst) = (*lst)->next;
			x++;
		}
		i++;
	}
	return (x);
}

t_unit		*ft_for_reading(int fd, int *y, int *x)
{
	t_unit		*lst;
	t_unit		*s_lst;
	char		*str;
	int			count;
	int			validate;

	s_lst = ft_lstnew_unit();
	lst = s_lst;
	count = -1;
	while (get_next_line(fd, &str) > 0)
	{
		if (count == -1)
			count = ft_valid_rows(str);
		validate = ft_valid_rows(str);
		if ((ft_valid_map(str) || count != validate) &&
				write(1, "Error! Invalid file\n", 21))
			return (0);
		(*x) = ft_fill_t_unit(str, &lst, (*y));
		free(str);
		(*y)++;
	}
	return (s_lst);
}

void		ft_fill_s_window(t_unit *lst, int x, int y)
{
	t_window	*win;

	win = ft_lstnew_win(x, y);
	win->lst_before = lst;
	ft_modify_z_2(win, win->lst_before);
	ft_display(win);
	mlx_hook(win->win, 2, 5, ft_key_control, win);
	mlx_loop(win->mlx);
}

int			main(int argc, char **argv)
{
	int			fd;
	int			y;
	int			x;
	t_unit		*lst;

	y = 0;
	if (argc != 2 && write(1, "usage: ./fdf [map.fdf]\n", 23))
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) == -1 &&
			write(1, "Error! Invalid file\n", 20))
		return (0);
	lst = ft_for_reading(fd, &y, &x);
	close(fd);
	if (lst != NULL)
		ft_fill_s_window(lst, x, y);
	return (0);
}
