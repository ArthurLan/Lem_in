/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:01:33 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/25 21:16:10 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "visual.h"

void	clean(t_info *info)
{
	t_room *tmp;

	while (info->room)
	{
		free(info->room->links);
		tmp = info->room->next;
		ft_strdel(&info->room->name);
		ft_memdel((void*)&info->room);
		info->room = tmp;
	}
}

void	start_again(t_info *info)
{
	t_room *tmp;

	tmp = info->room;
	info->nb_inst = 0;
	info->done = 0;
	while (tmp)
	{
		if (tmp->start)
			tmp->ant = info->ants;
		else
			tmp->ant = 0;
		tmp = tmp->next;
	}
}

int		main(void)
{
	t_info	*info;

	info = ft_memalloc(sizeof(t_info));
	if (!info)
		return (0);
	ft_search_ants(info);
	ft_search_rooms(info);
	ft_search_links(info);
	find_path(info, get_ending_room(info));
	start_again(info);
	window(info);
	clean(info);
	ft_strdel(&info->file);
	free(info);
	return (0);
}
