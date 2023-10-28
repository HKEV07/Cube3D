/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:49:24 by fel-hazz          #+#    #+#             */
/*   Updated: 2023/10/08 11:55:07 by fel-hazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D_bonus.h"

void	advanced_collision1(t_st *v, double p[3])
{
	if ((ft_check1(v, v->x - C_S, p[1] + C_S))
		&& (ft_check1(v, v->x, p[1] + C_S))
		&& (ft_check1(v, v->x + C_S, p[1] + C_S))
		&& (ft_check1(v, v->x - C_S, p[1]))
		&& (ft_check1(v, v->x, p[1]))
		&& (ft_check1(v, v->x + C_S, p[1]))
		&& (ft_check1(v, v->x - C_S, p[1] - C_S))
		&& (ft_check1(v, v->x, p[1] - C_S))
		&& (ft_check1(v, v->x + C_S, p[1] - C_S)))
		v->y = p[1];
	if ((ft_check1(v, p[0] + C_S, v->y + C_S))
		&& (ft_check1(v, p[0], v->y + C_S))
		&& (ft_check1(v, p[0] - C_S, v->y + C_S))
		&& (ft_check1(v, p[0] + C_S, v->y))
		&& (ft_check1(v, p[0], v->y))
		&& (ft_check1(v, p[0] - C_S, v->y))
		&& (ft_check1(v, p[0] + C_S, v->y - C_S))
		&& (ft_check1(v, p[0], v->y - C_S))
		&& (ft_check1(v, p[0] - C_S, v->y - C_S)))
		v->x = p[0];
}

void	advanced_collision(t_st *v, double p[3])
{
	if ((ft_check(v, v->x - C_S / 4, p[1] + C_S / 4))
		&& (ft_check(v, v->x, p[1] + C_S / 4))
		&& (ft_check(v, v->x + C_S / 4, p[1] + C_S / 4))
		&& (ft_check(v, v->x - C_S / 4, p[1]))
		&& (ft_check(v, v->x, p[1]))
		&& (ft_check(v, v->x + C_S / 4, p[1]))
		&& (ft_check(v, v->x - C_S / 4, p[1] - C_S / 4))
		&& (ft_check(v, v->x, p[1] - C_S / 4))
		&& (ft_check(v, v->x + C_S / 4, p[1] - C_S / 4)))
		v->y = p[1];
	if ((ft_check(v, p[0] + C_S / 4, v->y + C_S / 4))
		&& (ft_check(v, p[0], v->y + C_S / 4))
		&& (ft_check(v, p[0] - C_S / 4, v->y + C_S / 4))
		&& (ft_check(v, p[0] + C_S / 4, v->y))
		&& (ft_check(v, p[0], v->y))
		&& (ft_check(v, p[0] - C_S / 4, v->y))
		&& (ft_check(v, p[0] + C_S / 4, v->y - C_S / 4))
		&& (ft_check(v, p[0], v->y - C_S / 4))
		&& (ft_check(v, p[0] - C_S / 4, v->y - C_S / 4)))
		v->x = p[0];
}

int	advanced_collision3(t_st *v, char c)
{
	if ((ft_check3(v, v->x - C_S / 4, v->y + C_S / 4, c))
		|| (ft_check3(v, v->x, v->y + C_S / 4, c))
		|| (ft_check3(v, v->x + C_S / 4, v->y + C_S / 4, c))
		|| (ft_check3(v, v->x - C_S / 4, v->y, c))
		|| (ft_check3(v, v->x, v->y, c))
		|| (ft_check3(v, v->x + C_S / 4, v->y, c))
		|| (ft_check3(v, v->x - C_S / 4, v->y - C_S / 4, c))
		|| (ft_check3(v, v->x, v->y - C_S / 4, c))
		|| (ft_check3(v, v->x + C_S / 4, v->y - C_S / 4, c)))
		return (1);
	return (0);
}

int	ft_check1(t_st *v, double x, double y)
{
	if (!(x > 0 && y > 0 && x < v->width && y < v->height))
		return (0);
	if (v->map[(int)y / C_S][(int)x / C_S] == 'd')
	{
		if ((v->door == 0) || advanced_collision3(v, 'd'))
			return (0);
		if ((v->dx == 0 && v->dy == 0) || hs(x, y, v) < hs(v->dx, v->dy, v))
		{
			v->dx = x;
			v->dy = y;
		}
	}
	else if (v->map[(int)y / C_S][(int)x / C_S] == 'o')
	{
		if ((v->door == 0) || advanced_collision3(v, 'o'))
			return (1);
		if ((v->dx == 0 && v->dy == 0) || hs(x, y, v) < hs(v->dx, v->dy, v))
		{
			v->dx = x;
			v->dy = y;
		}
		return (0);
	}
	return (1);
}

double	hs(double x, double y, t_st *v)
{
	return (sqrt(pow(x - v->x, 2) + pow(y - v->y, 2)));
}
