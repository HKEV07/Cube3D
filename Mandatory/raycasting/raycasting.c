/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 09:07:45 by fel-hazz          #+#    #+#             */
/*   Updated: 2023/10/07 19:37:48 by fel-hazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

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
	double	hz[4];
	double	vt[2];
	double	incr[2];
	int		dir[4];

	dir[0] = (v->angle >= 0 && v->angle < M_PI);
	dir[1] = (v->angle >= 0 && v-> angle < M_PI_2) || (v->angle > 3 * M_PI_2);
	ft_memset(dir + 2, 0, 4 * 2);
	horizental_collision(v, hz, dir, incr);
	vertical_collision(v, vt, dir, incr);
	if (!dir[2] && !dir[3])
		return ;
	decision_maker(v, vt, hz, dir);
	floor_ceiling(v, i, angle, hz);
	draw_wall(v, i, hz, dir);
}

void	horizental_collision(t_st *v, double hz[2], int dir[4], double incr[2])
{
	hz[0] = (int)(v->y) / C_S * C_S + (dir[0]) * C_S;
	hz[1] = fabs((v->y - hz[0]) / tan(v->angle));
	hz[1] = (dir[1]) * (hz[1] + v->x) + (!dir[1]) * (v->x - hz[1]);
	incr[1] = C_S * ((!dir[0]) * -1 + (dir[0]));
	incr[0] = fabs(C_S / tan(v->angle)) * ((!dir[1]) * -1 + (dir[1]));
	while (hz[0] > 0 && hz[1] > 0 && hz[0] < v->height && hz[1] < v->width)
	{
		if ((dir[0] && !ch_b(v->map[(int)(hz[0] / C_S)][(int)(hz[1] / C_S)]))
			|| (!dir[0]
				&& !ch_b(v->map[(int)(hz[0] - 1) / C_S][(int)(hz[1]) / C_S])))
		{
			dir[2] = 1;
			break ;
		}
		hz[1] += incr[0];
		hz[0] += incr[1];
	}
}

void	vertical_collision(t_st *v, double vt[2], int dir[4], double incr[2])
{
	vt[1] = (int)(v->x) / C_S * C_S + (dir[1]) * C_S;
	vt[0] = fabs((v->x - vt[1]) * tan(v->angle));
	vt[0] = (dir[0]) * (vt[0] + v->y) + (!dir[0]) * (v->y - vt[0]);
	incr[0] = C_S * ((!dir[1]) * -1 + (dir[1]));
	incr[1] = fabs(C_S * tan(v->angle)) * ((!dir[0]) * -1 + (dir[0]));
	while (vt[0] > 0 && vt[1] > 0 && vt[0]
		< v->height && vt[1] < v->width)
	{
		if ((dir[1] && !ch_b(v->map[(int)vt[0] / C_S][(int)vt[1] / C_S]))
			|| (!dir[1]
				&& !ch_b(v->map[(int)vt[0] / C_S][(int)(vt[1] - 1) / C_S])))
		{
			dir[3] = 1;
			break ;
		}
		vt[1] += incr[0];
		vt[0] += incr[1];
	}
}

void	decision_maker(t_st *v, double vt[2], double hz[2], int dir[4])
{
	if (pow((vt[0] - v->y), 2) + pow((vt[1] - v->x), 2)
		< pow((hz[0] - v->y), 2) + pow((hz[1] - v->x), 2) && dir[3])
	{
		v->ry = vt[0];
		v->rx = vt[1];
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
		v->ry = vt[0];
		v->rx = vt[1];
		dir[2] = 0;
	}
}
