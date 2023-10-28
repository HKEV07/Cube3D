/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 09:09:30 by fel-hazz          #+#    #+#             */
/*   Updated: 2023/10/07 18:36:43 by fel-hazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D_bonus.h"

void	floor_ceiling(t_st *v, int i, double angle, double screenwall[4])
{
	double	raydistance;
	double	real_distance;
	double	t;

	real_distance = v->mlx->height / (2 * tan(FIELD_OF_VIEW / 2));
	raydistance = sqrt(pow(v->x - v->rx, 2) + pow(v->y - v->ry, 2));
	raydistance = fabs(cos(v->angle - angle) * raydistance);
	v->ds[i] = raydistance;
	screenwall[0] = real_distance * (C_S / raydistance);
	screenwall[1] = screenwall[0];
	screenwall[2] = v->mlx->height / 2 - screenwall[0] / 2;
	screenwall[3] = screenwall[2];
	t = -1;
	while (++t < screenwall[2])
	{
		if (i > 0 && t > 0 && i < v->mlx->width && t < v->mlx->height)
			mlx_put_pixel(v->img, i, t, v->cl_clr);
	}
	t = v->mlx->height / 2 + screenwall[0] / 2 - 1;
	while (++t < v->mlx->height)
	{
		if (i > 0 && t > 0 && i < v->mlx->width && t < v->mlx->height)
			mlx_put_pixel(v->img, i, t, v->fl_clr);
	}
}

mlx_texture_t	*ft_set2(t_st *v, int x[7], int dir[4], double s[4])
{
	mlx_texture_t	*tx;

	if (dir[2] && dir[0])
		tx = v->tx_no;
	else if (dir[2])
		tx = v->tx_so;
	else if (dir[1])
		tx = v->tx_ea;
	else
		tx = v->tx_we;
	x[2] = v->mlx->height;
	x[3] = v->mlx->width;
	x[4] = tx->height;
	x[5] = tx->width;
	x[6] = tx->bytes_per_pixel;
	s[2] = s[2] * (s[2] >= 0) - 1;
	s[0] = x[2] * (s[0] > x[2]) + s[0] * !(s[0] > x[2]);
	return (tx);
}

void	draw_wall(t_st *v, int i, double s[4], int dir[4])
{
	int				x[7];
	unsigned char	*c;
	mlx_texture_t	*tx;

	tx = ft_set2(v, x, dir, s);
	while (s[0]-- > 0 && ++s[2] >= 0)
	{
		if (dir[2] && (i > 0 && s[1] > 0 && i < x[3] && s[2] < x[2]))
		{
			x[0] = (int)(((int)v->rx % C_S) / (C_S - 1.0) * (x[5] - 1));
			x[1] = (int)((s[2] - s[3]) / (s[1]) * (x[4] - 1));
			c = tx->pixels + (x[1] * x[5] * x[6]) + x[0] * x[6];
			mlx_put_pixel(v->img, i, s[2], (*c << 24)
				| (*(c + 1) << 16) | (*(c + 2) << 8) | (*(c + 3)));
		}
		else if (i > 0 && s[2] > 0 && i < x[3] && s[2] < x[2])
		{
			x[0] = (int)(((int)v->ry % C_S) / (C_S - 1.0) * (x[5] - 1));
			x[1] = (int)(s[2] - s[3]) / (s[1]) * x[4];
			c = tx->pixels + (x[1] * x[5] * x[6]) + x[0] * x[6];
			mlx_put_pixel(v->img, i, s[2], (*c << 24)
				| (*(c + 1) << 16) | (*(c + 2) << 8) | (*(c + 3)));
		}
	}
}

void	clear_window(t_st *v)
{
	if (v->img)
		mlx_delete_image(v->mlx, v->img);
	v->img = mlx_new_image(v->mlx, v->mlx->width, v->mlx->height);
	mlx_image_to_window(v->mlx, v->img, 0, 0);
}
