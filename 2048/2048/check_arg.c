/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 00:51:11 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 23:21:15 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_check_p(t_game *g, char *num)
{
	int		i;

	i = 0;
	while (ft_isdigit(num[i]))
		i++;
	if (num[i])
	{
		ft_putstr_fd(num, 2);
		ft_putendl_fd(" is not a number.", 2);
		ft_puterror(g, "usage: ./game_2048 [-n size] [-p pow_max_random]");
	}
	g->pow_max = ft_atoi(num);
	if (g->pow_max < 2)
	{
		ft_putstr_fd(num, 2);
		ft_putendl_fd(" is too small.", 2);
		ft_puterror(g, "usage: ./game_2048 [-n size] [-p pow_max_random]");
	}
	if (g->pow_max >= WIN_VALUE / MAX_RANDOM)
	{
		ft_putstr_fd(num, 2);
		ft_putendl_fd(" is too big.", 2);
		ft_puterror(g, "usage: ./game_2048 [-n size] [-p pow_max_random]");
	}
}

void	ft_check_n(t_game *g, char *num)
{
	int		i;

	i = 0;
	while (ft_isdigit(num[i]))
		i++;
	if (num[i])
	{
		ft_putstr_fd(num, 2);
		ft_putendl_fd(" is not a number.", 2);
		ft_puterror(g, "usage: ./game_2048 [-n size] [-p pow_max_random]");
	}
	g->size_g = ft_atoi(num);
	if (g->size_g < 4)
	{
		ft_putstr_fd(num, 2);
		ft_putendl_fd(" is too small.", 2);
		ft_puterror(g, "usage: ./game_2048 [-n size] [-p pow_max_random]");
	}
	if (g->size_g > MAX_SIZE)
	{
		ft_putstr_fd(num, 2);
		ft_putendl_fd(" is too big.", 2);
		ft_puterror(g, "usage: ./game_2048 [-n size] [-p pow_max_random]");
	}
}

void	ft_check_arg(t_game *g, int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-n") && ++i < ac)
			ft_check_n(g, av[i]);
		else if (!ft_strcmp(av[i], "-p") && ++i < ac)
			ft_check_p(g, av[i]);
		else
			ft_puterror(g, "usage: ./game_2048 [-n size] [-p pow_max_random]");
		i++;
	}
}
