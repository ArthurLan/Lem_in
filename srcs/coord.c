/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 08:58:39 by alanter           #+#    #+#             */
/*   Updated: 2018/10/25 23:01:31 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	scale(t_info *info)
{
	t_room *tmp;

	tmp = info->room;
	info->xmin = 5000;
	info->ymin = 5000;
	info->xmax = 0;
	info->ymax = 0;
	while (tmp)
	{
		if (tmp->x < info->xmin)
			info->xmin = tmp->x;
		else if (tmp->x > info->xmax)
			info->xmax = tmp->x;
		if (tmp->y < info->ymin)
			info->ymin = tmp->y;
		else if (tmp->y > info->ymax)
			info->ymax = tmp->y;
		tmp = tmp->next;
	}
	if (info->xmax > 500 || info->ymax > 30
			|| (info->xmax == 0 && info->ymax == 0))
	{
		ft_putstr("Error map for visual\n");
		exit(0);
	}
}

void		calc_coord(t_info *info)
{
	t_room *tmp;

	scale(info);
	info->xmax = (WIN_W - WIN_W / 10) / (info->xmax - info->xmin);
	info->ymax = (WIN_H - WIN_H / 4) / (info->ymax - info->ymin);
	tmp = info->room;
	while (tmp)
	{
		tmp->visited = 0;
		tmp->x = 100 + (tmp->x - info->xmin) * info->xmax * 5 / 8;
		tmp->y = 130 + ((tmp->y - info->ymin) * info->ymax);
		tmp = tmp->next;
	}
}
