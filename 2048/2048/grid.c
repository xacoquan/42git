/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 00:51:11 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 23:21:49 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_init_grid(t_game *g)
{
	int		i;

	if ((g->grid = (int **)ft_memalloc(sizeof(int *) * g->size_g)) == NULL)
		return (ft_del_game(&g));
	i = 0;
	while (i < g->size_g)
	{
		if ((g->grid[i] = (int *)ft_memalloc(sizeof(int) * g->size_g)) == NULL)
			return (ft_del_game(&g));
		i++;
	}
	ft_add_random(g);
	ft_add_random(g);
}
