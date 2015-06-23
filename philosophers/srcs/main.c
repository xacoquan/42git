#include <philo.h>

int					print_philosophers(t_params *params)
{
	size_t			i;
	ssize_t			min_life;

	min_life = MAX_LIFE;
	while (min_life > 0)
	{
		i = 0;
		while (i < PHILOSOPHERS_NB && min_life > 0)
		{
			// draw_phil(params[i]);
			// dprintf(1, "philo number %zu passing the while with %zu of life\n ", params[i].id, params[i].life);
			if (params[i].life < min_life)
				min_life = params[i]. life;
			++i;
		}
	}
	return(0);
}			

int					main(void)
{
	pthread_t		philosophers[PHILOSOPHERS_NB];
	int				ret;
	t_params		*params[PHILOSOPHERS_NB];

	init_mutex();
	init_philosophers(philosophers, params);
	ret = print_philosophers(params);
	ret = wait_philosophers(philosophers);
	ret = exit_function(ret);
	// while (42);
	return (ret);
}
