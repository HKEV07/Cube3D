/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 02:25:47 by fel-hazz          #+#    #+#             */
/*   Updated: 2023/10/07 19:01:16 by fel-hazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D_bonus.h"

void	ft_init(t_st *v)
{
	v->cl_clr = -1;
	v->fl_clr = -1;
	v->tx_ea = 0;
	v->tx_no = 0;
	v->tx_so = 0;
	v->tx_we = 0;
	v->map = 0;
	v->height = 0;
	v->width = 0;
	v->x = 0;
	v->y = 0;
	v->img = 0;
	v->mlx = 0;
	load_animated_sprites(v);
	protect_sprites(v);
}

void	ft_load_color1(t_st *v, int var[2], char buff[1])
{
	unsigned int	rgb[5];

	ft_exit((v->fl_clr != -1), v);
	ft_memset(rgb, 0, 5 * 4);
	while (1)
	{
		var[1] = read(var[0], buff, 1);
		ft_exit((var[1] < 0 || rgb[4] >= 3 || rgb[3] >= 3), v);
		if (var[0] == 0 || buff[0] == '\n')
			break ;
		if (buff[0] == ' ')
			continue ;
		if (buff[0] <= '9' && buff[0] >= '0')
			rgb[rgb[3]] = rgb[rgb[3]] * 10 + buff[0] - 48;
		else if (((buff[0] == ',' && ++rgb[4])))
			rgb[3]++;
		else
			ft_exit(1, v);
		ft_exit((rgb[rgb[3]] > 255 || rgb[rgb[3]] < 0), v);
	}
	ft_exit((rgb[3] != 2), v);
	v->fl_clr = (rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | 0xFF);
}

void	ft_load_color2(t_st *v, int var[2], char buff[1])
{
	unsigned int	rgb[5];

	ft_exit((v->cl_clr != -1), v);
	ft_memset(rgb, 0, 5 * 4);
	while (1)
	{
		var[1] = read(var[0], buff, 1);
		ft_exit((var[1] < 0 || rgb[4] >= 3 || rgb[3] >= 3), v);
		if (var[0] == 0 || buff[0] == '\n')
			break ;
		if (buff[0] == ' ')
			continue ;
		if (buff[0] <= '9' && buff[0] >= '0')
			rgb[rgb[3]] = rgb[rgb[3]] * 10 + buff[0] - 48;
		else if (((buff[0] == ',' && ++rgb[4])))
			rgb[3]++;
		else
			ft_exit(1, v);
		ft_exit((rgb[rgb[3]] > 255 || rgb[rgb[3]] < 0), v);
	}
	ft_exit((rgb[3] != 2), v);
	v->cl_clr = (rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | 0xFF);
}

void	ft_exit(int condition, t_st *v)
{
	if (condition)
	{
		(void ) v;
		write(2, "Error\n", 6);
		exit(1);
	}
}
