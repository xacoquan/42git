/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 00:51:11 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 23:21:46 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <ncurses.h>
# include <fcntl.h>
# include "libft.h"
# define N 4
# define POW 2
# define SIZE_CASE 3
# define START_W 2
# define START_H 4
# define SIZE_PSEUDO 8
# define MIN_PSEUDO 3
# define SIZE_TOP 100
# define MAX_RANDOM 32
# define MAX_SIZE 20

typedef struct	s_score
{
	char		*pseudo;
	int			score;
	int			over;
}				t_score;

typedef struct	s_game
{
	int			**grid;
	int			size_g;
	int			end;
	int			score;
	int			save;
	int			move;
	int			size_w;
	int			size_h;
	int			start;
	int			stat;
	int			fd;
	int			pow_max;
	t_score		**top;
	char		pseudo[SIZE_PSEUDO + 1];
}				t_game;

enum	e_const
{
	WIN_VALUE = 2048
};

void			ft_check_arg(t_game *g, int ac, char **av);
int				ft_check_up(t_game *g, int i, int j);
int				ft_check_down(t_game *g, int i, int j);
int				ft_check_left(t_game *g, int i, int j);
int				ft_check_right(t_game *g, int i, int j);
void			ft_del_game(t_game **g);
void			ft_puterror(t_game *g, char *message);
int				ft_error(char *err);
int				ft_pow(int n, int pow);
int				ft_ispow_of_two(int n);
int				ft_can_move(t_game *g);
void			ft_add_random(t_game *g);
void			ft_init_grid(t_game *g);
t_game			*ft_init_game(int ac, char **av);
void			print_menu(t_game *g);
int				ft_move_up(t_game *g);
int				ft_move_down(t_game *g);
int				ft_move_left(t_game *g);
int				ft_move_right(t_game *g);
void			ft_up_number(t_game *g, int i, int *j);
void			ft_down_number(t_game *g, int i, int *j);
void			ft_left_number(t_game *g, int i, int *j);
void			ft_right_number(t_game *g, int i, int *j);
int				ft_isover(t_game *g);
void			print_value(t_game *g);
void			print_grid(t_game *g);
void			print_score(t_game *g, int x);
void			print_game(t_game *g);
void			ft_pseudo_add_char(t_game *g, char c);
void			ft_pseudo_del_char(t_game *g);
void			ft_save_pseudo(t_game *g);
void			ft_restart(t_game *g);
void			print_top(t_game *g);
void			ft_sort_top(t_game *g, int nbr_line);
void			stat_score(t_game *g);
void			stat_continue(t_game *g);
void			stat_save(t_game *g);
void			stat_game(t_game *g);
void			stat_menu(t_game *g);

#endif
