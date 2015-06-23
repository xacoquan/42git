/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/06/09 17:40:24 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# include <config.h>
# include <pthread.h>
# include <sys/types.h>

# include <ncurses.h>
# include <string.h>
# define DELAY 100000

typedef enum	e_state
{
	EATING = 0,
	RESTING = 1,
	THINKING = 2
}				t_state;

typedef struct	s_phisolophe
{
	size_t		last_eat;
	size_t		last_sec;
	size_t		birth;
	size_t		id;
	ssize_t		life;
	t_state		state;
	int			newstate;
	int			turn;
}				t_phisolophe;

typedef struct	s_params
{
	size_t		id;
	size_t		birth;
	size_t		state;
	size_t		life;
}				t_params;

typedef struct s_data
{
	


}				t_data;

void			puterror(int output, char *str, size_t len, int out);
int				exit_function(int ret);
void			init_philosophers(pthread_t philosophers[PHILOSOPHERS_NB],
										t_params *params[PHILOSOPHERS_NB]);
int				wait_philosophers(pthread_t philosophers[PHILOSOPHERS_NB]);
void			init_mutex(void);
int				philo(void *param);
void 			print_philo(WINDOW *win, int starty, int startx, char *string, size_t j,  size_t i);
void 			hp_bar(WINDOW *win, char *str, int starty, int startx, int index);
void 			start_color1(void);
void 			init_philo(char **philosophers);
void				*draw(void *arg);
void				init_data(t_data *data, long id);
t_data				*singleton_data(void);


pthread_mutex_t g_chopsticks[PHILOSOPHERS_NB];

#endif
