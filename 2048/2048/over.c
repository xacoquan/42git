/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:03:43 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 23:23:01 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		ft_win(t_game *g)
{
	int		i;
	int		j;

	i = 0;
	while (i < g->size_g)
	{
		j = 0;
		while (j < g->size_g)
		{
			if (g->grid[i][j] == WIN_VALUE)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_can_move(t_game *g)
{
	int		i;
	int		j;

	i = 0;
	while (i < g->size_g)
	{
		j = 0;
		while (j < g->size_g)
		{
			if (!g->grid[i][j] || (i < g->size_g - 1
				&& g->grid[i][j] == g->grid[i + 1][j])
				|| (j < g->size_g - 1 && g->grid[i][j] == g->grid[i][j + 1]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_isover(t_game *g)
{
	if (!ft_can_move(g))
		g->end = 1;
	if (ft_win(g))
		g->end = 2;
	if (!g->save && g->end)
		g->stat = 2;
	return (g->end);
}
