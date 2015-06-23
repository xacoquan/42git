/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:03:43 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 23:22:48 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	print_menu(t_game *g)
{
	int		x;
	int		y;
	char	*message;

	getmaxyx(stdscr, y, x);
	clear();
	if (y < 9 || x < 45)
	{
		message = "window is too small";
		mvaddstr(y / 2, (x / 2) - (ft_strlen(message) / 2), message);
		return ;
	}
	mvaddstr((y / 2) - 2, (x / 2) - 4, "ESC\t\tQUIT");
	mvaddstr((y / 2) - 1, (x / 2) - 4, "s  \t\tSCORE");
	if (g->start)
	{
		mvaddstr(y / 2, (x / 2) - 4, "c  \t\tCONTINUE");
		mvaddstr((y / 2) + 1, (x / 2) - 4, "n  \t\tNEW GAME");
	}
	else
		mvaddstr(y / 2, (x / 2) - 4, "n  \t\tNEW GAME");
}
