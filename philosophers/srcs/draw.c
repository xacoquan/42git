#include "philo.h"

static void		draw2(t_data *d, int pos)
{
	while (pos <= 40)
	{
		mvwprintw(d->win, pos, 1, "Philo #  ");
		mvwaddch(d->win, pos, 8, ft_itoa(d->philo[d->i].id)[0]);
		mvwprintw(d->win, pos + 1, 1, "STATE :");
		if (d->philo[d->i].etat == 2)
			mvwprintw(d->win, pos + 1, 8, " EAT  ");
		if (d->philo[d->i].etat == 3)
			mvwprintw(d->win, pos + 1, 8, " THINK");
		if (d->philo[d->i].etat == 4)
			mvwprintw(d->win, pos + 1, 8, " WAIT ");
		mvwprintw(d->win, pos + 2, 1, "LIFE :");
		mvwaddch(d->win, pos + 2, 8, ft_itoa(d->philo[d->i].life)[0]);
		if (d->philo[d->i].life > 9)
			mvwaddch(d->win, pos + 2, 9, ft_itoa(d->philo[d->i].life)[1]);
		else
			mvwaddch(d->win, pos + 2, 9, ' ');
		if (d->philo[d->i].life > 99)
			mvwaddch(d->win, pos + 2, 10, ft_itoa(d->philo[d->i].life)[2]);
		else
			mvwaddch(d->win, pos + 2, 10, ' ');
		d->i++;
		pos = pos + 5;
	}
}

void			*draw(void *arg)
{
	t_data		*data;
	time_t		now;
	int i;

	(void)arg;
	data = singleton_data();
	data->win = newwin(40 + 300, 40 + 300, 1, 1);
 	now = time(0);
	while (now - data->start < TIMEOUT && data->end != 0)
	{
		i = 0;
		int 
		// while (i < PHILO)
		// {
		// 	ft_putstr("id == ");
		// 	ft_putnbr(i);
		// 	ft_putstr("life == ");
		// 	ft_putnbr(data->philo[i].life);
		// 	ft_putchar('\n');
		// 	//printf("id == %d , life == %d", i, );
		// 	i++;
		// }
		ft_putchar('\n');
		data->i = 0;
		if (data->end != 0)
			remove_life(data);
		draw2(data, 9);
		wrefresh(data->win);
		usleep(1 * 1000000);
		now = time(0);
	}
	return (NULL);
}