/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 02:24:39 by fel-hazz          #+#    #+#             */
/*   Updated: 2023/10/02 05:17:39 by fel-hazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

void	ft_load_map1(t_st *v, char *name)
{
	int		var[2];
	char	buff[1];

	var[0] = open(name, O_RDONLY);
	while (1)
	{
		var[1] = read(var[0], buff, 1);
		if (var[1] < 0 || var[1] == 0)
			break ;
		if (buff[0] == '\n')
			continue ;
		if (buff[0] == 'F')
			ft_load_color1(v, var, buff);
		else if (buff[0] == 'C')
			ft_load_color2(v, var, buff);
		else if (buff[0] == 'N' || buff[0] == 'S'
			|| buff[0] == 'W' || buff[0] == 'E')
			ft_load_texture(v, var, buff);
		else
			break ;
	}
	ft_exit((var[1] < 0 || v->tx_no == 0 || v->tx_so == 0 || v->tx_we == 0
			|| v->tx_ea == 0 || v->fl_clr == -1 || v->cl_clr == -1), v);
	ft_load_map2(v, var, buff);
}

void	ft_load_map2(t_st *v, int var[2], char buff[1])
{
	char	map[100000];
	int		i[6];

	i[4] = var[0];
	ft_memset(i, 0, 4 * 4);
	ft_memset(map, 0, 100000);
	while (1)
	{
		ft_exit(((var[1] <= 0) || (i[0] >= 99999)), v);
		if (buff[0] == '\n')
		{
			map[i[0]++] = 'x';
			break ;
		}
		ft_exit(((buff[0] != '1') && (buff[0] != ' ')), v);
		map[i[0]++] = buff[0];
		var[1] = read(var[0], buff, 1);
	}
	ft_load_map3(v, buff, map, i);
	ft_load_map5(v, map, i[2]);
	ft_player_position(v, 0, 0);
}

void	ft_load_map3(t_st *v, char buff[1], char *map, int i[5])
{
	while (1)
	{
		i[5] = read(i[4], buff, 1);
		ft_exit((i[0] >= 99999) || (i[5] < 0), v);
		if (i[5] == 0 && map[i[0] - 1] != 'x')
			map[i[0]++] = 'x';
		if (i[5] == 0)
			break ;
		if ((buff[0] == '\n') && (map[i[0] - 1] == '1'
				|| map[i[0] - 1] == ' ' || map[i[0] - 1] == '0'))
		{
			map[i[0]++] = 'x';
			continue ;
		}
		else if ((buff[0] == '\n') && (map[i[0] - 1] == 'x'))
			break ;
		ft_load_map4(v, buff, map, i);
	}
	while (i[5] != 0)
	{
		i[5] = read(i[4], buff, 1);
		ft_exit((i[5] < 0) || (buff[0] != '\n'), v);
	}
}

void	ft_load_map4(t_st *v, char buff[1], char *map, int i[6])
{
	if (buff[0] == 'N' || buff[0] == 'S'
		|| buff[0] == 'E' || buff[0] == 'W')
		map[i[0]++] = buff[0 * (i[2]++)];
	else if (buff[0] == '0' || buff[0] == '1' || buff[0] == ' ')
		map[i[0]++] = buff[0];
	else
		ft_exit(1, v);
}

void	ft_load_map5(t_st *v, char *s, int j)
{
	int	var[7];

	ft_exit((j != 1), v);
	ft_memset(var, 0, 4 * 7);
	while (s[var[0]])
		var[1] = var[1] + (s[var[0]++] == 'x');
	ft_load_map6(v, s, var);
	while (var[1] < v->height)
	{
		var[2] = var[0];
		while (s[var[0]] && s[var[0]] != 'x')
			var[0]++;
		v->map[var[1]] = malloc(var[4] + 1);
		ft_exit((!v->map[var[1]]), v);
		ft_strlcpy(v->map[var[1]], s + var[2], var[0] - var[2] + 2);
		ft_memset(v->map[var[1]] + var[0] - var[2] + 1,
			'x', var[4] - (var[0] - var[2]));
		v->map[var[1]][var[4]] = '\0';
		if (s[var[0]] == 'x')
			var[0]++;
		var[1]++;
	}
	ft_load_map7(v);
}
