/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 19:36:29 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/12/08 05:12:29 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**map_generator(int size)
{
	char	**new_map;
	int		y;

	new_map = (char **)malloc(sizeof(char *) * (size + 1));
	y = -1;
	while (++y < size)
	{
		new_map[y] = (char *)malloc(sizeof(char) * (size + 1));
		ft_memset(new_map[y], '.', size);
		new_map[y][size] = '\0';
	}
	return (new_map);
}

void	put_elem(t_env *env, t_tetri *tetri, int x, int y)
{
	int		i;
	int		j;

	i = -1;
	while (tetri->tetri[++i])
	{
		j = -1;
		while (tetri->tetri[i][++j])
		{
			if (tetri->tetri[i][j] != '.')
				env->map[y + i][x + j] = 'A' + tetri->n;
		}
	}
}

void	put_elem_point(t_env *env, t_tetri *tetri, int x, int y)
{
	int		i;
	int		j;

	i = -1;
	while (tetri->tetri[++i])
	{
		j = -1;
		while (tetri->tetri[i][++j])
		{
			if (tetri->tetri[i][j] != '.')
				env->map[y + i][x + j] = '.';
		}
	}
}

void	del_env(t_env *env)
{
	t_tetri	*tmp;

	while (env->list->first)
	{
		tmp = env->list->first->next;
		ft_strdel(env->list->first->tetri);
		free(env->list->first);
		env->list->first = tmp;
	}
	free(env->list);
	ft_strdel(env->map);
	free(env);
}

void	print_map(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->map_size)
		ft_putendl(env->map[i]);
}
