/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:35:36 by fel-hazz          #+#    #+#             */
/*   Updated: 2023/10/02 05:17:54 by fel-hazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

int	main(int argc, char **argv)
{
	t_st	v;

	ft_init(&v);
	ft_exit((argc != 2) || (!ft_check_name(argv[1])), 0);
	ft_load_map1(&v, argv[1]);
	v.mlx = mlx_init(MLX_WIDTH, MLX_HEIGHT, "cube3D", 1);
	v.width = v.width * C_S;
	v.height = v.height * C_S;
	v.img = mlx_new_image(v.mlx, MLX_WIDTH, MLX_HEIGHT);
	mlx_image_to_window(v.mlx, v.img, 0, 0);
	mlx_loop_hook(v.mlx, mlx_move_player, &v);
	mlx_loop(v.mlx);
	exit(0);
}
