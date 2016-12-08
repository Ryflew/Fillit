/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:36:36 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/12/08 06:26:49 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
	t_env	*env;

	if (argc != 2)
	{
		ft_putendl_fd("usage: ./fillit source_file", 2);
		exit(-1);
	}
	if (check_file(argv[1]))
		ERROR;
	env = init_env();
	get_tetri(&env, argv[1]);
	solve(env);
	print_map(env);
	return (0);
}
