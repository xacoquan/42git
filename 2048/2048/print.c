/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:03:43 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 23:23:04 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	print_value(t_game *g)
{
	int		i;
	int		j;
	int		x;
	int		y;
	char	*message;

	i = 0;
	while (i < g->size_g)
	{
		j = 0;
		while (j < g->size_g)
		{
			if (g->grid[i][j])
				message = ft_itoa(g->grid[i][j]);
			else
				message = ft_strdup("");
			x = (g->size_w * j) + (g->size_w / 2) + START_W;
			y = (g->size_h * i) + (g->size_h / 2) + START_H;
			mvaddstr(y, x - (ft_strlen(message) / 2), message);
			ft_strdel(&message);
			j++;
		}
		i++;
	}
}

void	print_grid(t_game *g)
{
	int		i;
	int		j;

	i = 0;
	while (i <= g->size_h * g->size_g)
	{
		j = 0;
		while (j <= g->size_w * g->size_g)
		{
			if (!(i % (g->size_h)) && !(j % (g->size_w)))
				mvaddstr(i + START_H, j + START_W, "+");
			else if (!(i % (g->size_h)))
				mvaddstr(i + START_H, j + START_W, "-");
			else if (!(j % (g->size_w)))
				mvaddstr(i + START_H, j + START_W, "|");
			j++;
		}
		i++;
	}
}

void	print_score(t_game *g, int x)
{
	char	*score;

	score = ft_itoa(g->score);
	mvaddstr(1, x - 17, "score: ");
	mvaddstr(1, x - START_W - ft_strlen(score), score);
	ft_strdel(&score);
	if (g->top[0])
	{
		score = ft_itoa(g->top[0]->score);
		mvaddstr(2, x - 26, "meilleur score: ");
		mvaddstr(2, x - START_W - ft_strlen(score), score);
		ft_strdel(&score);
	}
}

void	print_help(t_game *g, int y)
{
	mvaddstr(1, START_W, "ESC\tQUIT");
	if (g->stat == 2)
	{
		mvaddstr(y - 2, START_W, "Enter your pseudo: ");
		mvaddstr(y - 2, START_W + 19, g->pseudo);
	}
	else if (g->stat == 1)
	{
		mvaddstr(2, START_W, "m\tMENU");
		mvaddstr(3, START_W, "r\tRESTART");
	}
	else if (g->stat == 3)
		mvaddstr(2, START_W, "CONTINUE?(y/n)");
}

void	print_game(t_game *g)
{
	int			x;
	int			y;
	char		*message;

	getmaxyx(stdscr, y, x);
	clear();
	g->size_h = (y - (2 * START_H)) / g->size_g;
	g->size_w = (x - (2 * START_W)) / g->size_g;
	if (g->size_w < SIZE_CASE || g->size_h < SIZE_CASE)
	{
		message = "window is too small";
		mvaddstr(y / 2, (x / 2) - (ft_strlen(message) / 2), message);
		return ;
	}
	print_value(g);
	print_score(g, x);
	print_grid(g);
	ft_isover(g);
	message = "";
	if (g->end == 2)
		message = "YOU WIN";
	else if (g->end == 1)
		message = "GAME OVER";
	mvaddstr(1, (x / 2) - (ft_strlen(message) / 2), message);
	print_help(g, y);
}
