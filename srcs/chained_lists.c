/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_lists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:29:08 by nghaddar          #+#    #+#             */
/*   Updated: 2016/12/08 05:34:00 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_env			*init_env(void)
{
	t_env		*new_env;

	if (!(new_env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	new_env->list = init_list();
	new_env->map_size = 3;
	new_env->map = map_generator(new_env->map_size);
	return (new_env);
}

t_handler		*init_list(void)
{
	t_handler	*new_list;

	if (!(new_list = (t_handler *)malloc(sizeof(t_handler))))
		return (NULL);
	new_list->first = NULL;
	new_list->last = NULL;
	new_list->n_elem = 0;
	return (new_list);
}

void			add_node(t_handler **list, char **tetri)
{
	t_tetri		*new_el;

	if (!(new_el = (t_tetri *)malloc(sizeof(t_tetri))))
		return ;
	new_el->tetri = tetri;
	new_el->next = NULL;
	new_el->n = (*list)->n_elem;
	(*list)->n_elem++;
	if ((*list)->first == NULL)
	{
		(*list)->first = new_el;
		(*list)->last = new_el;
	}
	else
	{
		(*list)->last->next = new_el;
		(*list)->last = new_el;
	}
}

char			**malloc_out(void)
{
	char	**out;

	out = (char**)malloc(sizeof(char*) * 5);
	out[4] = NULL;
	return (out);
}
