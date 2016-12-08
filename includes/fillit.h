/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 00:31:05 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/12/08 06:13:41 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft.h"

# define ERROR { ft_putendl("error"); exit(EXIT_FAILURE); }

typedef	struct			s_tetri
{
	char			**tetri;
	int				height;
	int				width;
	int				n;
	struct s_tetri	*next;
}						t_tetri;

typedef	struct			s_handler
{
	t_tetri		*first;
	t_tetri		*last;
	int			n_elem;
}						t_handler;

typedef	struct			s_env
{
	t_handler	*list;
	char		**map;
	int			map_size;
}						t_env;

int						get_next_line(const int fd, char **line);
int						check_file(char *path);
t_env					*init_env(void);
t_handler				*init_list(void);
void					add_node(t_handler **list, char **tetri);
void					print_struct(t_env *env);
char					**map_generator(int size);
void					put_elem(t_env *env, t_tetri *tetri, int x, int y);
void					put_elem_point(t_env *env, t_tetri *tetri, int x,
							int y);
void					print_map(t_env *env);
void					get_tetri(t_env **env, char *path);
int						get_column(char **str);
int						get_line(char **str, int column);
char					**clear_tetri(char **src, int x, int y, int line);
void					add_param(t_tetri *tetri);
void					get_tetri(t_env **env, char *path);
int						try_put(t_env *env, t_tetri *tetri, int x, int y);
int						go_solve(t_env *env, t_tetri *tetri);
void					solve(t_env *env);
char					**malloc_out(void);
void					del_env(t_env *env);
#endif
