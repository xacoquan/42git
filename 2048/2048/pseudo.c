/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:03:43 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 23:23:06 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_pseudo_add_char(t_game *g, char c)
{
	int		i;

	i = 0;
	while (g->pseudo[i])
		i++;
	if (i < SIZE_PSEUDO)
		g->pseudo[i] = c;
}

void	ft_pseudo_del_char(t_game *g)
{
	int		i;

	i = 0;
	while (g->pseudo[i])
		i++;
	if (i > 0)
		g->pseudo[i - 1] = '\0';
}

void	ft_write_score(t_game *g)
{
	int		i;

	i = 0;
	if ((g->fd = open("scores.txt", O_WRONLY | O_CREAT, 0644)) == -1
		|| !g->top)
		return ;
	while (g->top[i])
	{
		ft_putstr_fd(g->top[i]->pseudo, g->fd);
		ft_putchar_fd(' ', g->fd);
		ft_putnbr_fd(g->top[i]->score, g->fd);
		ft_putchar_fd(' ', g->fd);
		ft_putnbr_fd(g->top[i]->over, g->fd);
		ft_putchar_fd('\n', g->fd);
		i++;
	}
	close(g->fd);
}

void	ft_save_pseudo(t_game *g)
{
	int		i;

	if (ft_strlen(g->pseudo) < MIN_PSEUDO)
		return ;
	g->save = 1;
	g->stat = 1;
	if (g->end == 2)
		g->stat = 3;
	i = 0;
	while (g->top[i])
		i++;
	g->top[i] = (t_score*)ft_memalloc(sizeof(t_score));
	g->top[i]->pseudo = ft_strdup(g->pseudo);
	g->top[i]->over = g->end - 1;
	g->top[i]->score = g->score;
	ft_sort_top(g, i + 1);
	if (i == SIZE_TOP)
	{
		ft_strdel(&(g->top[i]->pseudo));
		ft_memdel((void**)(&(g->top[i])));
	}
	ft_write_score(g);
}
