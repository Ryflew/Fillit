/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttabstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 03:55:28 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/12/08 02:46:07 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttabstr(char **str)
{
	size_t	i;

	if (!str)
		return ;
	i = -1;
	ft_putchar('{');
	ft_putchar('\n');
	while (str[++i])
	{
		ft_putchar('\t');
		ft_putchar('|');
		ft_putstr(str[i]);
		ft_putendl("|,");
	}
	ft_putendl("}");
}
