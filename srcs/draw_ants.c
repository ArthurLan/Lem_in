/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 22:23:48 by alanter           #+#    #+#             */
/*   Updated: 2018/10/26 13:46:36 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		move_ants(t_info *info)
{
	t_room *tmp;

	tmp = info->room;
	while (tmp->end != 1)
		tmp = tmp->next;
	if (tmp->end == 1 && tmp->ant == info->ants)
		info->done = 1;
	while (tmp->start != 1)
	{
		if (tmp->previous_room->ant)
		{
			if (tmp->previous_room->start == 1)
			{
				tmp->ant = info->ants - tmp->previous_room->ant + 1;
				tmp->previous_room->ant -= 1;
			}
			else
			{
				tmp->ant = tmp->previous_room->ant;
				tmp->previous_room->ant = 0;
			}
		}
		tmp = tmp->previous_room;
	}
}

static void	print_name(t_mlx *mlx, t_room *tmp, int c)
{
	if (tmp->start == 1)
		mlx_string_put(mlx->mlx_ptr, mlx->win, tmp->x + 10,
				tmp->y + 35, 0x000000, "start");
	if (tmp->end == 1)
		mlx_string_put(mlx->mlx_ptr, mlx->win, tmp->x + 18,
				tmp->y + 35, 0x000000, "end");
	mlx_string_put(mlx->mlx_ptr, mlx->win, tmp->x, tmp->y - 2, c, tmp->name);
}

static void	print_ant(t_mlx *mlx, t_room *tmp)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win, tmp->x + 15,
			tmp->y + 18, 0x000000, "L");
	mlx_string_put(mlx->mlx_ptr, mlx->win, tmp->x + 15,
			tmp->y + 38, 0x000000, ">o{-{");
}

void		draw_ants(t_mlx *mlx, t_info *info)
{
	t_room	*tmp;
	char	*nb_ant;

	tmp = info->room;
	while (tmp)
	{
		tmp->white = 0;
		if (tmp->ant)
		{
			nb_ant = ft_itoa(tmp->ant);
			mlx_string_put(mlx->mlx_ptr, mlx->win, tmp->x + 29,
					tmp->y + 18, 0x000000, nb_ant);
			if (tmp->start != 1 && tmp->end != 1)
				print_ant(mlx, tmp);
			tmp->white = 1;
			print_name(mlx, tmp, 0xFFFFFF);
			ft_memdel((void**)&nb_ant);
		}
		if (tmp->white == 0)
			print_name(mlx, tmp, 0x000000);
		tmp = tmp->next;
	}
}
