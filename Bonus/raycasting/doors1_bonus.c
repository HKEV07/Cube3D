/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:31:18 by fel-hazz          #+#    #+#             */
/*   Updated: 2023/10/07 19:00:19 by fel-hazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D_bonus.h"

void	calculate(t_st *v, double angle, double screenwall[4], int i)
{
	double	raydistance;
	double	real_distance;

	real_distance = v->mlx->height / (2 * tan(FIELD_OF_VIEW / 2));
	raydistance = sqrt(pow(fabs(v->x - v->rx), 2) + pow(fabs(v->y - v->ry), 2));
	raydistance = fabs(cos(v->angle - angle) * raydistance);
	v->ds[i] = raydistance;
	screenwall[0] = real_distance * (C_S / raydistance);
	screenwall[1] = screenwall[0];
	screenwall[2] = v->mlx->height / 2 - screenwall[0] / 2;
	screenwall[3] = screenwall[2];
}

void	ft_set3(t_st *v, int x[7], double s[4], int dir[4])
{
	if ((v->map[(int)(v->ry) / C_S][(int)(v->rx) / C_S] == 'd')
		|| (dir [2] && v->map[(int)(v->ry - 1) / C_S]
			[(int)(v->rx) / C_S] == 'd')
		|| (dir [3] && v->map[(int)v->ry / C_S]
			[(int)(v->rx - 1) / C_S] == 'd'))
		v->tx_dr = v->tx_dr1;
	else
	{
		v->tx_dr = 0;
		return ;
	}
	x[2] = v->mlx->height;
	x[3] = v->mlx->width;
	x[4] = v->tx_dr->height;
	x[5] = v->tx_dr->width;
	x[6] = v->tx_dr->bytes_per_pixel;
	s[2] = s[2] * (s[2] >= 0) - 1;
	s[0] = x[2] * (s[0] > x[2]) + s[0] * !(s[0] > x[2]);
}

int	door_decision_maker(t_st *v, double hz[12], int dir[4])
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
	else
		return (1);
	if ((dir[2] && hz[10]) || (dir[3] && hz[11]))
		return (1);
	return (0);
}

int	chd(char c)
{
	if (c == 'd')
		return (1);
	return (0);
}

void	protect_sprites(t_st *v)
{
	ft_exit((v->a[0] == 0), 0);
	ft_exit((v->a[1] == 0), 0);
	ft_exit((v->a[2] == 0), 0);
	ft_exit((v->a[3] == 0), 0);
	ft_exit((v->a[4] == 0), 0);
	ft_exit((v->a[5] == 0), 0);
	ft_exit((v->a[6] == 0), 0);
	ft_exit((v->a[7] == 0), 0);
	ft_exit((v->b[0] == 0), 0);
	ft_exit((v->b[1] == 0), 0);
	ft_exit((v->b[2] == 0), 0);
	ft_exit((v->b[3] == 0), 0);
	ft_exit((v->b[4] == 0), 0);
	ft_exit((v->b[5] == 0), 0);
	ft_exit((v->b[6] == 0), 0);
	ft_exit((v->b[7] == 0), 0);
	ft_exit((v->c[0] == 0), 0);
	ft_exit((v->c[1] == 0), 0);
	ft_exit((v->c[2] == 0), 0);
	ft_exit((v->c[3] == 0), 0);
	ft_exit((v->c[4] == 0), 0);
	ft_exit((v->c[5] == 0), 0);
	ft_exit((v->c[6] == 0), 0);
	ft_exit((v->c[7] == 0), 0);
}
