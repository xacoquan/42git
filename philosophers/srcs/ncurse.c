/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 22:03:34 by xacoquan          #+#    #+#             */
/*   Updated: 2015/06/09 17:40:47 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "config.h"
#include <unistd.h>

void	draw_phil(t_params *params)
{
	// params = (t_params)
	// char *philosophers[7];
	int max_y;
	int max_x;
	// int i;

	max_x = 0;
	max_y = 0;
	// i = MAX_LIFE;

	// init_phileo(philosophers);
	char *str;
	str = "philo number";

	initscr();
 	start_color1();
   
    	getmaxyx(stdscr, max_y, max_x);
    	clear();
    	// str = (char *)malloc(sizeof(char) // philo id philo chop, philo stat)
		mvwprintw(stdscr, MAX_Y, 0, "%s%zi  %zi", str,params->id, params->life);
 		// mvwprintw(stdscr, MAX_Y, 0, "%s", "test4204204204204204204");
		// print_philo(stdscr, MAX_Y, 0, str, philo.id, philo.life);
		refresh();
		usleep(DELAY);
		// break ;
	
	endwin();
}
	
void print_philo(WINDOW *win, int max_y, int max_x, char *string, size_t j,  size_t i)
{

	int x;
	int y;
	y = max_y;
    x = max_x;
	attron(COLOR_PAIR(3));
	mvwprintw(win, y, x, " %s%d%d", string,j,i);
	attroff(COLOR_PAIR(3));
	// hp_bar(win, string, y, x, i);
}

void hp_bar(WINDOW *win, char *str, int y, int x, int index)
{
	const size_t	len = ((int)(index * PERCENT));
	size_t			i;
	size_t			j;

	j = (index * 100) / MAX_LIFE;

	x +=  MAX_NAME_LEN;
	i = 0;
	attron(COLOR_PAIR(2));
	while (i != len)
		mvwprintw(win, y, x + i++, "|");
		mvwprintw(win, y, x + MAX_LIFE_LEN /2, "%d%%", j);
	attroff(COLOR_PAIR(2));
	attron(COLOR_PAIR(4));
	while (i < MAX_LIFE_LEN)
		mvwprintw(win, y, x + i++, "-");
	if (len < MAX_LIFE_LEN / 2 + 3)
		mvwprintw(win, y, x + MAX_LIFE_LEN /2, "%d%%", j);
	attroff(COLOR_PAIR(4));
}

void init_philo(char **philosophers)
{
	philosophers[0] = strdup("PHILO [1]  ");
	philosophers[1] = strdup("PHILO [2]  ");
	philosophers[2] = strdup("PHILO [3]  ");
	philosophers[3] = strdup("PHILO [4]  ");
	philosophers[4] = strdup("PHILO [5]  ");
	philosophers[5] = strdup("PHILO [6]  ");
	philosophers[6] = strdup("PHILO [7]  ");
}

void start_color1(void)
{
	start_color();
	init_pair(0, COLOR_RED, COLOR_YELLOW);
	init_pair(1, COLOR_GREEN,COLOR_GREEN);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);
	init_pair(3, COLOR_BLACK,  COLOR_BLUE);
	init_pair(4, COLOR_BLACK, COLOR_RED);
}
