/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:58:48 by fel-hazz          #+#    #+#             */
/*   Updated: 2023/10/07 18:36:43 by fel-hazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D_bonus.h"

void	horizental_door_collision(t_st *v, double hz[12], int dir[4])
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
			return (hz[8] = pow((hz[0] - v->y), 2) + pow((hz[1] - v->x), 2)
				, hz[10] = 1, dir[2] = 1, free(0));
		if ((dir[0] && chd(v->map[(int)(hz[0] / C_S)][(int)(hz[1] / C_S)]))
			|| (!dir[0]
				&& chd(v->map[(int)(hz[0] - 1) / C_S][(int)(hz[1]) / C_S])))
			return (dir[2] = 1, free(0));
		hz[1] += hz[6];
		hz[0] += hz[7];
	}
}

void	vertical_door_collision(t_st *v, double hz[12], int dir[4])
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
			return (hz[9] = pow((hz[4] - v->y), 2) + pow((hz[5] - v->x), 2)
				, hz[11] = 1, dir[3] = 1, free(0));
		if ((dir[1] && chd(v->map[(int)hz[4] / C_S][(int)hz[5] / C_S]))
			|| (!dir[1]
				&& chd(v->map[(int)hz[4] / C_S][(int)(hz[5] - 1) / C_S])))
			return (dir[3] = 1, free(0));
		hz[5] += hz[6];
		hz[4] += hz[7];
	}
}

void	draw_door1(t_st *v, double s[4], int dir[4], int x[7])
{
	unsigned char	*c;
	unsigned int	color;

	x[0] = (int)(((int)v->rx % C_S) / (C_S - 1.0) * (x[5] - 1));
	x[1] = (int)((s[2] - s[3]) / (s[1]) * (x[4] - 1));
	c = v->tx_dr->pixels + (x[1] * x[5] * x[6]) + x[0] * x[6];
	color = (*c << 24) | (*(c + 1) << 16) | (*(c + 2) << 8) | (*(c + 3));
	if (color != 3879401471 && color != 0xff00ffff && color != 0)
		mlx_put_pixel(v->img, dir[4], s[2], (*c << 24)
			| (*(c + 1) << 16) | (*(c + 2) << 8) | (*(c + 3)));
}

void	draw_door2(t_st *v, double s[4], int dir[4], int x[7])
{
	unsigned char	*c;
	unsigned int	color;

	x[0] = (int)(((int)v->ry % C_S) / (C_S - 1.0) * (x[5] - 1));
	x[1] = (int)(s[2] - s[3]) / (s[1]) * x[4];
	c = v->tx_dr->pixels + (x[1] * x[5] * x[6]) + x[0] * x[6];
	color = (*c << 24) | (*(c + 1) << 16) | (*(c + 2) << 8) | (*(c + 3));
	if (color != 3879401471 && color != 0xff00ffff && color != 0)
		mlx_put_pixel(v->img, dir[4], s[2], (*c << 24)
			| (*(c + 1) << 16) | (*(c + 2) << 8) | (*(c + 3)));
}

void	draw_door(t_st *v, double s[4], int dir[5])
{
	int				x[7];

	ft_set3(v, x, s, dir);
	if (!v->tx_dr)
		return ;
	while (s[0]-- > 0 && ++s[2] >= 0)
	{
		if (dir[2] && (dir[4] > 0 && s[1] > 0 && dir[4] < x[3] && s[2] < x[2]))
			draw_door1(v, s, dir, x);
		else if (dir[3] && dir[4] > 0 && s[2] > 0 
			&& dir[4] < x[3] && s[2] < x[2])
			draw_door2(v, s, dir, x);
	}
}
