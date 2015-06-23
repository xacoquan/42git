/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 00:51:11 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 23:21:54 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		ft_get_top(t_game *g, char **tab)
{
	int		i;

	i = 0;
	while (ft_isalnum(tab[0][i]) && i < SIZE_PSEUDO)
		i++;
	if (tab[0][i] || i < MIN_PSEUDO)
		return (0);
	i = 0;
	while (ft_isdigit(tab[1][i]))
		i++;
	if (tab[1][i])
		return (0);
	if (!ft_isdigit(tab[2][0]) || tab[2][1] || tab[2][0] > '1')
		return (0);
	i = 0;
	while (g->top[i])
		i++;
	if ((g->top[i] = (t_score*)ft_memalloc(sizeof(t_score))) == NULL)
		return (0);
	g->top[i]->pseudo = ft_strdup(tab[0]);
	g->top[i]->score = ft_atoi(tab[1]);
	g->top[i]->over = tab[2][0] - '0';
	return (1);
}

int		ft_fill_top(t_game *g, char *line)
{
	char	**tab;
	int		i;
	int		len;
	int		ret;

	if ((tab = ft_strsplit(line, ' ')) == NULL)
		return (0);
	len = 0;
	while (tab[len])
		len++;
	if (len == 3)
		ret = ft_get_top(g, tab);
	if (tab)
	{
		i = 0;
		while (tab[i])
			ft_memdel((void**)&(tab[i++]));
		ft_memdel((void**)&tab);
	}
	return (ret);
}

void	ft_init_top(t_game *g)
{
	char	*line;
	int		nbr_line;
	int		ret;

	g->top = (t_score **)ft_memalloc(sizeof(t_score *) * (SIZE_TOP + 1));
	if ((g->fd = open("scores.txt", O_RDONLY | O_CREAT, 0644)) == -1 || !g->top)
		return (ft_del_game(&g));
	nbr_line = 0;
	ret = 1;
	while (ret && get_next_line(g->fd, &line) > 0 && nbr_line < SIZE_TOP)
	{
		ret = ft_fill_top(g, line);
		nbr_line++;
		ft_strdel(&line);
	}
	close(g->fd);
	ft_sort_top(g, nbr_line);
}

t_game	*ft_init_game(int ac, char **av)
{
	t_game	*g;

	if ((g = (t_game *)ft_memalloc(sizeof(t_game))) == NULL)
		return (g);
	g->size_g = N;
	g->pow_max = POW;
	if (ac > 1)
		ft_check_arg(g, ac, av);
	ft_init_grid(g);
	ft_init_top(g);
	return (g);
}
