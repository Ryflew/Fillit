/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 22:23:47 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/12/08 05:33:27 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	add_param(t_tetri *tetri)
{
	int		y;
	int		x;
	int		max_x;
	int		max_y;
	int		line_x;

	max_x = 0;
	max_y = 0;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		line_x = 0;
		while (tetri->tetri[y][++x])
			if (tetri->tetri[y][x] == '#')
				line_x++;
		if (line_x)
			max_y++;
		if (line_x > max_x)
			max_x = line_x;
	}
	tetri->width = max_x;
	tetri->height = max_y;
}

int		get_column(char **str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < 4)
	{
		if (str[i][j] == '#')
			return (j);
		if (++i == 4)
		{
			i = 0;
			j++;
		}
	}
	return (0);
}

int		get_line(char **str, int column)
{
	int		i;
	int		j;

	i = 0;
	j = column;
	while (i < 4)
	{
		if (str[i][j] == '#')
			return (i);
		if (!str[i][++j])
		{
			j = column;
			i++;
		}
	}
	return (0);
}

char	**clear_tetri(char **src, int x, int column, int line)
{
	int		y;
	char	**out;

	out = malloc_out();
	line = get_line(src, column);
	y = line - 1;
	while (++y < 4 && src[y])
	{
		x = 4;
		while (--x >= column)
		{
			if (src[y][x] == '#')
			{
				out[y - line] = ft_strsub(src[y], column, (x - column + 1));
				break ;
			}
		}
		if (x < column)
			break ;
	}
	y--;
	while ((++y - line) < 4)
		out[y - line] = ft_memalloc(1);
	ft_strdel(src);
	return (out);
}

void	get_tetri(t_env **env, char *path)
{
	char	*str;
	char	**out;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	while (1)
	{
		out = (char**)malloc(sizeof(char*) * 5);
		out[4] = NULL;
		i = -1;
		while (++i < 4)
		{
			get_next_line(fd, &str);
			out[i] = str;
		}
		out = clear_tetri(out, 0, get_column(out), 0);
		add_node(&(*env)->list, out);
		add_param((*env)->list->last);
		if (!get_next_line(fd, &str))
			break ;
		free(str);
	}
	free(str);
	close(fd);
}
