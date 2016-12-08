/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:39:19 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/12/08 06:23:26 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		try_put(t_env *env, t_tetri *tetri, int x, int y)
{
	int		i;
	int		j;

	i = -1;
	while (tetri->tetri[++i] && ((y + i) <= env->map_size))
	{
		j = -1;
		while (tetri->tetri[i][++j] && ((x + j) <= env->map_size))
			if ((env->map[y + i][x + j] != '.') && (tetri->tetri[i][j] != '.'))
				return (0);
	}
	put_elem(env, tetri, x, y);
	return (1);
}

int		go_solve(t_env *env, t_tetri *tetri)
{
	int		y;
	int		x;

	if (!tetri)
		return (1);
	y = -1;
	while ((++y + tetri->height) <= env->map_size)
	{
		x = -1;
		while ((++x + tetri->width) <= env->map_size)
		{
			if (try_put(env, tetri, x, y))
			{
				if (go_solve(env, tetri->next))
					return (1);
				else
					put_elem_point(env, tetri, x, y);
			}
		}
	}
	return (0);
}

void	solve(t_env *env)
{
	while (!go_solve(env, env->list->first))
	{
		ft_strdel(env->map);
		env->map = map_generator(++(env->map_size));
	}
}
