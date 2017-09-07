/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_s_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:26:31 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/12 18:26:32 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_color		*ft_rgb(int color)
{
	t_color		*lst;

	lst = (t_color *)malloc(sizeof(t_color));
	lst->b = (color) & 0xFF;
	lst->g = (color >> 8) & 0xFF;
	lst->r = (color >> 16) & 0xFF;
	lst->a = (color >> 24) & 0xFF;
	return (lst);
}

int			ft_same_colors(t_color *fir, t_color *sec)
{
	if (fir->r != sec->r)
		return (0);
	if (fir->g != sec->g)
		return (0);
	if (fir->b != sec->b)
		return (0);
	if (fir->a != sec->a)
		return (0);
	return (1);
}

int			rgbtoint(t_color *fir, t_color *sec, t_color_indent *list)
{
	int			color;
	int			r;
	int			g;
	int			b;
	int			a;

	if (ft_same_colors(fir, sec) == 0)
	{
		a = fir->a + ((double)(sec->a - fir->a) / list->len) * list->len2;
		r = fir->r + ((double)(sec->r - fir->r) / list->len) * list->len2;
		g = fir->g + ((double)(sec->g - fir->g) / list->len) * list->len2;
		b = fir->b + ((double)(sec->b - fir->b) / list->len) * list->len2;
		list->len2++;
	}
	else
	{
		r = fir->r;
		g = fir->g;
		b = fir->b;
		a = fir->a;
	}
	color = b | (g << 8) | (r << 16) | (a << 24);
	return (color);
}

void		shift_coord(t_window *win, t_unit *lst)
{
	int			a;
	int			b;
	int			n;
	int			k;

	k = 0;
	n = 0;
	while (lst)
	{
		a = lst->x + n;
		b = lst->y + k;
		n = n + win->size;
		if (lst && lst->next && lst->x > lst->next->x)
		{
			k = k + win->size;
			n = 0;
		}
		lst->x1 = (a - b) + win->indent_x;
		if (lst->flag > 0)
			lst->z_2 = (lst->z * win->size / 3) * win->size_z_coef;
		lst->y1 = ((a + b) / 2) - lst->z_2 + win->size + win->indent_y;
		lst = lst->next;
	}
}

void		ft_display(t_window *win)
{
	int			i;
	int			j;

	ft_modify_z_2(win, win->lst_before);
	shift_coord(win, win->lst_before);
	win->lst = ft_convert(win->y, win->x, win->lst_before);
	i = 0;
	while (i < win->y)
	{
		j = 0;
		while (j < win->x)
		{
			if (j + 1 < win->x)
				ft_print_pixels(&win->lst[i][j], &win->lst[i][j + 1], win);
			if (i + 1 < win->y)
				ft_print_pixels(&win->lst[i][j], &win->lst[i + 1][j], win);
			j++;
		}
		i++;
	}
	ft_string_put(win);
}
