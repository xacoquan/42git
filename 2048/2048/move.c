/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:03:43 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 23:29:38 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		ft_move_up(t_game *g)
{
	int		score;
	int		i;
	int		j;

	score = 0;
	g->move = 0;
	i = 0;
	while (i < g->size_g - 1)
	{
		j = 0;
		while (j < g->size_g)
		{
			if (g->grid[i][j])
				score += ft_check_up(g, i, j);
			else
				ft_up_number(g, i, &j);
			j++;
		}
		i++;
	}
	if (g->move)
		ft_add_random(g);
	return (score);
}

int		ft_move_down(t_game *g)
{
	int		score;
	int		i;
	int		j;

	score = 0;
	g->move = 0;
	i = g->size_g - 1;
	while (i > 0)
	{
		j = 0;
		while (j < g->size_g)
		{
			if (g->grid[i][j])
				score += ft_check_down(g, i, j);
			else
				ft_down_number(g, i, &j);
			j++;
		}
		i--;
	}
	if (g->move)
		ft_add_random(g);
	return (score);
}

int		ft_move_left(t_game *g)
{
	int		score;
	int		i;
	int		j;

	score = 0;
	g->move = 0;
	i = 0;
	while (i < g->size_g)
	{
		j = 0;
		while (j < g->size_g - 1)
		{
			if (g->grid[i][j])
				score += ft_check_left(g, i, j);
			else
				ft_left_number(g, i, &j);
			j++;
		}
		i++;
	}
	if (g->move)
		ft_add_random(g);
	return (score);
}

int		ft_move_right(t_game *g)
{
	int		score;
	int		i;
	int		j;

	score = 0;
	g->move = 0;
	i = 0;
	while (i < g->size_g)
	{
		j = g->size_g - 1;
		while (j > 0)
		{
			if (g->grid[i][j])
				score += ft_check_right(g, i, j);
			else
				ft_right_number(g, i, &j);
			j--;
		}
		i++;
	}
	if (g->move)
		ft_add_random(g);
	return (score);
}
