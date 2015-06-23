/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 00:51:11 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 23:21:20 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		ft_check_up(t_game *g, int i, int j)
{
	int		k;

	k = i + 1;
	while (k < g->size_g && g->grid[k][j] == 0)
		k++;
	if (k < g->size_g && g->grid[i][j] == g->grid[k][j])
	{
		g->grid[i][j] *= 2;
		g->grid[k][j] = 0;
		g->score += g->grid[i][j];
		g->move = 1;
		return (g->grid[i][j]);
	}
	return (0);
}

int		ft_check_down(t_game *g, int i, int j)
{
	int		k;

	k = i - 1;
	while (k >= 0 && g->grid[k][j] == 0)
		k--;
	if (k >= 0 && g->grid[i][j] == g->grid[k][j])
	{
		g->grid[i][j] *= 2;
		g->grid[k][j] = 0;
		g->score += g->grid[i][j];
		g->move = 1;
		return (g->grid[i][j]);
	}
	return (0);
}

int		ft_check_left(t_game *g, int i, int j)
{
	int		k;

	k = j + 1;
	while (k < g->size_g && g->grid[i][k] == 0)
		k++;
	if (k < g->size_g && g->grid[i][j] == g->grid[i][k])
	{
		g->grid[i][j] *= 2;
		g->grid[i][k] = 0;
		g->score += g->grid[i][j];
		g->move = 1;
		return (g->grid[i][j]);
	}
	return (0);
}

int		ft_check_right(t_game *g, int i, int j)
{
	int		k;

	k = j - 1;
	while (k >= 0 && g->grid[i][k] == 0)
		k--;
	if (k >= 0 && g->grid[i][j] == g->grid[i][k])
	{
		g->grid[i][j] *= 2;
		g->grid[i][k] = 0;
		g->score += g->grid[i][j];
		g->move = 1;
		return (g->grid[i][j]);
	}
	return (0);
}
