/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:00:52 by fel-hazz          #+#    #+#             */
/*   Updated: 2023/10/08 11:00:49 by fel-hazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D_bonus.h"

void	load_animated_sprites(t_st *v)
{
	v->tx = 0;
	v->a[0] = mlx_load_png("./Bonus/animation/1.png");
	v->a[1] = mlx_load_png("./Bonus/animation/2.png");
	v->a[2] = mlx_load_png("./Bonus/animation/3.png");
	v->a[3] = mlx_load_png("./Bonus/animation/4.png");
	v->a[4] = mlx_load_png("./Bonus/animation/5.png");
	v->a[5] = mlx_load_png("./Bonus/animation/6.png");
	v->a[6] = mlx_load_png("./Bonus/animation/7.png");
	v->a[7] = mlx_load_png("./Bonus/animation/8.png");
	v->b[0] = mlx_load_png("./Bonus/animation1/1.png");
	v->b[1] = mlx_load_png("./Bonus/animation1/2.png");
	v->b[2] = mlx_load_png("./Bonus/animation1/3.png");
	v->b[3] = mlx_load_png("./Bonus/animation1/4.png");
	v->b[4] = mlx_load_png("./Bonus/animation1/5.png");
	v->b[5] = mlx_load_png("./Bonus/animation1/6.png");
	v->b[6] = mlx_load_png("./Bonus/animation1/7.png");
	v->b[7] = mlx_load_png("./Bonus/animation1/8.png");
	v->c[0] = mlx_load_png("./Bonus/animation2/1.png");
	v->c[1] = mlx_load_png("./Bonus/animation2/2.png");
	v->c[2] = mlx_load_png("./Bonus/animation2/3.png");
	v->c[3] = mlx_load_png("./Bonus/animation2/4.png");
	v->c[4] = mlx_load_png("./Bonus/animation2/5.png");
	v->c[5] = mlx_load_png("./Bonus/animation2/6.png");
	v->c[6] = mlx_load_png("./Bonus/animation2/7.png");
	v->c[7] = mlx_load_png("./Bonus/animation2/8.png");
}

void	ft_init2(t_st *v)
{
	int	i;

	mlx_set_cursor_mode(v->mlx, MLX_MOUSE_HIDDEN);
	v->m_width = v->width * M_C_S;
	v->m_height = v->height * M_C_S;
	v->door = 0;
	v->map_img = malloc(sizeof(unsigned int *) * v->m_height);
	{
		i = 0;
		while (i < v->m_height)
		{
			v->map_img[i] = malloc(sizeof(unsigned int) * v->m_width);
			i++;
		}
	}
	v->width = v->width * C_S;
	v->height = v->height * C_S;
	v->tx_dr1 = mlx_load_png("./Bonus/walls/door.png");
	if (!v->tx_dr1)
		exit(1);
	v->tx_dr2 = 0;
	v->tx_dr = v->tx_dr1;
	v->img = mlx_new_image(v->mlx, MLX_WIDTH, MLX_HEIGHT);
	mlx_image_to_window(v->mlx, v->img, 0, 0);
}

void	draw_rectangle(t_point p, t_st *v, int size)
{
	int				i;
	int				j;

	j = p.y * size ;
	while (j < p.y * size + size)
	{
		i = p.x * size ;
		while (i < p.x * size + size)
		{
			v->map_img[j][i] = p.c;
			i++;
		}
		j++;
	}
}

void	draw_cercle(t_point a, int r, t_st v)
{
	t_point	x;
	double	angle;
	double	xx;
	double	yy;

	angle = 0;
	while (angle < 2 * M_PI)
	{
		xx = r * cos(angle) + a.x;
		yy = r * sin(angle) + a.y;
		x.x = xx;
		x.y = yy;
		x.c = a.c;
		bresenham(v, x, a, v.img);
		angle += 0.001;
	}
}

void	draw_cube(t_point p, t_st *v, int size)
{
	int				i;
	int				j;

	j = p.y - size / 2;
	while (j < p.y + size / 2)
	{
		i = p.x - size / 2;
		while (i < p.x + size / 2)
		{
			if (j > 0 && i > 0 && j < MLX_HEIGHT && i < MLX_WIDTH)
				mlx_put_pixel(v->img, i, j, p.c);
			i++;
		}
		j++;
	}
}
