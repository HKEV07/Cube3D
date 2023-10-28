/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:33:11 by fel-hazz          #+#    #+#             */
/*   Updated: 2023/10/08 12:05:48 by fel-hazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D_bonus.h"

t_tx	*find_furthest_sprite(t_st *v, t_list *walker)
{
	t_tx	*max;
	t_tx	*tmp;

	walker = v->tx;
	max = 0;
	while (walker)
	{
		tmp = walker->content;
		if (tmp->visible)
			max = walker->content;
		walker = walker->next;
	}
	if (!max)
		return (0);
	walker = v->tx;
	while (walker)
	{
		tmp = walker->content;
		if (tmp->visible && max->distance < tmp->distance)
			max = tmp;
		walker = walker->next;
	}
	return (max);
}

void	sort_sprites(t_st *v, t_list *walker, t_tx *tx)
{
	walker = v->tx;
	while (walker)
	{
		tx = find_furthest_sprite(v, v->tx);
		if (tx && tx->visible)
		{
			draw_sprite(v, tx);
			tx->visible = 0;
		}
		walker = walker->next;
	}
}

void	visible_sprite(t_st *v, t_list *walker, t_tx *tx, double f[3])
{
	while (walker)
	{
		tx = walker->content;
		f[0] = tx->x - v->x;
		f[1] = tx->y - v->y;
		tx->distance = sqrt(pow(f[1], 2) + pow(f[0], 2));
		tx->angle = normalize(atan2(f[1], f[0]));
		f[2] = normalize(tx->angle - v->angle);
		if (f[2] > M_PI)
			f[2] -= PIPI;
		f[2] = fabs(f[2]);
		tx->r_d = v->mlx->height / (2 * tan(FIELD_OF_VIEW / 2));
		tx->distance = fabs(cos(tx->angle - v->angle) * tx->distance);
		tx->size = tx->r_d * (C_S / tx->distance);
		tx->visible = (f[2] < fabs(asin((MLX_WIDTH / 2 + tx->size / 2)
						/ tx->r_d)) || f[2] < FIELD_OF_VIEW / 2);
		if (tx->type == 1)
			tx->tx = v->a[(unsigned int)(mlx_get_time() * 5) % 8];
		else if (tx->type == 2)
			tx->tx = v->b[(unsigned int)(mlx_get_time() * 5) % 8];
		else if (tx->type == 3)
			tx->tx = v->c[(unsigned int)(mlx_get_time() * 5) % 8];
		walker = walker->next;
	}
	sort_sprites(v, walker, tx);
}

void	draw_sprite2(t_st *v, t_tx *tx, double f[4], unsigned int color)
{
	int				x[2];
	unsigned char	*c;

	x[0] = (f[0] < 0) * fabs(f[0]) - 1;
	f[0] = (f[0] >= 0) * f[0] - 1;
	while (++x[0] >= 0 && ++f[0] >= 0 && f[0] < f[1])
	{
		f[2] = v->mlx->height / 2 - tx->size / 2;
		x[1] = (f[2] < 0) * fabs(f[2]) - 1;
		f[2] = f[2] * (f[2] >= 0) - 1;
		while (++x[1] >= 0 && ++f[2] >= 0 && f[2] < f[3])
		{
			c = tx->tx->pixels + (((int)(((int)x[1]) / (tx->size)
							* (tx->tx->height - 1))) * tx->tx->bytes_per_pixel
					* tx->tx->width) + ((int)(((int)x[0]) / (tx->size)
						* (tx->tx->width - 1))) * tx->tx->bytes_per_pixel;
			color = (*c << 24) | (*(c + 1) << 16)
				| (*(c + 2) << 8) | (*(c + 3));
			if (color != 3879401471 && color != 0xff00ffff && color != 0)
				if (f[2] > 0 && f[2] < v->mlx->height && f[0] > 0
					&& f[0] < v->mlx->width && tx->distance < v->ds[(int)f[0]])
					mlx_put_pixel(v->img, f[0], f[2], color);
		}
	}
}

void	draw_sprite(t_st *v, t_tx *tx)
{
	double	f[4];

	f[2] = v->mlx->height / 2 - tx->size / 2;
	f[3] = v->mlx->height / 2 + tx->size / 2; 
	f[0] = tan(normalize(tx->angle - v->angle))
		* tx->r_d + MLX_WIDTH / 2 - tx->size / 2;
	f[1] = f[0] + tx->size;
	if (f[1] > MLX_WIDTH)
		f[1] = MLX_WIDTH;
	if (f[3] > MLX_HEIGHT)
		f[3] = MLX_HEIGHT;
	draw_sprite2(v, tx, f, 0);
}
