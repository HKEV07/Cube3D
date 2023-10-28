/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:11:37 by fel-hazz          #+#    #+#             */
/*   Updated: 2023/10/07 18:36:43 by fel-hazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D_bonus.h"

int	ch_b(int c)
{
	if (c == '0' || c == 'E' || c == 'N'
		|| c == 'S' || c == 'W'
		|| c == 'd' || c == 'c' || c == 'o' || c == 'a' || c == 'b')
		return (1);
	return (0);
}

void	ft_load_map9(t_st *v, int var[2])
{
	ft_exit(((v->map[var[1]][var[0]] == ' ')
			&& ((var[0] && ch_b(v->map[var[1]][var[0] - 1]))
				|| (var[1] && ch_b(v->map[var[1] - 1][var[0]]))
				|| (var[1] + 1 < v->height
					&& ch_b(v->map[var[1] + 1][var[0]]))
				|| (v->map[var[1]][var[0] + 1]
					&& ch_b(v->map[var[1]][var[0] + 1])))), v);
	ft_exit(((v->map[var[1]][var[0]] == 'x')
			&& ((var[0] && ch_b(v->map[var[1]][var[0] - 1]))
				|| (var[1] && ch_b(v->map[var[1] - 1][var[0]]))
				|| (var[1] + 1 < v->height
					&& ch_b(v->map[var[1] + 1][var[0]]))
				|| (v->map[var[1]][var[0] + 1]
					&& ch_b(v->map[var[1]][var[0] + 1])))), v);
}

void	ft_load_map7(t_st *v)
{
	int	var[2];

	ft_memset(var, 0, 4 * 2);
	while (var[1] < v->height)
	{
		var[0] = 0;
		while (v->map[var[1]][var[0]] == ' ')
			var[0]++;
		ft_exit(ch_b(v->map[var[1]][var[0]]), v);
		var[0] = 0;
		while (v->map[var[1]][var[0]])
		{
			ft_load_map9(v, var);
			var[0]++;
		}
		ft_exit((var[0] && ch_b(v->map[var[1]][var[0] - 1])), v);
		var[1]++;
	}
	ft_load_map8(v, var);
}

void	ft_load_map8(t_st *v, int *var)
{
	var[1] = 0;
	var[0] = 0;
	while (v->map[var[1]][var[0]])
	{
		if (ch_b(v->map[var[1]][var[0]]))
			ft_exit(1, v);
		var[0]++;
	}
	var[1] = v->height - 1;
	var[0] = 0;
	while (v->map[var[1]][var[0]])
	{
		if (ch_b(v->map[var[1]][var[0]]))
			ft_exit(1, v);
		var[0]++;
	}
}

int	ft_check_name(char *argv)
{
	int	i;

	i = ft_strlen(argv) - 1;
	return (i >= 4 && argv[i] == 'b' && argv[i - 1] == 'u'
		&& argv[i - 2] == 'c' && argv[i - 3] == '.');
}
