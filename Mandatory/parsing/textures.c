/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 02:23:21 by fel-hazz          #+#    #+#             */
/*   Updated: 2023/10/02 05:17:50 by fel-hazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

void	ft_load_texture(t_st *v, int var[2], char buff[1])
{
	if (buff[0] == 'N')
		ft_load_texture1(v, var, buff);
	else if (buff[0] == 'S')
		ft_load_texture2(v, var, buff);
	else if (buff[0] == 'W')
		ft_load_texture3(v, var, buff);
	else if (buff[0] == 'E')
		ft_load_texture4(v, var, buff);
}

void	ft_load_texture1(t_st *v, int var[2], char buff[1])
{
	char	s[256];
	int		i;

	i = 0;
	ft_memset(s, 0, 256);
	var[1] = read(var[0], buff, 1);
	ft_exit((v->tx_no != 0 || buff[0] != 'O'), v);
	var[1] = read(var[0], buff, 1);
	ft_exit((var[1] < 0), v);
	ft_exit((var[0] == 0 || buff[0] == '\n'), v);
	while (buff[0] == ' ' && ((i == 0 && i++) || 1))
		var[1] = read(var[0], buff, 1);
	ft_exit((buff[0] != '.') || (i-- != 1), v);
	var[1] = read(var[0], buff, 1);
	ft_exit((buff[0] != '/'), v);
	var[1] = read(var[0], s + i, 1);
	while (var[1] > 0 && i < 255 && s[i++] != '\n')
		var[1] = read(var[0], s + i, 1);
	if (i > 0 && s[i -1] == '\n')
		s[i - 1] = '\0';
	ft_exit((i >= 255), v);
	v->tx_no = mlx_load_png(s);
	ft_exit((!v->tx_no), v);
}

void	ft_load_texture2(t_st *v, int var[2], char buff[1])
{
	char	s[256];
	int		i;

	i = 0;
	ft_memset(s, 0, 256);
	var[1] = read(var[0], buff, 1);
	ft_exit((v->tx_so != 0 || buff[0] != 'O'), v);
	var[1] = read(var[0], buff, 1);
	ft_exit((var[1] < 0), v);
	ft_exit((var[0] == 0 || buff[0] == '\n'), v);
	while (buff[0] == ' ' && ((i == 0 && i++) || 1))
		var[1] = read(var[0], buff, 1);
	ft_exit((buff[0] != '.') || (i-- != 1), v);
	var[1] = read(var[0], buff, 1);
	ft_exit((buff[0] != '/'), v);
	var[1] = read(var[0], s + i, 1);
	while (var[1] > 0 && i < 255 && s[i++] != '\n')
		var[1] = read(var[0], s + i, 1);
	if (i > 0 && s[i -1] == '\n')
		s[i - 1] = '\0';
	ft_exit((i >= 255), v);
	v->tx_so = mlx_load_png(s);
	ft_exit((!v->tx_so), v);
}

void	ft_load_texture3(t_st *v, int var[2], char buff[1])
{
	char	s[256];
	int		i;

	i = 0;
	ft_memset(s, 0, 256);
	var[1] = read(var[0], buff, 1);
	ft_exit((v->tx_we != 0 || buff[0] != 'E'), v);
	var[1] = read(var[0], buff, 1);
	ft_exit((var[1] < 0), v);
	ft_exit((var[0] == 0 || buff[0] == '\n'), v);
	while (buff[0] == ' ' && ((i == 0 && i++) || 1))
		var[1] = read(var[0], buff, 1);
	ft_exit((buff[0] != '.') || (i-- != 1), v);
	var[1] = read(var[0], buff, 1);
	ft_exit((buff[0] != '/'), v);
	var[1] = read(var[0], s + i, 1);
	while (var[1] > 0 && i < 255 && s[i++] != '\n')
		var[1] = read(var[0], s + i, 1);
	if (i > 0 && s[i -1] == '\n')
		s[i - 1] = '\0';
	ft_exit((i >= 255), v);
	v->tx_we = mlx_load_png(s);
	ft_exit((!v->tx_we), v);
}

void	ft_load_texture4(t_st *v, int var[2], char buff[1])
{
	char	s[256];
	int		i;

	i = 0;
	ft_memset(s, 0, 256);
	var[1] = read(var[0], buff, 1);
	ft_exit((v->tx_ea != 0 || buff[0] != 'A'), v);
	var[1] = read(var[0], buff, 1);
	ft_exit((var[1] < 0), v);
	ft_exit((var[0] == 0 || buff[0] == '\n'), v);
	while (buff[0] == ' ' && ((i == 0 && i++) || 1))
		var[1] = read(var[0], buff, 1);
	ft_exit((buff[0] != '.') || (i-- != 1), v);
	var[1] = read(var[0], buff, 1);
	ft_exit((buff[0] != '/'), v);
	var[1] = read(var[0], s + i, 1);
	while (var[1] > 0 && i < 255 && s[i++] != '\n')
		var[1] = read(var[0], s + i, 1);
	if (i > 0 && s[i -1] == '\n')
		s[i - 1] = '\0';
	ft_exit((i >= 255), v);
	v->tx_ea = mlx_load_png(s);
	ft_exit((!v->tx_ea), v);
}
