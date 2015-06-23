/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 00:51:11 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 23:21:58 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "game.h"

void	loop(t_game *g)
{
	while (1)
	{
		if (g->stat == 0)
			stat_menu(g);
		else if (g->stat == 1)
			stat_game(g);
		else if (g->stat == 2)
			stat_save(g);
		else if (g->stat == 3)
			stat_continue(g);
		else if (g->stat == 4)
			stat_score(g);
		refresh();
	}
}

int		main(int ac, char **av)
{
	t_game			*g;

	if (!ft_ispow_of_two(WIN_VALUE))
		return (ft_error("WIN_VALUE is not a pow of two."));
	srand(time(NULL));
	if ((g = ft_init_game(ac, av)) == NULL)
		return (ft_error("Error malloc."));
	keypad(initscr(), true);
	start_color();
	noecho();
	curs_set(0);
	loop(g);
	ft_del_game(&g);
	return (0);
}
