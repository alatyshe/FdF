/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:48:08 by alatyshe          #+#    #+#             */
/*   Updated: 2017/01/27 17:48:09 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1200
# define HEIGHT 900
# include <stdio.h>
# include "./miniLibX/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "libft/header/libft.h"

typedef struct	s_color
{
	int				r;
	int				g;
	int				b;
	int				a;
}				t_color;

typedef struct	s_color_indent
{
	int				len;
	int				len2;
}				t_color_indent;

typedef struct	s_units
{
	int				x;
	int				y;
	double			x1;
	double			y1;
	int				z;
	t_color			*cl;
	int				flag;
}				t_units;

typedef struct	s_unit
{
	int				x;
	int				y;
	double			x1;
	double			y1;
	int				z;
	int				z_2;
	t_color			*color;
	int				flag;
	struct s_unit	*next;
}				t_unit;

typedef struct	s_print
{
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	int				delta_x;
	int				delta_y;
	int				sign_x;
	int				sign_y;
	int				error;
	int				error2;
	int				i;
}				t_print;

typedef struct	s_window
{
	int				width;
	int				height;
	double			indent_x;
	double			indent_y;
	int				x;
	int				y;
	void			*mlx;
	void			*win;
	int				size;
	double			size_coef;
	double			size_z_coef;
	t_units			**lst;
	t_unit			*lst_before;
}				t_window;

int				ft_valid_map(char *str);
void			ft_nulling_str(char **str);
int				ft_valid_rows(char *str);
int				get_next_line(int const fd, char **line);
t_unit			*ft_lstnew_unit(void);
t_print			*ft_lstnew_print(t_units *first, t_units *second);
t_window		*ft_lstnew_win(int x, int y);
int				ft_fill_t_unit(char *str, t_unit **lst, int y);
t_units			**ft_convert(int y, int x, t_unit *lst);
t_units			**ft_convert(int y, int x, t_unit *lst);
void			shift_coord(t_window *window, t_unit *list);
int				ft_key_control(int key, t_window *window);
void			ft_fill_s_window(t_unit *lst, int x, int y);
void			ft_modify_z_2(t_window *window, t_unit *list);
int				ft_atoi_base(char *str, int base);
void			ft_print_pixels(t_units *first, t_units *second,
					t_window *window);
t_color			*ft_rgb(int color);
int				rgbtoint(t_color *fir, t_color *sec, t_color_indent *list);
void			ft_display(t_window *window);
void			ft_string_put(t_window *window);
t_color_indent	*ft_color_indent(int len);

#endif
