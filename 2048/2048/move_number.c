/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:03:43 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 23:22:58 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_up_number(t_game *g, int i, int *j)
{
	int		k;

	k = i + 1;
	while (k < g->size_g)
	{
		if (g->grid[k][*j])
		{
			g->grid[i][*j] = g->grid[k][*j];
			g->grid[k][*j] = 0;
			g->move = 1;
			(*j)--;
			return ;
		}
		k++;
	}
}

void	ft_down_number(t_game *g, int i, int *j)
{
	int		k;

	k = i - 1;
	while (k >= 0)
	{
		if (g->grid[k][*j])
		{
			g->grid[i][*j] = g->grid[k][*j];
			g->grid[k][*j] = 0;
			g->move = 1;
			(*j)--;
			return ;
		}
		k--;
	}
}

void	ft_left_number(t_game *g, int i, int *j)
{
	int		k;

	k = (*j) + 1;
	while (k < g->size_g)
	{
		if (g->grid[i][k])
		{
			g->grid[i][*j] = g->grid[i][k];
			g->grid[i][k] = 0;
			g->move = 1;
			(*j)--;
			return ;
		}
		k++;
	}
}

void	ft_right_number(t_game *g, int i, int *j)
{
	int		k;

	k = (*j) - 1;
	while (k >= 0)
	{
		if (g->grid[i][k])
		{
			g->grid[i][*j] = g->grid[i][k];
			g->grid[i][k] = 0;
			g->move = 1;
			(*j)++;
			return ;
		}
		k--;
	}
}
