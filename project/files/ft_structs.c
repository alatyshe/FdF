/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:26:31 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/12 18:26:32 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
**	ft_lstnew_unit	- list for first reading
**	ft_lstnew_win	- list for all program, contains(list from first
**						read info about window etc)
**	ft_lstnew_print	- struct for saving variables for bresenham func
**	ft_fill_lst		- checking and fill lst if found Numbers
**	ft_convert		- function for creating massive from first list
**	ft_color_indent	- for work width color indnent
*/

t_unit			*ft_lstnew_unit(void)
{
	t_unit			*lst;

	if (!(lst = (t_unit *)malloc(sizeof(t_unit))))
		return (0);
	lst->x = 0;
	lst->y = 0;
	lst->x1 = 0;
	lst->y1 = 0;
	lst->z = 0;
	lst->z_2 = 0;
	lst->flag = 0;
	lst->next = NULL;
	return (lst);
}

t_window		*ft_lstnew_win(int x, int y)
{
	t_window		*win;
	int				unit;
	int				size_box;

	unit = (x < y) ? y : x;
	size_box = (((WIDTH < HEIGHT) ? WIDTH : HEIGHT) / unit) / 2;
	if (!(win = (t_window *)malloc(sizeof(t_window))))
		return (0);
	win->width = (WIDTH > 0) ? WIDTH : 800;
	win->height = (HEIGHT > 0) ? HEIGHT : 800;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, WIDTH, HEIGHT, "mlx 42");
	size_box = (size_box == 0) ? 1 : size_box;
	win->size = size_box;
	win->indent_x = WIDTH / 2;
	win->indent_y = (win->size == 1) ? 0 : (HEIGHT - (size_box * unit)) / 2;
	win->x = x;
	win->size_coef = 1;
	win->size_z_coef = 1;
	win->y = y;
	win->lst = NULL;
	return (win);
}

t_print			*ft_lstnew_print(t_units *first, t_units *second)
{
	t_print			*lst;

	if (!(lst = (t_print *)malloc(sizeof(t_print))))
		return (0);
	lst->x1 = first->x1;
	lst->y1 = first->y1;
	lst->y2 = second->y1;
	lst->x2 = second->x1;
	lst->delta_x = fabs(lst->x2 - lst->x1);
	lst->delta_y = fabs(lst->y2 - lst->y1);
	lst->sign_x = lst->x1 < lst->x2 ? 1 : -1;
	lst->sign_y = lst->y1 < lst->y2 ? 1 : -1;
	lst->error = lst->delta_x - lst->delta_y;
	lst->i = 0;
	return (lst);
}

t_units			**ft_convert(int y, int x, t_unit *lst)
{
	t_units			**res;
	int				y1;
	int				x1;

	y1 = 0;
	res = (t_units **)malloc(sizeof(t_units *) * y);
	while (y1 < y)
	{
		x1 = 0;
		res[y1] = (t_units*)malloc(sizeof(t_units) * x);
		while (x1 < x)
		{
			res[y1][x1].x = lst->x;
			res[y1][x1].y = lst->y;
			res[y1][x1].y1 = lst->y1;
			res[y1][x1].x1 = lst->x1;
			res[y1][x1].z = lst->z;
			res[y1][x1].cl = lst->color;
			lst = lst->next;
			x1++;
		}
		y1++;
	}
	return (res);
}

t_color_indent	*ft_color_indent(int len)
{
	t_color_indent	*list;

	list = (t_color_indent *)malloc(sizeof(t_color_indent));
	list->len = len;
	list->len2 = 1;
	return (list);
}
