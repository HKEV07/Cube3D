/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 09:11:00 by fel-hazz          #+#    #+#             */
/*   Updated: 2023/10/07 19:35:01 by fel-hazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

int	ft_check(t_st *v, double x, double y)
{
	if (x > 0 && y > 0 && x < v->width && y < v->height
		&& ch_b(v->map[(int)y / C_S][(int)x / C_S]))
		return (1);
	return (0);
}

void	advanced_collision(t_st *v, double p[3])
{
	if ((ft_check(v, v->x - C_S / 4, p[1] + C_S / 4))
		&& (ft_check(v, v->x, p[1] + C_S / 4))
		&& (ft_check(v, v->x + C_S / 4, p[1] + C_S / 4))
		&& (ft_check(v, v->x - C_S / 4, p[1]))
		&& (ft_check(v, v->x, p[1]))
		&& (ft_check(v, v->x + C_S / 4, p[1]))
		&& (ft_check(v, v->x - C_S / 4, p[1] - C_S / 4))
		&& (ft_check(v, v->x, p[1] - C_S / 4))
		&& (ft_check(v, v->x + C_S / 4, p[1] - C_S / 4)))
		v->y = p[1];
	if ((ft_check(v, p[0] + C_S / 4, v->y + C_S / 4))
		&& (ft_check(v, p[0], v->y + C_S / 4))
		&& (ft_check(v, p[0] - C_S / 4, v->y + C_S / 4))
		&& (ft_check(v, p[0] + C_S / 4, v->y))
		&& (ft_check(v, p[0], v->y))
		&& (ft_check(v, p[0] - C_S / 4, v->y))
		&& (ft_check(v, p[0] + C_S / 4, v->y - C_S / 4))
		&& (ft_check(v, p[0], v->y - C_S / 4))
		&& (ft_check(v, p[0] - C_S / 4, v->y - C_S / 4)))
		v->x = p[0];
}

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

void	mlx_move_player(void *param)
{
	double	p[2];
	t_st	*v;

	v = param;
	mlx_move_player1(v, p);
	mlx_move_player2(v, p);
	if (mlx_is_key_down(v->mlx, 83))
	{
		p[0] = v->x - MOVEMENT_SPEED * cos(v->angle);
		p[1] = v->y - MOVEMENT_SPEED * sin(v->angle);
		advanced_collision(v, p);
	}
	cast_ray(v);
}
