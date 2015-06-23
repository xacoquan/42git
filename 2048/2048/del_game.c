/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 00:51:11 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 23:21:28 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_del_grid(t_game **g)
{
	int		i;

	if ((*g)->grid)
	{
		i = 0;
		while (i < (*g)->size_g)
		{
			ft_memdel((void**)(&((*g)->grid[i])));
			i++;
		}
		ft_memdel((void**)(&((*g)->grid)));
	}
}

void	ft_del_top(t_game **g)
{
	int		i;

	if ((*g)->top)
	{
		i = 0;
		while ((*g)->top[i])
		{
			ft_strdel(&((*g)->top[i]->pseudo));
			ft_memdel((void**)(&((*g)->top[i])));
			i++;
		}
		ft_memdel((void**)(&((*g)->top)));
	}
}

void	ft_del_game(t_game **g)
{
	close((*g)->fd);
	ft_del_grid(g);
	ft_del_top(g);
	ft_memdel((void**)g);
	clear();
	clrtoeol();
	endwin();
	exit(0);
}
