/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:17:25 by fel-hazz          #+#    #+#             */
/*   Updated: 2023/10/07 18:36:43 by fel-hazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D_bonus.h"

void	dr1(t_st *v, int i, int j)
{
	t_tx	*tx;
	t_list	*t;

	tx = malloc(sizeof(t_tx));
	if (!tx)
		exit(1);
	tx->x = i * C_S + C_S / 2;
	tx->y = j * C_S + C_S / 2;
	tx->visible = 0;
	tx->type = 3;
	t = ft_lstnew(tx);
	if (!t)
		exit(1);
	ft_lstadd_back(&v->tx, t);
	v->map_img[j * M_C_S + M_C_S / 2][i * M_C_S + M_C_S / 2] = 0xFF0000FF;
}

void	dr2(t_st *v, int i, int j)
{
	t_tx	*tx;
	t_list	*t;

	tx = malloc(sizeof(t_tx));
	if (!tx)
		exit(1);
	tx->x = i * C_S + C_S / 2;
	tx->y = j * C_S + C_S / 2;
	tx->visible = 0;
	tx->type = 1;
	t = ft_lstnew(tx);
	if (!t)
		exit(1);
	ft_lstadd_back(&v->tx, t);
	v->map_img[j * M_C_S + M_C_S / 2][i * M_C_S + M_C_S / 2] = 0xFF0000FF;
}

void	dr3(t_st *v, int i, int j)
{
	t_tx	*tx;
	t_list	*t;

	tx = malloc(sizeof(t_tx));
	if (!tx)
		exit(1);
	tx->x = i * C_S + C_S / 2;
	tx->y = j * C_S + C_S / 2;
	tx->visible = 0;
	tx->type = 2;
	t = ft_lstnew(tx);
	if (!t)
		exit(1);
	ft_lstadd_back(&v->tx, t);
	v->map_img[j * M_C_S + M_C_S / 2][i * M_C_S + M_C_S / 2] = 0xFF0000FF;
}
