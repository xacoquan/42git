/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 00:51:11 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 23:21:41 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		ft_pow(int n, int pow)
{
	if (pow <= 0)
		return (1);
	if (n == 1 || n == 0)
		return (n);
	return (n * ft_pow(n, pow - 1));
}

int		ft_ispow_of_two(int n)
{
	if (n < 2 || n % 2)
		return (0);
	n /= 2;
	if (n == 1)
		return (1);
	return (ft_ispow_of_two(n));
}

int		ft_nb_zero(t_game *g)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (i < g->size_g)
	{
		j = 0;
		while (j < g->size_g)
		{
			if (!g->grid[i][j])
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int		ft_random_pow(t_game *g)
{
	int		nb;
	int		i;
	int		j;
	int		res;

	nb = rand() % 100;
	i = 0;
	j = 2;
	res = 0;
	while (i < g->pow_max - 1)
	{
		res += (100 / j) + 4;
		if (nb < res)
			return (ft_pow(2, i + 1));
		j *= 2;
		i++;
	}
	return (ft_pow(2, i + 1));
}

void	ft_add_random(t_game *g)
{
	int		i;
	int		j;
	int		nb;

	nb = ft_nb_zero(g);
	if (!nb)
		return ;
	nb = rand() % nb;
	i = 0;
	while (i < g->size_g)
	{
		j = 0;
		while (j < g->size_g)
		{
			if (!g->grid[i][j])
				nb--;
			if (nb <= 0 && !g->grid[i][j])
			{
				g->grid[i][j] = ft_random_pow(g);
				return ;
			}
			j++;
		}
		i++;
	}
}
