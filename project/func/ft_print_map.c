/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:26:31 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/12 18:26:32 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int				ft_checking_overflow(t_units *fir, t_units *sec, t_window *win)
{
	if ((fir->x1 < 0 || fir->y1 < 0) && (sec->x1 < 0 || sec->y1 < 0))
		return (0);
	if ((fir->x1 > win->width || fir->y1 > win->height) &&
			(sec->x1 > win->width || sec->y1 > win->height))
		return (0);
	return (1);
}

void			ft_print_pixels(t_units *f, t_units *s, t_window *w)
{
	t_print			*l;
	t_color_indent	*c;

	if (!ft_checking_overflow(f, s, w))
		return ;
	l = ft_lstnew_print(f, s);
	c = ft_color_indent(l->error > 0 ? l->delta_x : l->delta_y);
	mlx_pixel_put(w->mlx, w->win, l->x1, l->y1, rgbtoint(f->cl, s->cl, c));
	while (l->x1 != l->x2 || l->y1 != l->y2)
	{
		mlx_pixel_put(w->mlx, w->win, l->x1, l->y1, rgbtoint(f->cl, s->cl, c));
		l->error2 = l->error * 2;
		if (l->error2 > -l->delta_y)
		{
			l->error -= l->delta_y;
			l->x1 += l->sign_x;
		}
		if (l->error2 < l->delta_x)
		{
			l->error += l->delta_x;
			l->y1 += l->sign_y;
		}
	}
	free(c);
	free(l);
}

void			ft_modify_z_2(t_window *win, t_unit *list)
{
	t_unit		*lst;

	lst = list;
	while (lst)
	{
		lst->z_2 = (lst->z * win->size / 3) * win->size_z_coef;
		lst = lst->next;
	}
}

int				ft_key_control(int key, t_window *win)
{
	if (key == 53)
		exit(1);
	if (key == 1)
		win->indent_y -= 20;
	if (key == 13)
		win->indent_y += 20;
	if (key == 2)
		win->indent_x -= 20;
	if (key == 0)
		win->indent_x += 20;
	if (key == 78 || key == 27)
		win->size_z_coef -= 0.1;
	if (key == 69 || key == 24)
		win->size_z_coef += 0.1;
	if (key == 29)
		win->size = (win->size < 5) ? win->size * 2 : win->size * 1.2;
	if (key == 25 && win->size > 1)
		win->size = win->size / 1.2;
	mlx_clear_window(win->mlx, win->win);
	ft_display(win);
	return (0);
}

void			ft_string_put(t_window *win)
{
	mlx_string_put(win->mlx, win->win, 20, 15, 0xFFFFFF, "Move by Arrows:");
	mlx_string_put(win->mlx, win->win, 40, 40, 0xFFFFFF, "W - up");
	mlx_string_put(win->mlx, win->win, 40, 60, 0xFFFFFF, "S - down");
	mlx_string_put(win->mlx, win->win, 40, 80, 0xFFFFFF, "A - left");
	mlx_string_put(win->mlx, win->win, 40, 100, 0xFFFFFF, "D - right");
	mlx_string_put(win->mlx, win->win, 20, 125, 0xFFFFFF,
		"Raise or low peaks:");
	mlx_string_put(win->mlx, win->win, 40, 150, 0xFFFFFF, "+ - Raise");
	mlx_string_put(win->mlx, win->win, 40, 170, 0xFFFFFF, "- - Lower");
	mlx_string_put(win->mlx, win->win, 20, 195, 0xFFFFFF, "Zomming:");
	mlx_string_put(win->mlx, win->win, 40, 220, 0xFFFFFF, ") - zoom +");
	mlx_string_put(win->mlx, win->win, 40, 240, 0xFFFFFF, "( - zoom -");
}
