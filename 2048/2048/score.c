/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:03:43 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 23:23:12 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_display_top(t_game *g, int len)
{
	char	*message;

	mvaddstr(len + 1, 1, g->top[len]->pseudo);
	message = ft_itoa(g->top[len]->score);
	mvaddstr(len + 1, 2 + SIZE_PSEUDO, message);
	ft_strdel(&message);
	if (g->top[len]->over)
		mvaddstr(len + 1, 15 + SIZE_PSEUDO, "Finish");
}

void	print_top(t_game *g)
{
	int		x;
	int		y;
	int		len;
	char	*message;

	getmaxyx(stdscr, y, x);
	clear();
	len = 0;
	while (g->top[len])
		len++;
	if (y < len + 2 || x < SIZE_PSEUDO + 20)
	{
		message = "window is too small";
		mvaddstr(y / 2, (x / 2) - (ft_strlen(message) / 2), message);
		return ;
	}
	len = 0;
	while (g->top[len])
	{
		ft_display_top(g, len);
		len++;
	}
}

int		ft_scorecmp(t_score *s1, t_score *s2)
{
	if (s1->score < s2->score || (s1->score == s2->score
		&& (s1->over < s2->over || (s1->over == s2->over
			&& ft_strcmp(s1->pseudo, s2->pseudo) > 0))))
		return (1);
	return (0);
}

void	ft_sort_top(t_game *g, int nbr_line)
{
	int			i;
	int			j;
	t_score		*tmp;

	i = 0;
	while (i < nbr_line - 1 && g->top[i])
	{
		j = i + 1;
		while (j < nbr_line && g->top[j])
		{
			if (ft_scorecmp(g->top[i], g->top[j]))
			{
				tmp = g->top[i];
				g->top[i] = g->top[j];
				g->top[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
