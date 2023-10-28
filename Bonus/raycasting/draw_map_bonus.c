/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:03:30 by fel-hazz          #+#    #+#             */
/*   Updated: 2023/10/08 09:44:49 by fel-hazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D_bonus.h"

void	draw_map(t_st *v)
{
	int	i;
	int	j;

	j = -1;
	while (++j < v->m_height / M_C_S)
	{
		i = -1;
		while (++i >= 0 && v->map[j][i])
		{
			if (v->map[j][i] == '1')
				draw_rectangle((t_point){i, j, 0x4869E155}, v, M_C_S);
			else if (v->map[j][i] == 'd' || v->map[j][i] == 'o')
				draw_rectangle((t_point){i, j, 0xFF69E155}, v, M_C_S);
			else if (ch_b(v->map[j][i]))
				draw_rectangle((t_point){i, j, 0XBCD7E355}, v, M_C_S);
			else
				draw_rectangle((t_point){i, j, 0}, v, M_C_S);
			if (v->map[j][i] == 'c')
				dr1(v, i, j);
			else if (v->map[j][i] == 'a')
				dr2(v, i, j);
			else if (v->map[j][i] == 'b')
				dr3(v, i, j);
		}
	}
}

void	draw_player(t_st *v)
{
	int		f[3];
	double	xx;
	double	yy;

	f[0] = MLX_WIDTH / 8.0;
	f[1] = MLX_HEIGHT / 8.0;
	f[2] = 0;
	xx = f[0] - M_C_S / 16.0;
	yy = f[1] - M_C_S / 16.0;
	draw_cube((t_point){f[0], f[1], 0x11443355}, v, M_C_S / 2);
	while (f[2] < M_C_S / 8)
	{
		bresenham(*v, (t_point){xx, yy, 0x00556688},
			(t_point){round(xx + ((M_C_S / 4) * cos(v->angle))),
			round(yy + ((M_C_S / 4) * sin(v->angle))), 0x00556688}, v->img);
		xx = ((f[0] - M_C_S / 16.0) + f[2] * cos((M_PI_2 + v->angle)));
		yy = ((f[1] - M_C_S / 16.0) + f[2] * sin(M_PI_2 + v->angle));
		f[2]++;
	}
	draw_cercle((t_point){f[0] - M_C_S / 16.0,
		f[1] - M_C_S / 16.0, 0x00555588}, M_C_S / 7, *v);
}

void	draw_map2(t_st *v)
{
	int	f[4];

	ft_memset(f, 0, 4 * 4);
	while (f[1] < MLX_HEIGHT / 4)
	{
		f[0] = 0;
		while (f[0] < MLX_WIDTH / 4)
		{
			f[2] = v->x / C_S * M_C_S - MLX_WIDTH / 8 + f[0];
			f[3] = v->y / C_S * M_C_S - MLX_HEIGHT / 8 + f[1];
			if (f[3] > 0 && f[2] > 0 && f[3] < v->m_height
				&& f[2] < v->m_width && f[0] < MLX_HEIGHT && f[1] < MLX_WIDTH)
				mlx_put_pixel(v->img, f[0], f[1], v->map_img[f[3]][f[2]]);
			else 
				mlx_put_pixel(v->img, f[0], f[1], 0);
			f[0]++;
		}
		f[1]++;
	}
	draw_player(v);
}
