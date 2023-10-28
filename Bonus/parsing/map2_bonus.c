/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 07:16:27 by fel-hazz          #+#    #+#             */
/*   Updated: 2023/10/07 18:36:43 by fel-hazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D_bonus.h"

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

int	ft_player_position(t_st *v, int i, int j)
{
	while (j < v->height)
	{
		i = 0;
		while (v->map[j][i])
		{
			if (v->map[j][i] == 'N')
				return (v->x = i * C_S + C_S / 2.0
					, v->y = j * C_S + C_S / 2.0, v->angle = M_PI_2);
			else if (v->map[j][i] == 'S')
				return (v->x = i * C_S + C_S / 2.0
					, v->y = j * C_S + C_S / 2.0, v->angle = 3 * M_PI_2);
			else if (v->map[j][i] == 'E')
				return (v->x = i * C_S + C_S / 2.0
					, v->y = j * C_S + C_S / 2.0, v->angle = M_PI);
			else if (v->map[j][i] == 'W')
				return (v->x = i * C_S + C_S / 2.0
					, v->y = j * C_S + C_S / 2.0, v->angle = 0);
			i++;
		}
		j++;
	}
	return (1);
}
