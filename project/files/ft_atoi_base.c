/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:48:08 by alatyshe          #+#    #+#             */
/*   Updated: 2017/01/27 17:48:09 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
**	ft_atoi_base	- converting from any system to int
*/

int		ft_find_char(char a, int base)
{
	char	*str;
	int		i;

	i = 0;
	str = "0123456789ABCDEF";
	while (str[i] && i < base)
	{
		if (str[i] == a)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, int base)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	ft_nulling_str(&str);
	while (str[k] != '\0')
	{
		if (str[k] == ' ' || str[k] == '\t')
			break ;
		if ((j = ft_find_char(str[k], base)) > -1)
		{
			if (i == 0)
				i += j;
			else
				i = (i * base) + j;
		}
		k++;
	}
	return (i);
}
