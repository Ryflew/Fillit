/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 00:29:10 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/12/05 22:24:00 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		parse_str(int bits, char *str)
{
	int		i;
	int		tmp;

	i = -1;
	tmp = 0;
	while (++i < 4)
	{
		if (str[i] == '.')
			tmp = (tmp << 1) + 0;
		else if (str[i] == '#')
			tmp = (tmp << 1) + 1;
		else
			return (0);
	}
	bits = (bits << 4) + tmp;
	return (bits);
}

int		check_tetri(int bits)
{
	if ((bits != 547) && (bits != 23) && (bits != 785) && (bits != 71) &&
		(bits != 275) && (bits != 113) && (bits != 401) && (bits != 29) &&
		(bits != 39) && (bits != 281) && (bits != 57) && (bits != 305) &&
		(bits != 27) && (bits != 561) && (bits != 153) && (bits != 99) &&
		(bits != 4369) && (bits != 15) && (bits != 51))
		return (0);
	return (1);
}

int		check_one_tetri(int fd)
{
	int		i;
	int		bits;
	char	*str;

	i = -1;
	bits = 0;
	while (++i < 4)
	{
		if (!get_next_line(fd, &str) || (ft_strlen(str) != 4))
			return (0);
		bits = parse_str(bits, str);
		free(str);
	}
	return (bits);
}

int		check_file(char *path)
{
	int		fd;
	int		bits;
	char	*str;

	bits = 1;
	fd = open(path, O_RDONLY);
	while (bits)
	{
		bits = check_one_tetri(fd);
		while (bits > 0 && !(bits & 1))
			bits = bits >> 1;
		if (!check_tetri(bits))
			return (1);
		bits = get_next_line(fd, &str);
		if (ft_strlen(str))
		{
			free(str);
			return (1);
		}
		free(str);
	}
	close(fd);
	return (0);
}
