/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 15:28:09 by xacoquan          #+#    #+#             */
/*   Updated: 2015/06/18 00:07:51 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>
#include <stdio.h>

void	ft_draw_h(double derr, t_env *data, t_vector *p1, t_vector *p2)
{
	int		x;
	int		y;
	double	err;

	x = p1->newx;
	y = p1->newy;
	err = 0;
	while (x < p2->newx)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, 0x00ff00);
		err += derr;
		if (err > 0.5)
		{
			y += (p1->newy < p2->newy) ? 1 : -1;
			err -= 1.0;
		}
		x++;
	}
}

void	ft_draw_l(double derr, t_env *data, t_vector *p1, t_vector *p2)
{
	int		x;
	int		y;
	double	err;

	x = p1->newx;
	y = p1->newy;
	err = 0;
	while (y < p2->newy)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, 0xff0000);
		err += derr;
		if (err > 0.5)
		{
			x += (p1->newx < p2->newx) ? 1 : -1;
			err -= 1.0;
		}
		y++;
	}
}

void	draw_line(t_vector *p1, t_vector *p2, t_env *data)
{
	double	dx;
	double	dy;

	dx = abs(p2->newx - p1->newx);
	dy = abs(p2->newy - p1->newy);
	if (dx > dy && (p1->newx > p2->newx))
		draw_line(p2, p1, data);
	else if (dx > dy)
		ft_draw_h(dy / dx, data, p1, p2);
	else if (p1->newy > p2->newy)
		draw_line(p2, p1, data);
	else
		ft_draw_l(dx / dy, data, p1, p2);
}

void ft_apply_mtomap(t_matrix *m, t_env *e)
{
	unsigned int x;
	unsigned int y;

 
	y = 0;
	while ((e->tab)[y])
	{
		x = 0;
		while ((e->tab)[y][x])
		{
			(e->tab)[y][x] = vector_matrix(m, (e->tab)[y][x]);
			x++;
		}
		y++;
	}
}

void	draw(t_env *e)
{
	unsigned int	x;
	unsigned int	y;
	t_matrix		*m;

	y = 0;
	m = e->m;
	while ((e->tab)[y])
	{
		x = 0;
		while ((e->tab)[y][x])
		{
			(e->tab)[y][x] = vector_matrix(e->m, (e->tab)[y][x]);
			(e->tab)[y][x]->newx = (e->tab)[y][x]->x;
			(e->tab)[y][x]->newy = (e->tab)[y][x]->y;
			(e->tab)[y][x]->newx = (int)(e->tab[y][x])->x + WIDTH / 2;
			(e->tab)[y][x]->newy = (int)(e->tab[y][x])->y + HEIGHT / 2;
			if (y > 0)
				draw_line(e->tab[y - 1][x], e->tab[y][x], e);
			if (x > 0)
				draw_line(e->tab[y][x - 1], e->tab[y][x], e);
			x++;
		}
		y++;
	}
}

int		expose_hook(t_env *e)
{
	draw(e);
	return (0);
} 
 // 
int 	key_hook(int keycode, t_env *e)
{
	 free(e->mt);
	 free(e->sc);
	 free(e->rx);
	 free(e->ry);
	 free(e->rz);
	
   	e->m = m_ident();
	if (keycode == 65307)
		exit (0);
	else if (keycode == 45) // -
	{
		e->m = mult_matrix(e->m, ft_Sc(9.0 / 10.0, 9.0 / 10.0, 9.0 / 10.0));
		mlx_clear_window(e->mlx, e->win);
		draw(e);
	}
	else if (keycode == 61) // '+'
	{
		e->m = mult_matrix(e->m, ft_Sc(10.0 / 9.0, 10.0 / 9.0, 10.0 / 9.0));
		mlx_clear_window(e->mlx, e->win);
		draw(e);
	}
	else if (keycode == 114) // 'r'
	{
		e->m = mult_matrix(e->m, ft_Rx(.5));
		mlx_clear_window(e->mlx, e->win);
		draw(e);
	}
	else if (keycode == 116) // 't'
	{
		e->m = mult_matrix(e->m, ft_Rx(-.5));
		mlx_clear_window(e->mlx, e->win);
		draw(e);
	}
	else if (keycode == 102) // 'f'
	{
		e->m = mult_matrix(e->m, ft_Ry(.5));
		mlx_clear_window(e->mlx, e->win);
		draw(e);
	}
	else if (keycode == 103) // 'g'
	{
		e->m = mult_matrix(e->m, ft_Ry(-.5));
		mlx_clear_window(e->mlx, e->win);
		draw(e);
	}
	else if (keycode == 118) // 'v'
	{
		e->m = mult_matrix(e->m, ft_Rz(.5));
		mlx_clear_window(e->mlx, e->win);
		draw(e);
	}
	else if (keycode == 98) // 'b'
	{
		e->m = mult_matrix(e->m, ft_Rz(-.5));
		mlx_clear_window(e->mlx, e->win);
		draw(e);
		free(e);
	}
	else if (keycode == 65362) // 'haut'
	{
		e->m = mult_matrix(e->m, ft_trans(0, -10.0, 0));
		mlx_clear_window(e->mlx, e->win);
		draw(e);
	}
	else if (keycode == 65364) // 'bas'
	{
		e->m = mult_matrix(e->m, ft_trans(0, 10.0, 0));
		mlx_clear_window(e->mlx, e->win);

                                                                                                                     		draw(e);
	}
	else if (keycode == 65361) // 'gauche'
	{
		e->m = mult_matrix(e->m, ft_trans(-10.0, 0, 0));
		mlx_clear_window(e->mlx, e->win);
		draw(e);
	}
	else if (keycode == 65363) // 'droite'
	{
		e->m = mult_matrix(e->m, ft_trans(10.0, 0, 0));
		mlx_clear_window(e->mlx, e->win);
		draw(e);
	}
	return (0);
}

void		ft_init(t_env *e)
{
	e->m = m_ident();
}

int main(int ac, char **av)
{
	t_env	*e;

	e = (t_env *)ft_memalloc(sizeof(t_env));
	exit (0);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 2000, 2000, "42");
	ft_get_data(ac, av, e);
	ft_init(e);
	mlx_hook(e->win, 2, 3, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
	return (0);		
}
