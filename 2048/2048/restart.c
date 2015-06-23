/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restart.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:03:43 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 23:23:10 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_restart(t_game *g)
{
	int		i;

	if (g->grid)
	{
		i = 0;
		while (i < g->size_g)
		{
			ft_memdel((void**)(&(g->grid[i])));
			i++;
		}
		ft_memdel((void**)(&(g->grid)));
	}
	ft_init_grid(g);
	g->end = 0;
	g->score = 0;
	g->move = 0;
	g->save = 0;
	i = 0;
	while (g->pseudo[i])
		g->pseudo[i++] = '\0';
}
