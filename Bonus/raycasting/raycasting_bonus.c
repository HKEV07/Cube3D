/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 09:07:45 by fel-hazz          #+#    #+#             */
/*   Updated: 2023/10/07 18:36:43 by fel-hazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D_bonus.h"

void	cast_ray(t_st *v)
{
	double	startangle;
	double	angleincre;
	double	angle;
	int		i;

	i = -1;
	angle = v->angle;
	startangle = v->angle - (FIELD_OF_VIEW / 2);
	angleincre = FIELD_OF_VIEW / v->mlx->width;
	v->angle = startangle;
	clear_window(v);
	while (++i < v->mlx->width)
	{
		if (v->angle >= PIPI)
			v->angle -= PIPI;
		if (v->angle < 0)
			v->angle += PIPI;
		cast_ray1(v, i, angle);
		v->angle += angleincre;
	}
	v->angle = angle;
}

void	cast_ray1(t_st *v, int i, double angle)
{
	double	hz[12];
	int		dir[5];

	hz[10] = 0;
	hz[11] = 0;
	dir[0] = (v->angle >= 0 && v->angle < M_PI);
	dir[1] = (v->angle >= 0 && v-> angle < M_PI_2) || (v->angle > 3 * M_PI_2);
	ft_memset(dir + 2, 0, 4 * 2);
	horizental_collision(v, hz, dir);
	vertical_collision(v, hz, dir);
	if (!dir[2] && !dir[3])
		return ;
	decision_maker(v, hz, dir);
	floor_ceiling(v, i, angle, hz);
	draw_wall(v, i, hz, dir);
	ft_memset(dir + 2, 0, 4 * 2);
	horizental_door_collision(v, hz, dir);
	vertical_door_collision(v, hz, dir);
	if (door_decision_maker(v, hz, dir))
		return ;
	calculate(v, angle, hz, i);
	dir[4] = i;
	draw_door(v, hz, dir);
}

void	horizental_collision(t_st *v, double hz[8], int dir[4])
{
	hz[0] = (int)(v->y) / C_S * C_S + (dir[0]) * C_S;
	hz[1] = fabs((v->y - hz[0]) / tan(v->angle));
	hz[1] = (dir[1]) * (hz[1] + v->x) + (!dir[1]) * (v->x - hz[1]);
	hz[7] = C_S * ((!dir[0]) * -1 + (dir[0]));
	hz[6] = fabs(C_S / tan(v->angle)) * ((!dir[1]) * -1 + (dir[1]));
	while (hz[0] > 0 && hz[1] > 0 && hz[0] < v->height && hz[1] < v->width)
	{
		if ((dir[0] && !ch_b(v->map[(int)(hz[0] / C_S)][(int)(hz[1] / C_S)]))
			|| (!dir[0]
				&& !ch_b(v->map[(int)(hz[0] - 1) / C_S][(int)(hz[1]) / C_S])))
		{
			dir[2] = 1;
			break ;
		}
		hz[1] += hz[6];
		hz[0] += hz[7];
	}
}

void	vertical_collision(t_st *v, double hz[8], int dir[4])
{
	hz[5] = (int)(v->x) / C_S * C_S + (dir[1]) * C_S;
	hz[4] = fabs((v->x - hz[5]) * tan(v->angle));
	hz[4] = (dir[0]) * (hz[4] + v->y) + (!dir[0]) * (v->y - hz[4]);
	hz[6] = C_S * ((!dir[1]) * -1 + (dir[1]));
	hz[7] = fabs(C_S * tan(v->angle)) * ((!dir[0]) * -1 + (dir[0]));
	while (hz[4] > 0 && hz[5] > 0 && hz[4]
		< v->height && hz[5] < v->width)
	{
		if ((dir[1] && !ch_b(v->map[(int)hz[4] / C_S][(int)hz[5] / C_S]))
			|| (!dir[1]
				&& !ch_b(v->map[(int)hz[4] / C_S][(int)(hz[5] - 1) / C_S])))
		{
			dir[3] = 1;
			break ;
		}
		hz[5] += hz[6];
		hz[4] += hz[7];
	}
}

void	decision_maker(t_st *v, double hz[6], int dir[4])
{
	if (pow((hz[4] - v->y), 2) + pow((hz[5] - v->x), 2)
		< pow((hz[0] - v->y), 2) + pow((hz[1] - v->x), 2) && dir[3])
	{
		v->ry = hz[4];
		v->rx = hz[5];
		dir[2] = 0;
	}
	else if (dir[2])
	{
		v->ry = hz[0];
		v->rx = hz[1];
		dir[3] = 0;
	}
	else if (dir[3])
	{
		v->ry = hz[4];
		v->rx = hz[5];
		dir[2] = 0;
	}
}
