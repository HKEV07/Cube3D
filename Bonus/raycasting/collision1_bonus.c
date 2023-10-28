/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:53:21 by fel-hazz          #+#    #+#             */
/*   Updated: 2023/10/07 18:36:43 by fel-hazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D_bonus.h"

int	ft_check(t_st *v, double x, double y)
{
	if (x > 0 && y > 0 && x < v->width && y < v->height
		&& ch_b(v->map[(int)y / C_S][(int)x / C_S]))
	{
		if (v->map[(int)y / C_S][(int)x / C_S] == 'd')
			return (0);
		return (1);
	}
	return (0);
}

int	ft_check3(t_st *v, double x, double y, char c)
{
	if (x > 0 && y > 0 && x < v->width && y < v->height)
	{
		if (v->map[(int)y / C_S][(int)x / C_S] == c)
			return (1);
	}
	return (0);
}
