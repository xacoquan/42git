/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:03:43 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 23:23:16 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	stat_score(t_game *g)
{
	int		press;

	print_top(g);
	press = getch();
	if (press == 'm')
		g->stat = 0;
	else if (press == 27)
		ft_del_game(&g);
}

void	stat_continue(t_game *g)
{
	int		press;

	print_game(g);
	press = getch();
	if (press == 'n' || press == 'N')
	{
		ft_restart(g);
		g->start = 0;
		g->stat = 0;
	}
	else if (press == 'y' || press == 'Y')
		g->stat = 1;
	else if (press == 27)
		ft_del_game(&g);
}

void	stat_save(t_game *g)
{
	int		press;

	print_game(g);
	press = getch();
	if (ft_isalnum(press))
		ft_pseudo_add_char(g, press);
	else if (press == 127)
		ft_pseudo_del_char(g);
	else if (press == 10)
		ft_save_pseudo(g);
	else if (press == 27)
		ft_del_game(&g);
}

void	stat_game(t_game *g)
{
	int		press;

	print_game(g);
	press = getch();
	if (press == 'm')
	{
		if (g->end == 1)
		{
			ft_restart(g);
			g->start = 0;
		}
		g->stat = 0;
	}
	else if (press == KEY_UP && g->end != 1)
		ft_move_up(g);
	else if (press == KEY_DOWN && g->end != 1)
		ft_move_down(g);
	else if (press == KEY_RIGHT && g->end != 1)
		ft_move_right(g);
	else if (press == KEY_LEFT && g->end != 1)
		ft_move_left(g);
	else if (press == 'r')
		ft_restart(g);
	else if (press == 27)
		ft_del_game(&g);
}

void	stat_menu(t_game *g)
{
	int		press;

	print_menu(g);
	press = getch();
	if (press == 'c' && g->start)
		g->stat = 1;
	else if (press == 'n')
	{
		if (!g->start)
			g->start = 1;
		else
			ft_restart(g);
		g->stat = 1;
	}
	else if (press == 's')
		g->stat = 4;
	else if (press == 27)
		ft_del_game(&g);
}
