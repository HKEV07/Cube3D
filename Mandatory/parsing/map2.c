/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 07:16:27 by fel-hazz          #+#    #+#             */
/*   Updated: 2023/10/02 05:17:43 by fel-hazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

void	ft_load_map6(t_st *v, char *s, int *var)
{
	v->height = var[1];
	v->map = malloc(sizeof(char *) * var[1]);
	ft_exit((!v->map), v);
	var[0] = 0;
	var[1] = 0;
	while (s[var[5]])
	{
		var[6] = 0;
		while (s[var[5]] && s[var[5]] != 'x')
		{
			var[5]++;
			var[6]++;
		}
		if (var[6] > var[4])
			var[4] = var[6];
		if (s[var[5]] == 'x')
			var[5]++;
	}
	v->width = var[4];
}

void	ft_player_position(t_st *v, int i, int j)
{
	while (j < v->height)
	{
		i = 0;
		while (v->map[j][i])
		{
			if (v->map[j][i] != '0' && ch_b(v->map[j][i]))
			{
				if (v->map[j][i] == 'N')
					v->angle = M_PI_2;
				else if (v->map[j][i] == 'S')
					v->angle = 3 * M_PI_2;
				else if (v->map[j][i] == 'E')
					v->angle = M_PI;
				else
					v->angle = 0;
				v->x = i * C_S + (double)C_S / 2;
				v->y = j * C_S + (double)C_S / 2;
				return ;
			}
			i++;
		}
		j++;
	}
}
