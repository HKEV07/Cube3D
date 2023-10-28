/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 09:11:00 by fel-hazz          #+#    #+#             */
/*   Updated: 2023/10/07 18:36:43 by fel-hazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D_bonus.h"

void	mlx_move_player2(t_st *v, double p[2])
{
	if (mlx_is_key_down(v->mlx, 68))
	{
		p[0] = v->x + MOVEMENT_SPEED * cos((M_PI_2 + v->angle));
		p[1] = v->y + MOVEMENT_SPEED * sin((M_PI_2 + v->angle));
		advanced_collision(v, p);
	}
	if (mlx_is_key_down(v->mlx, 87))
	{
		p[0] = v->x + MOVEMENT_SPEED * cos(v->angle);
		p[1] = v->y + MOVEMENT_SPEED * sin(v->angle);
		advanced_collision(v, p);
	}
}

double	normalize(double angle)

{
	if (angle >= PIPI)
		angle -= PIPI;
	else if (angle < 0)
		angle += PIPI;
	return (angle);
}

void	mlx_move_player1(t_st *v, double p[2])
{
	ft_memset(p, 0, 8 * 2);
	if (mlx_is_key_down(v->mlx, 256))
		exit(0);
	if (mlx_is_key_down(v->mlx, MLX_KEY_LEFT))
		v->angle -= ROTATION_SPEED;
	if (mlx_is_key_down(v->mlx, MLX_KEY_RIGHT))
		v->angle += ROTATION_SPEED;
	if (v->angle >= PIPI)
		v->angle -= PIPI;
	else if (v->angle < 0)
		v->angle += PIPI;
	if (mlx_is_key_down(v->mlx, 65))
	{
		p[0] = v->x - MOVEMENT_SPEED * cos((M_PI_2 + v->angle));
		p[1] = v->y - MOVEMENT_SPEED * sin((M_PI_2 + v->angle));
		advanced_collision(v, p);
	}
}

void	mlx_move_player3(t_st *v, double p[2])
{
	double	f[3];

	mlx_move_player1(v, p);
	mlx_move_player2(v, p);
	if (mlx_is_key_down(v->mlx, 83))
	{
		p[0] = v->x - MOVEMENT_SPEED * cos(v->angle);
		p[1] = v->y - MOVEMENT_SPEED * sin(v->angle);
		advanced_collision(v, p);
	}
	cast_ray(v);
	visible_sprite(v, v->tx, 0, f);
	draw_map2(v);
}

void	mlx_move_player(void *param)
{
	double	p[2];
	t_st	*v;

	v = param;
	if (mlx_is_key_down(v->mlx, 70))
	{
		v->dx = 0;
		v->dy = 0;
		v->door = 1;
		usleep(80000);
		p[0] = v->x;
		p[1] = v->y;
		advanced_collision1(v, p);
		if (v->dx != 0 && v->dy != 0)
		{
			if (v->map[(int)v->dy / C_S][(int)v->dx / C_S] == 'o')
				v->map[(int)v->dy / C_S][(int)v->dx / C_S] = 'd';
			else if (v->map[(int)v->dy / C_S][(int)v->dx / C_S] == 'd')
				v->map[(int)v->dy / C_S][(int)v->dx / C_S] = 'o';
		}
		v->door = 0;
	}
	mlx_move_player3(v, p);
}
