/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:35:36 by fel-hazz          #+#    #+#             */
/*   Updated: 2023/10/07 18:55:31 by fel-hazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D_bonus.h"

void	ft_set(t_point *a, t_point b)
{
	a->x = b.x;
	a->y = b.y;
	a->c = b.c;
}

void	ft_setup(t_point *a, t_point *b, int *var)
{
	t_point	x;

	ft_memset(var, 0, 8 * 4);
	if (abs(a->x - b->x) < abs(a->y - b->y))
	{
		ft_set(a, (t_point){a->y, a->x, a->c});
		ft_set(b, (t_point){b->y, b->x, b->c});
		var[0] = 1;
	}
	if (a->x > b->x)
	{
		ft_set(&x,*a);
		ft_set(a, *b);
		ft_set(b, x);
	}
	var[1] = b->x - a->x;
	var[2] = b->y - a->y;
	var[3] = -1;
	if ((var[1] >= 0 && var[2] >= 0) || (var[1] < 0 && var[2] < 0))
		var[3] = 1;
	var[4] = 2 * var[2] - (var[3] * var[1]);
	var[5] = var[1];
}

void	bresenham(t_st v, t_point a, t_point b, mlx_image_t *img)
{
	int	var[8];

	ft_setup(&a, &b, var);
	while (var[5]-- >= 0)
	{
		var[6] = a.y * var[0] + a.x * !var[0];
		var[7] = a.y * !var[0] + a.x * var[0];
		if ((var[6] < v.mlx->width && var[7]
				< v.mlx->height && var[6] > 0 && var[7] > 0))
		{
			mlx_put_pixel(img, var[6], var[7], a.c);
			mlx_put_pixel(img, var[6] + 1, var[7], a.c);
			mlx_put_pixel(img, var[6] + 1, var[7] + 1, a.c);
			mlx_put_pixel(img, var[6], var[7] + 1, a.c);
		}
		if ((var[4] > 0 && var[3] == 1) || (var[4] < 0 && var[3] == -1))
		{
			var[4] += -2 * var[1] * var[3];
			a.y += var[3];
		}
		var[4] += 2 * var[2];
		a.x++;
	}
}

void	mouse_hook(double xpos, double ypos, void *param)
{
	t_st	*v;

	v = param;
	(void) ypos;
	if (xpos > v->mlx->width / 2 + 10)
		v->angle += ROTATION_SPEED ;
	else if (xpos < v->mlx->width / 2 - 10)
		v->angle -= ROTATION_SPEED ;
	if (v->angle >= PIPI)
		v->angle -= PIPI;
	else if (v->angle < 0)
		v->angle += PIPI;
	mlx_set_mouse_pos(v->mlx, MLX_WIDTH / 2, MLX_HEIGHT / 2);
}

int	main(int argc, char **argv)
{
	t_st	v;

	ft_init(&v);
	ft_exit((argc != 2) || (!ft_check_name(argv[1])), 0);
	ft_load_map1(&v, argv[1]);
	v.mlx = mlx_init(MLX_WIDTH, MLX_HEIGHT, "cube3D", 1);
	ft_init2(&v);
	draw_map(&v);
	mlx_loop_hook(v.mlx, mlx_move_player, &v);
	mlx_cursor_hook(v.mlx, mouse_hook, &v);
	mlx_loop(v.mlx);
	exit(0);
}
