/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:26:31 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/12 18:26:32 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
**	function for validate maps
**	ft_nulling_str	- for transfer from small letter to big for ColorFunc
**	ft_valid_map	- for checking valide symbols
**	ft_valid_rows	- for checking property length of rows
*/

void	ft_nulling_str(char **str)
{
	int		i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] >= 'a' && (*str)[i] <= 'z')
			(*str)[i] -= 32;
		i++;
	}
}

int		ft_valid_map(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' || !ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_valid_rows(char *str)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] != ' ' && i < len)
				i++;
			if (i > len && (str[i + 1] != ' ' || !ft_isdigit(str[i + 1])))
				return (j);
			j++;
		}
		i++;
	}
	return (j);
}
